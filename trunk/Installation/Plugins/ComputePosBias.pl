#! /usr/bin/perl -w 
use Getopt::Long;
use File::Basename;
use strict;

# This script takes as input a list of seeds in a .seeds format
# To each seed it computes the positional bias in two ways:
# 1. It computes the madian of the distribution, drops the $outlr percentage which are the furthest from it, and then computes mean
# and variance and reports them
# 2. Computes the empirical distribution in the positive and negative set, and the KS pvalue between them
# 
# The script also outputs a .png of the distributions, estimated using parzen windows
my $paramFile = "Params/ComputePosBias.params";
my $binParamFile = "Params/Bin.params";
open F, "<$paramFile" or die "can not open $paramFile\n";
open BF, "<$binParamFile" or die "can not open $binParamFile\n";
my $usage = "$0 looks for $paramFile and $binParamFile\n";

my $k_dataDir = "dataDir";
my $k_seedF = "seedsFile";
my $k_outStub = "out";
my $prlcom = undef;
my $awkcom = undef;
my $gnpltcom = undef;
my $k_outlr = "outlr";
my $k_minNegCount = "minNegCount";
my $k_minPosCount = "minPosCount";
my $k_baseGnuF = "baseGnuF";
my $k_ksProg = "ksProg";
my $k_histProg = "histProg";
my $k_relPosition = "relPosition";
my $k_seqF = "seqF";
my @ParamsKeys = ( $k_dataDir, $k_seedF, $k_outStub, $k_outlr, $k_minNegCount, $k_minPosCount, $k_baseGnuF, $k_ksProg, $k_histProg, $k_relPosition, $k_seqF );
my %Params;

my $prlkey = "-prlcom";
my $awkkey = "-awkcom";
my $gnpltkey = "-gnpltcom";


my %binHash;
while (<BF>) {
  chop $_;
  my $bkey = $_;
  my $bdata = <BF>;
  chomp($bdata);
  $binHash{$bkey}= $bdata;
  #print "bkey $bkey bdata $bdata\n";
}		

die "Must have awkprog,prlprog,gnuplot defined in $binParamFile !!\n" unless (exists ($binHash{$prlkey}) && exists ($binHash{$awkkey}) && exists ($binHash{$gnpltkey}));
$prlcom = $binHash{$prlkey};
$awkcom = $binHash{$awkkey};
$gnpltcom = $binHash{$gnpltkey};

while (<F>) {
  chop $_;
  push (@ARGV , $_);
}		

#print "@ARGV\n";


GetOptions(
	  "dataDir:s" => \$Params{$k_dataDir},
	  "seedsFile:s" => \$Params{$k_seedF},
	  "out:s" => \$Params{$k_outStub},
	  "awkcom:s" => \$Params{$awkcom},
	  "prlcom:s" => \$Params{$prlcom},
	  "outlr:i" => \$Params{$k_outlr},
	  "minNegCount:i" => \$Params{$k_minNegCount},
	  "minPosCount:i" => \$Params{$k_minPosCount},
	  "baseGnuF:s" => \$Params{$k_baseGnuF},
	  "ksProg:s" => \$Params{$k_ksProg},
	  "histProg:s" => \$Params{$k_histProg},
	  "relPosition:s" => \$Params{$k_relPosition},
	  "seqF:s" => \$Params{$k_seqF},
	  );

#print "dataDir $dataDir seedsFile $seedF hgprog $hgprog  redprog $redprog out $outStub awkcom $awkcom prlcom $prlcom\n";

foreach (@ParamsKeys) {
#  print "$_\n";
  die "Param File must speficiy $_\n" unless (exists($Params{$_}));
}

my $outFile = $Params{$k_outStub}.".pb";
open SF, "<$Params{$k_seedF}" or die "fail to open $Params{$k_seedF} $!\n";
my $outDir = dirname $Params{$k_outStub};
if (! -e $outDir) {
  mkdir $outDir or die "cannot create output directory $outDir $!\n";
}
open OF, ">$outFile" or die "fail to open output file $!\n";

# Get the sequence length data, if relevant:
my %seqLen;
if ($Params{$k_relPosition} eq "S_START" || $Params{$k_relPosition} eq "MINDIST" ) {
  die "if using position bias from start of sequence or from the nearer end  the sequence file must be specificed!\n" unless (defined($Params{$k_seqF}));
  open SEQF, "<$Params{$k_seqF}" or die "cannot open sequence file $Params{$k_seqF} $!\n";
  while (<SEQF>) {
    if (m/\>/) {
      chop $_;
      my $name = substr($_,1);
      my $seq = <SEQF>;
      chomp($seq);
      $seqLen{$name}= length($seq);
    }
  }
}


# read the seed data in:
my @seedData;
my @motifFiles;
while (<SF>) {
  push @seedData, $_;
}
close SF;

# print the file header:
print OF "FileName\torigMedian\torigMean\torigStd\ttrimMean\ttrimStd\tKSpval\n";
my $M = undef;
for (my $i = 0 ;$i<= $#seedData;$i++) {
  # Find out the total number of targets (this is the "N=" in the .seeds file)
  if ($i == 0 ) {
    ($seedData[$i] =~ m/.*\sN=(\d+),\sM=.*$/) or  die "cannot find the number of targets\n";
    $M = $1;
  }
  my @fields = split /\s/, $seedData[$i];
  # find out the .motif file of current seed:
  my $motifF1 = undef;
  for (@fields) {
    if (m/\.motifs$/) {
      $motifF1 = $Params{$k_dataDir}."/".$_ ;
      $motifFiles[$i] =  $motifF1;
      last;
    }
  }
  die "did not find a motif file name in $_\n" unless defined($motifF1);
  my @vals = sort {$a <=> $b } (ReadDistances($motifF1));
  my $cmean = avg(@vals);
  my $median = ( $vals[int($#vals/2)]+ $vals[int(($#vals+1)/2)])/2;
  #print  OF "Median:".$median." Mean: ".$cmean."Std: ".std(@vals)."\n";
  # compute trimmed statistics:
  my %Dist;
  foreach (@vals) {
    $Dist{$_} = sqrt( ($median - $_)*($median - $_));
  }
  my @valsByDist = sort {$Dist{$a} <=> $Dist{$b} } keys %Dist; # ascending order;
  $#valsByDist = max( int(($#valsByDist+1)*(100 - $Params{$k_outlr})/100)-1,0);#truncate
  #print OF "TMean: ". avg(@valsByDist). " TStd: ". std(@valsByDist). "\n";
  # collecte the data from the .neg.motifs file:
  my $negMotifF1 = $motifF1;
  $negMotifF1 =~ s/\.motifs$/.neg.motifs/ ;
  my @negvals = sort { $a <=> $b} ReadDistances($negMotifF1);
  # compute positional bias (KS pval) and plot distributions:
  my $KS = "NaN";
  if ($#negvals >= $Params{$k_minNegCount} && $#vals >= $Params{$k_minPosCount} ) {
    # print .locations which gives the empirical distribution of distances:
    my $locationsF = $Params{$k_outStub}.".".$i.".locations";
    open LF, ">$locationsF" or die "cannot write to $locationsF $!\n";
    my $lim = max($#vals,$#negvals);
    my $minCount = min($#vals,$#negvals);
    for (my $j = 0; $j <= $lim ; $j++) {
#      my $do = 0;
#      $do = 1 if ($j == $lim);
#      $do = 1 if ($j < $lim && 
      if ( $j <= $#vals && $j <= $#negvals) {
	print LF $vals[$j]."\t".$j/($#vals+1)."\t".$negvals[$j]."\t".$j/($#negvals+1)."\n";
      }
      else {
	if ( $j <= $#vals) {	
	  print LF $vals[$j]."\t".$j/($#vals+1)."\t\t\n";
	}
	else {
	  print LF "\t\t".$negvals[$j]."\t".$j/($#negvals+1)."\n";
	}
      }
    }
    close(LF);
    # KS is computed only if both pos and negative have actual counts:
    # (it can be the case that a motif only appears in the positive set for example)
    if ($#negvals > 0 && $#vals >= 0 ) {
      #print "$prlcom $Params{$k_ksProg}  $locationsF\n";
      my $tmp = `$prlcom $Params{$k_ksProg}  $locationsF`;
      print "$tmp\n";
      @fields = split /\s+/, $tmp;
      $KS = $fields[1];
      #print "KS $KS\n";
    }
    print OF "$motifF1\t$median\t$cmean\t".std(@vals)."\t".avg(@valsByDist)."\t".std(@valsByDist)."\t".$KS."\n";
    
    # create the matching .hist files and then plot positional bias:
    my $tmp = `$awkcom $Params{$k_histProg} 1 $locationsF`;
#    my $maxHistVal;
    my $posBiasHistFpos = $Params{$k_outStub}.".".$i.".pos.posBias.hist";
    open HF, ">$posBiasHistFpos" or die "cannot write to $posBiasHistFpos $!\n";
    print HF $tmp;
    close(HF);
    $tmp = `$awkcom $Params{$k_histProg} 3 $locationsF`;
    my $posBiasHistFneg = $Params{$k_outStub}.".".$i.".neg.posBias.hist";
    open HF, ">$posBiasHistFneg" or die "cannot write to $posBiasHistFneg $!\n";
    print HF $tmp;
    close(HF);
    # read the base gnu file:
    open GF, "<$Params{$k_baseGnuF}" or die "cannot read $Params{$k_baseGnuF} $!\n";
    $tmp = "";
    $tmp = $tmp . $_ while <GF>;
    close(GF);
    my $posBiasPlt = $Params{$k_outStub}.".$i.posBias";
    # add the relevant settings to the file:
    $tmp = $tmp."set term postscript color solid\n";
    $tmp = $tmp."set output \'$posBiasPlt.eps\'\n";
    $tmp = $tmp."set key right bottom\n";
    $tmp = $tmp."set data style lines\n";
#    $tmp = $tmp."set yrange [0:$maxHistVal]\n";
    $tmp = $tmp."set xlabel \'Position\'\n";
    $tmp = $tmp."set ylabel \'Probability Disribution\'\n";
    $tmp = $tmp."set title \'Motifs estimated probability disribution in negative and positive groups\'\n";
    $tmp = $tmp."set style line 1 lt 1 ps 2 lw 10\n";
    $tmp = $tmp."set style line 2 lt 2 ps 2 lw 10\n";
    if ($#negvals > 0 ) {
      $tmp = $tmp."plot \"".$posBiasHistFpos."\" using 1:2 title \"Positive Set\" lt 1 lw 10 ,\"".$posBiasHistFneg."\" using 1:2 title \"Negative Set\" lt 2 lw 10\n";
    }
    # plot only the histogram for positive set:
    else {
      $tmp = $tmp."plot \"".$posBiasHistFpos."\" using 1:2 title \"Positive Set (No Negatives)\" lt 1 lw 10\n";
    }
    my $gnuF = $Params{$k_outStub}.".$i.posBias.gnu";
    open GF, ">$gnuF" or die "cannot write $gnuF $!\n";
    print GF $tmp;
    close(GF);
    system "$gnpltcom -persist $gnuF";
    system "convert -rotate 90 $posBiasPlt.eps $posBiasPlt.png";
    system "convert -resize 180X100 $posBiasPlt.png $posBiasPlt.thmb.png";
  }
  
  print "\nPress enter to continue...";
	my $miew = <STDIN>;
}




################################################
#### SUBRUTINES
################################################
sub max {
  my($max_so_far) = shift @_;
  foreach (@_){
    $max_so_far = $_ if ($_ > $max_so_far);
  }
  return $max_so_far;
}

sub min {
  my($min_so_far) = shift @_;
  foreach (@_){
    $min_so_far = $_ if ($_ < $min_so_far);
  }
  return $min_so_far;
}

sub sum {
  my($my_sum) = shift @_;
  foreach (@_){
    $my_sum += $_;
  }
  return $my_sum;
}

sub avg {
  return undef if ($#_ == -1);
  return sum(@_)/(scalar(@_));
}

sub var {
  return undef if ($#_ == -1);
  my $E = avg(@_);
  my @sqr = @_;
  for (my $i = 0; $i <= $#sqr; $i++) {
    $sqr[$i] *=  $sqr[$i];
  }
  return (avg(@sqr) - $E*$E);
}

sub std {
  return undef if ($#_ == -1);
  return sqrt(var(@_));
}


sub ReadDistances {
  my $motifF1 = $_[0];
  open MF, "<$motifF1" or die "cannot open $motifF1 $!\n";
  my $count = 0;
  #extract data from the matching .motif file:
  my @vals;
  while (<MF>) {
    $count++;
    next if ($count == 1);
    my @fields = split(/\t/, $_);
    $fields[1]  =~ s/\s//g ;
    my $val = $fields[5];
    if ( $Params{$k_relPosition} eq "S_START") {
      my $gene = $fields[2];
      die "unknown sequence name $gene at line $count of file $motifF1\n" if (! exists($seqLen{$gene}));
      $val = $fields[4] + $seqLen{$gene};
    }
    if ( $Params{$k_relPosition} eq "MINDIST") {
      my $gene = $fields[2];
      die "unknown sequence name $gene at line $count of file $motifF1\n" if (! exists($seqLen{$gene}));
      my $tmp = $fields[4] + $seqLen{$gene};
      $val = min(sqrt($tmp*$tmp), sqrt($val*$val));
    }
    push @vals,  $val;
  }
  close(MF);
  return @vals;
}
