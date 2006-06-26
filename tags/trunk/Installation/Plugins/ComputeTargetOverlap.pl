#! /usr/bin/perl -w 
use Getopt::Long;
use File::Basename;
use strict;

# this script takes as input a file in a .seeds format and compute the target overlap of any two seeds in it.
# NOTE: assume all the seeds came from the same set of targets i.e they share the same amount of total genes
# in the positive set. This is used as "M" in the hg pval computation.
my $paramFile = "Params/ComputeTargetOverlap.params";
my $binParamFile = "Params/Bin.params";
open F, "<$paramFile" or die "can not open $paramFile\n";
open BF, "<$binParamFile" or die "can not open $binParamFile\n";
my $usage = "$0 looks for $paramFile which should contain:\n-dataDir dataDirName\n-seedsFile seedFileName\n-hgprog hgprog\n-redprog redundancyProg\n-out outStub\nOutput is written to outStub.to\nIt also looks for $binParamFile which should contain\n-awkcom awkcommand\n-prlcom perlcommand\n";

my $dataDir = undef;
my $seedF = undef;
my $hgprog = undef;
my $redprog = undef;
my $outStub = undef;
my $prlcom = undef;
my $awkcom = undef;
my $prlkey = "-prlcom";
my $awkkey = "-awkcom";


my %binHash;
while (<BF>) {
  chop $_;
  my $bkey = $_;
  my $bdata = <BF>;
  chomp($bdata);
  $binHash{$bkey}= $bdata;
  #print "bkey $bkey bdata $bdata\n";
}		

die "Must have awkprog and prlprog defined in $binParamFile !!\n" unless (exists ($binHash{$prlkey}) && exists ($binHash{$awkkey}));
$prlcom = $binHash{$prlkey};
$awkcom = $binHash{$awkkey};

while (<F>) {
  chop $_;
  push (@ARGV , $_);
}		

#print "@ARGV\n";

GetOptions(
	  "dataDir:s" => \$dataDir,
	  "seedsFile:s" => \$seedF,
	  "hgprog:s" => \$hgprog,
	  "redprog:s" => \$redprog,
	  "out:s" => \$outStub,
	  "awkcom:s" => \$awkcom,
	  "prlcom:s" => \$prlcom,
	  );

#print "dataDir $dataDir seedsFile $seedF hgprog $hgprog  redprog $redprog out $outStub awkcom $awkcom prlcom $prlcom\n";

unless ( defined($dataDir) && defined($seedF) && defined($hgprog) && defined($redprog) && defined($outStub) && defined($awkcom) && defined($prlcom)) {
    die $usage;
}

#my $hgprog = hgPval.pl;
#my $redprog = ComputeRedundancy.awk;
my %genePerMotif;

my $outFile = $outStub.".to";
open SF, "<$seedF" or die "fail to open $seedF $!\n";
my $outDir = dirname $outStub;
if (! -e $outDir) {
  mkdir $outDir or die "cannot create output directory $outDir $!\n";
}
open OF, ">$outFile" or die "fail to open output file $!\n";

# read the seed data in:
my @seedData;
my @motifFiles;

while (<SF>) {
  push @seedData, $_;
}
close SF;
my $M = undef;
for (my $i = 0 ;$i<= $#seedData;$i++) {
  # Find out the total number of targets (N= in the .seeds file)
  if ($i == 0 ) {
    ($seedData[$i] =~ m/.*\sN=(\d+),\sM=.*$/) or  die "cannot find the number of targets\n";
    $M = $1;
  }
  my @fields = split /\s/, $seedData[$i];
  # find out the .motif file of current seed:
  my $motifF1 = undef;
  for (@fields) {
    if (m/\.motifs$/) {
      #$motifFiles[$i] =  $_;
      $motifF1 = $dataDir."/".$_ ;
      $motifFiles[$i] =  $motifF1;
      last;
    }
  }
  die "did not find a motif file name in $_\n" unless defined($motifF1);
  open MF, "<$motifF1" or die "cannot open $motifF1 $!\n";
  my $count = 0;
  #extract data from the matching .motif file:
  while (<MF>) {
    $count++;
    next if ($count == 1);
    my @fields = split(/\t/, $_);
     $fields[1]  =~ s/\s//g ;
     my $gene = $fields[1];
    #print "gene $gene\n";
    my $ckey = "Motif".$i.$gene;
    #$geneCountPerMotif{$i}++ if (! (exists $genePerMotif{$i}{$key}));
    $genePerMotif{$i}{$gene}++;
  }
  close(MF);
}
#Now, copute the targets overlap for all seeds listed:
for (my $i = 0 ;$i<= $#seedData;$i++) {
  my $N = keys %{$genePerMotif{$i}};
  my @fields = split(/\//, $motifFiles[$i]);
  my $m1 = $fields[$#fields];
  for (my $j = $i+1 ;$j<= $#seedData;$j++) {
    my $K = keys %{$genePerMotif{$j}};
    my $X = 0;
    foreach my $gene (keys %{$genePerMotif{$j}}) {
      $X++ if exists($genePerMotif{$i}{$gene});
    }
    #print "i= $i j= $j X= $X  N=$N  K=$K M=$M\n";
    my $res = `$prlcom $hgprog $X $K $N $M`;
    @fields = split(/\s/, $res);
    my $pval = $fields[$#fields];
    #print "$pval\n";
    #print "$awkcom $redprog $motifFiles[$i] $motifFiles[$j]\n";
    my $Redundancy = `$awkcom $redprog $motifFiles[$i] $motifFiles[$j]`;
    @fields = split(/\//, $motifFiles[$j]);
    my $m2 = $fields[$#fields];
    print OF "$m1\t$m2\t$X\t$K\t$N\t$M\t$pval\t$Redundancy";
  }
}
