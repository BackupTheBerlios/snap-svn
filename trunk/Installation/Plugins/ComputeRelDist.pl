#! /usr/bin/perl -w 
use Getopt::Long;
use File::Basename;
use strict;

# This script takes as input a list of seeds in a .seeds format
# It computes the statistics of co occurences of each pair, specifically:
# For any sequence that contains occurences of both seeds it takes the minimal distance between any occurence pair possible
# Also, the distance is always computed as motif1 - motif2 , to the relative order is preserved.
# The distance computed is based on the values as they appear inthe .motifs files 
# 1. It computes the madian of the distribution, drops the $outlr percentage which are the furthest from it, and then computes mean
# and variance and reports them too
# 2. Computes the empirical distribution in the positive and negative set, and the KS pvalue between them
# 3. prints for each pair .distlist which lists the distances as they were found 


## READING INPUT:
##################
my $paramFile = "params/ComputeRelDist.params";
my $binParamFile = "params/Bin.params";
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
my $k_minCount = "minCount";
my $k_baseGnuF = "baseGnuF";
my $k_histProg = "histProg";
my $k_seqlogprg = "seqlogprg";
my $k_minVal = "minVal";
my $k_maxVal = "maxVal";

# mandatory keys:
my @MandatoryKeys = ( $k_dataDir, $k_seedF, $k_outStub, $k_outlr, $k_minCount, $k_baseGnuF, $k_histProg, $k_seqlogprg);
my %Params;
$Params{$k_minVal} = undef;
$Params{$k_maxVal} = undef;

my $prlkey = "-prlcom";
my $awkkey = "-awkcom";
my $gnpltkey = "-gnpltcom";

# READ BIN PARAMS:
my %binHash;
while (<BF>) {
  chop $_;
  my $bkey = $_;
  my $bdata = <BF>;
  chomp($bdata);
  $binHash{$bkey}= $bdata;
  #print "bkey $bkey bdata $bdata\n";
}		
die "Must have awkprog,prlprog,gnuplot defined in $binParamFile !!\n" 
  unless (exists ($binHash{$prlkey}) && exists ($binHash{$awkkey}) && exists ($binHash{$gnpltkey}));
$prlcom = $binHash{$prlkey};
$awkcom = $binHash{$awkkey};
$gnpltcom = $binHash{$gnpltkey};
# READ PARAMS:
while (<F>) {
  chop $_;
  next if (m/^#/); # skipt comment lines
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
	   "minCount:i" => \$Params{$k_minCount},
	   "baseGnuF:s" => \$Params{$k_baseGnuF},
	   "histProg:s" => \$Params{$k_histProg},
	   "seqlogprg:s" => \$Params{$k_seqlogprg},
	   "minVal:i" => \$Params{$k_minVal},
	   "maxVal:i" => \$Params{$k_maxVal},
	  );
#print "dataDir $dataDir seedsFile $seedF hgprog $hgprog  redprog $redprog out $outStub awkcom $awkcom prlcom $prlcom\n";
foreach (@MandatoryKeys) {
#  print "$_\n";
  die "Param File must speficiy $_\n" unless (defined($Params{$_}));
}
# INITALIZE:
###############
my @outFilesTypes; # used to report the output for summary.xml
my @outFilesList; # used to report the output for summary.xml 
$" = "\t";# set the arrays to print with \t as the seperator
open SF, "<$Params{$k_seedF}" or die "fail to open $Params{$k_seedF} $!\n";
my $outDir = dirname $Params{$k_outStub};
if (! -e $outDir) {
  mkdir $outDir or die "cannot use output directory $outDir $!\n";
}
my $rdFile = $Params{$k_outStub}.".rd";
open OF, ">$rdFile" or die "fail to open output file $rdFile $!\n";
push @outFilesTypes, "Relative Distance tab summary";
push @outFilesList, "$rdFile";

my $TRIM_RATIO = (100-$Params{$k_outlr})/100;# how much of the positions is left (the other are trimmed)
my %Data;
# get the name of the .motifs files from the .seeds file:
my @motifFiles;
while (<SF>) {
  chomp;
  my @fields = split;
  # find out the .motif file of current seed:
  my $motifF1 = undef;
  for (@fields) {
    if (m/\.motifs$/) {
      $motifF1 = $_; # $Params{$k_dataDir}."/".$_ ;
      push @motifFiles , $motifF1;
      my $m1 = $Params{$k_dataDir}."/".$motifF1;
      $Data{$motifF1}{"motifF"} = $m1;
      #print "$motifF1\n";
      last;
    }
  }
  die "did not find a motif file name in $_\n" unless defined($motifF1);
}
close SF;
die "This seeds file has less then 2 seeds in it, aborting....\n" unless ($#motifFiles > 0);

### COMPUTE STAT AND OUTPUT .DISTLIST FILES FOR RELATIVE DISTANCE OF EACH SEEDS PAIR:
################################################################################
print OF "#File1\tFile2\tMedian\tMean\tstd\ttrimMean\ttrimMean\ttrimStd\n";
print "Computing Statisitcs....\n";
for (my $i = 0 ;$i< $#motifFiles;$i++) {
  my $motifI = $motifFiles[$i];
  my $m1 = $Data{$motifI}{"motifF"};
  for (my $j = $i+1 ;$j<= $#motifFiles;$j++) {
    my $motifJ = $motifFiles[$j];
    my $m2 = $Data{$motifJ}{"motifF"};
    my $Best = Compute2SeedsDistanceList($m1, $m2);
    ##foreach my $event (@{$Best}) {
    ##  print "@{$event}\n";
    ##}
    # handle the case of an empty list:
    if (! @{$Best}) {
      print OF "$motifFiles[$i]\t$motifFiles[$j]\t###Error-NoTargetOverlapp####\n";
      $Data{$motifI}{$motifJ}{"distlist"} = undef;
      next;
    }
    my @Best = sort { $a->[0] <=> $b->[0] } (@{$Best});
    my $trimNum = int( $TRIM_RATIO * @Best);
    #print "trimNum $trimNum\n";
    my @Dists;
    my $distListFile = $outDir."/$motifFiles[$i].And.$motifFiles[$j].distlist";
    open DLIST, ">$distListFile" or die "cannot write $distListFile $!\n";
    $Data{$motifI}{$motifJ}{"distlist"} = basename $distListFile;
    $Data{$motifI}{$motifJ}{"distlistF"} = $distListFile;
    print DLIST "#Dist\tSeq\tSeed1Pos\tSeed2Pos\n";
    foreach my $event (@Best) {
      print DLIST "@{$event}\n";
      #print "$event->[0]\n";
      push @Dists, $event->[0];
    }
    close(DLIST);
    #@Dists = sort {$a <=> $b } (@Dists); Dists is already sorted !!
    my $origMean = avg(@Dists);
    my $origStd = std(@Dists);
    my $origMedian = med(@Dists);
    my $trimMean = $origMean;
    my $trimStd = $origStd;
    #print "origMean $origMean origStd $origStd origMedian $origMedian\n";
    foreach my $event (@Best) {
      $event->[4] = abs($event->[0] - $origMedian);
      #print "@{$event}\n";
      #print "$event->[4]\n";
    }
    if ($trimNum > 0) {
      my @trimBest = @Best;
      @trimBest = sort { $a->[4] <=> $b->[4] } (@trimBest);
      $#trimBest = $trimNum-1;
      @Dists = ();
      #print "we are left with:\n";
      foreach my $event (@trimBest) {
	#print "@{$event}\n";
	#print "$event->[0]\n";
	push @Dists, $event->[0];
      }
      $trimMean = avg(@Dists);
      $trimStd = std(@Dists);
    }
    #print "trimMean $trimMean trimStd $trimStd trimMedian $trimMedian\n";
    my $statString = sprintf("%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",$motifFiles[$i],$motifFiles[$j],$origMedian,$origMean,$origStd,$trimMean,$trimStd);
    print OF $statString;
    $statString = sprintf("#: %d avg: %.2f std: %.2f med: %.2f tavg: %.2f tstd: %.2f ",scalar(@Dists),$origMedian,$origMean,$origStd,$trimMean,$trimStd);
    $Data{$motifI}{$motifJ}{"stats"} = $statString;

  }
}
close (OF);
#### ????? FINISH !!!!! add reporting of error etc. into the data strucutre, print the .rd .html and .xml files.....
# OUTPUT .HIST AND PLOT HIST FOR EACH .DISTLIST FILE :
######################################################
print "Building relativ distance histograms....\n";
my $minValFlag = ( defined $Params{$k_minVal} ) ? "-min \"$Params{$k_minVal}\"" : "" ;
my $maxValFlag = ( defined $Params{$k_maxVal} ) ? "-max \"$Params{$k_maxVal}\"" : "";
for (my $i = 0 ;$i< $#motifFiles;$i++) {
  my $motifI = $motifFiles[$i];
  print "Handling  histogrms for $motifI ...\n";
  my $m1 = $Data{$motifI}{"motifF"};
  for (my $j = $i+1 ;$j<= $#motifFiles;$j++) {
    my $motifJ = $motifFiles[$j];
    my $m2 = $Data{$motifJ}{"motifF"};
    next unless ($Data{$motifI}{$motifJ}{"distlist"});
    #  print "$prlcom $Params{$k_histProg} -In $Data{$motifI}{$motifJ}{"distlistF"} -field 0 $minValFlag $maxValFlag\n";
    #  next;
    my $tmp = `$prlcom $Params{$k_histProg} -In $Data{$motifI}{$motifJ}{"distlistF"} -field 0 $minValFlag $maxValFlag`;
#    if (! $?) {
#      warn "Failed to compute a histogrm for $motifI $motifJ, skipping....\n ";
#      next;
#    }
    #print "$tmp\n";
    # we only do plotting for histograms with at list $minCount points in them
    my @tmp = split(/\n/ , $tmp);
    next unless ($Params{$k_minCount} <= @tmp );
    (my $posBiasHistF = $Data{$motifI}{$motifJ}{"distlistF"}) =~ s/\.distlist$/.disthist/;
    #print "$posBiasHistF\n";
    open HF, ">$posBiasHistF" or die "cannot write to $posBiasHistF $!\n";
    print HF $tmp;
    close(HF);
    $Data{$motifI}{$motifJ}{"disthist"} = $posBiasHistF;
    # ploting:
    #----------
    my $posBiasPlt = "CmpRelDist.hist.$$";#$posBiasHistF;
    (my $titleName = $posBiasHistF) =~ s/$outDir//;
    # read the base gnu file:
    open GF, "<$Params{$k_baseGnuF}" or die "cannot read $Params{$k_baseGnuF} $!\n";
    $tmp = "";
    $tmp = $tmp . $_ while <GF>;
    close(GF);
    # add the relevant settings to the file:
    $tmp = $tmp."set term postscript color solid\n";
    $tmp = $tmp."set output \'$posBiasPlt.eps\'\n";
    $tmp = $tmp."set key right bottom\n";
    $tmp = $tmp."set data style lines\n";
    #    $tmp = $tmp."set yrange [0:$maxHistVal]\n";
    $tmp = $tmp."set xlabel \'Position\'\n";
    $tmp = $tmp."set ylabel \'Probability Disribution\'\n";
    $tmp = $tmp."set title \'Relative Distance $titleName\'\n";
    $tmp = $tmp."set style line 1 lt 1 ps 2 lw 10\n";
    $tmp = $tmp."set style line 2 lt 2 ps 2 lw 10\n";
    $tmp = $tmp."plot \"".$posBiasHistF."\" using 1:2 title \"Relative Distance\" lt 1 lw 10\n";
    my $gnuF = "CmpRelDist.hist.$$.gnu"; #$Params{$k_outStub}.".$i.posBias.gnu";
    open GF, ">$gnuF" or die "cannot write $gnuF $!\n";
    print GF $tmp;
    close(GF);
    system "$gnpltcom -persist $gnuF";
    system "convert -rotate 90 $posBiasPlt.eps $posBiasPlt.png";
    system "convert -resize 180X100 $posBiasPlt.png $posBiasPlt.thmb.png";
    unlink $gnuF;
    unlink "$posBiasPlt.eps";
    rename "$posBiasPlt.png", "$posBiasHistF.png";
    #print "$posBiasHistF.png\n";
    rename "$posBiasPlt.thmb.png", "$posBiasHistF.thmb.png";
    $Data{$motifI}{$motifJ}{"histpng"} = "$posBiasHistF.png";
    $Data{$motifI}{$motifJ}{"histthmb"} = "$posBiasHistF.thmb.png";
    #last;
  }
}

## Make sure we have a SeqLogo for each of the seeds we use, if not - create ones:
##############################################################################
print "Creating SeqLogo if needed....\n";
for (my $i = 0 ;$i< $#motifFiles;$i++) {
  my $motifI = $motifFiles[$i];
  my $m1 = $Data{$motifI}{"motifF"};
  (my $png1 = $m1) =~ s/\.motifs$/.png/;
  (my $thmb1 = $m1) =~ s/\.motifs$/.thmb.png/;
  $Data{$motifI}{"png"} = "$png1";
  $Data{$motifI}{"thmb"} = "$thmb1";
  next if (-f $png1 && -f $thmb1);
  (my $p1 = $m1) =~ s/\.motifs$/.pssm/;
  if (! -f $p1 ) {
    warn "cannot locate file $p1, the matching seqLogo will be missing....\n";
    next;
  }
  my $tmp = `$prlcom $Params{$k_seqlogprg} $p1`;
  my $seqLogo = "CmpRelDist.seqlog.$$";
  open SL, ">$seqLogo.eps" or die "cannot write $seqLogo $!\n";
  print SL $tmp;
  close(SL);
  system "convert $seqLogo.eps $seqLogo.png";
  system "convert -resize 180X100 $seqLogo.png $seqLogo.thmb.png";
  unlink "$seqLogo.eps";
  rename "$seqLogo.png", "$png1";
  print "$png1\n";
  rename "$seqLogo.thmb.png", "$thmb1";
  print "$thmb1\n";
}
  
#### PRINT HTML File:
#######################
my $htmlFile = $Params{$k_outStub}.".html";
open OF, ">$htmlFile" or die "fail to open output file $htmlFile $!\n";
print "Printing $htmlFile....\n";
push @outFilesTypes, "Relative Distance Html Summary";
push @outFilesList, "$htmlFile";
my $linkHeader = "<a href=\""; 
my $linkFooter = "\">";
my $linkFooter2 = "</a>";
my $lineFooter = "</tr>\n";
my  $header = "Relative Distance Summary for: ". basename($Params{$k_seedF});
#print "header: $header\n";
my $tmp = fileHeader($header);
print OF $tmp;
print OF "<h3> $linkHeader$rdFile$linkFooter Stats File $linkFooter2  </h3>\n";
##### Table Header:
print OF "<table border=1>\n";
print OF "<tr>\n<td>MOTIF</td>";
for (my $i = 0 ;$i< $#motifFiles;$i++) {
  my $motifI = $motifFiles[$i];
  my $m1 = $Data{$motifI}{"motifF"};
  my $png1 = $Data{$motifI}{"png"};
  my $thmb1 = $Data{$motifI}{"thmb"};
  print OF " <td> $linkHeader$png1$linkFooter <img src=\"$thmb1\" > $linkFooter2 \n";
  print OF " <br> $linkHeader$m1$linkFooter $motifI $linkFooter </td>";
}
print OF "\n</tr>\n";
####### print each line:
for (my $i = 0 ;$i< $#motifFiles;$i++) {
  my $motifI = $motifFiles[$i]; 
  my $m1 = $Data{$motifI}{"motifF"};
  my $png1 = $Data{$motifI}{"png"};
  my $thmb1 = $Data{$motifI}{"thmb"};
  print OF "<tr>\n";
  print OF " <td> $linkHeader$png1$linkFooter <img src=\"$thmb1\" > $linkFooter2 \n";
  print OF " <br> $linkHeader$m1$linkFooter $motifI $linkFooter </td>";
  for (my $j = $i+1 ;$j<= $#motifFiles;$j++) {
    my $motifJ = $motifFiles[$j];
    my $m1 = $Data{$motifJ}{"motifF"};
    if ($Data{$motifI}{$motifJ}{"distlist"}) {
      if ($Data{$motifI}{$motifJ}{"histpng"}) {
	my $histpng = $Data{$motifI}{$motifJ}{"histpng"};
	my $histthmb = $Data{$motifI}{$motifJ}{"histthmb"};
	print OF "<td >$linkHeader$histpng$linkFooter <img src=\"$histthmb\" > $linkFooter2\t";
      }
      else {
	print OF "<td> NO HIST PLOT: #Targets < $Params{$k_minCount}\t";
      }
      my $distlist = $Data{$motifI}{$motifJ}{"distlist"};
      my $stats = $Data{$motifI}{$motifJ}{"stats"};
      print OF "<br >$linkHeader$distlist$linkFooter $stats $linkFooter2 </td>";
    }
    else {
      print OF "<td> NO TARGET OVERLAPP </td>";
    }
  }
  print OF "\n</tr>";
}
print OF "\n</table>\n";
close(OF);
## PRINT SUMMARY.XML:
####################
my $xmlFile = dirname($outDir)."/summary.xml";
open OF, ">$xmlFile" or die "fail to open output file $xmlFile $!\n";
print OF "<?xml version=\"1.0\"?>\n";
print OF "<resources>";
for (my $i = 0; $i <= $#outFilesList; $i++) {
  my $base = basename $outFilesList[$i];
  my $type = $outFilesTypes[$i];
  print OF "<resource name=\"$base\" type=\"$type\"><field name=\"File\" value=\"$outFilesList[$i]\"/></resource>";
}
print OF "</resources>";
close (OF);

sub fileHeader() {
  my $header = $_[0];
  my $s = "<html>\n";
  $s .= "<head>\n";
  $s .= " <title> $header </title>\n";
  $s .= "</head>\n";
  $s .= "<h1 align=\"left\"><font color=\"#CC0000\" size=\"6\">$header</font></h1>\n";
  return $s;
}

sub Header {
  my ($val, $header) = @_;
  my $s = "<a name=\"$header\"> <h$val align=\"left\"><font color=\"#CC0000\" size=\"4\"> $header </font></h$val> </a>\n";
  return $s;
}




######



# given two .motifs files finds the occurences in each sequence and return this for all sequences with both occurences
# 1. The computation is done in order of files given, i.e file1.motifs compared to file2.motifs
# 2. the minimal distance computed is in ABS value, but it is printed with +- signs, and can therefore indicate order preference too.
# 3. It's important to understand that in the null hypothesis this distibution heavily depends (like in EVD) on the number of sites in the promoter because you always take the minimum over all pairs !!!
sub Compute2SeedsDistanceList  {
  my @mFiles = @_;
  open MF0, "<$mFiles[0]" or die "fail to open $mFiles[0] $!\n";
  my %s1Sites;
  my $s1len;
  my $s1SiteNum;
  while (<MF0>) {
    next if ($. == 1); #skip first line;
    my @fields = split/\t/, $_;
    (my $seq = $fields[2]) =~ s/\s*$//;
    $seq =~ s/^\s*//;
    $fields[4] =~ s/\s*$//;
    $fields[4] =~ s/^\s*//;
    push @{$s1Sites{$seq}}, $fields[4];
    $s1SiteNum++;
    $s1len = ($fields[0] =~ m/\w+ (\w+) \w+/) ? length($1) : length( $fields[0]); # take as lenght just the actual seed.
  }
  close(MF0);
  open MF1, "<$mFiles[1]" or die "fail to open $mFiles[1] $!\n";
  my %s2Sites;
  my $s2len;
  my $s2SiteNum;
  while (<MF1>) {
    next if ($. == 1); #skip first line;
    my @fields = split/\t/, $_;
    (my $seq = $fields[2]) =~ s/\s*$//;
    $seq =~ s/^\s*//;
    $fields[4] =~ s/\s*$//;
    $fields[4] =~ s/^\s*//;
#    print "$fields[4]\n";
    push @{$s2Sites{$seq}}, $fields[4];
    $s2SiteNum++;
    $s2len = ($fields[0] =~ m/\w+ (\w+) \w+/) ? length($1) : length( $fields[0]);
  }
  close(MF1);
  # compute the minimal distance in any sequence containig both seeds:
  my $Best = [];# referece to an empty array
  my $s1BestSite = undef;
  my $s2BestSite = undef;
  my $bestDist = 1000000;
  for my $seq (keys %s1Sites) {
    $s1BestSite = undef;
    $s2BestSite = undef;
    $bestDist = 1000000;
    next unless (exists $s2Sites{$seq});
    my @s1crrSites = @{$s1Sites{$seq}};
    my @s2crrSites = @{$s2Sites{$seq}};
    foreach my $s1 (@s1crrSites) {
      foreach my $s2 (@s2crrSites) {
	if (abs($s1 - $s2) < abs($bestDist)) {
	  $bestDist = $s1 - $s2;
	  $s1BestSite = $s1;
	  $s2BestSite = $s2;
	}
      }
    }
    push @{$Best}, [$bestDist, $seq, $s1BestSite,  $s2BestSite] if (defined $s1BestSite);
  }
  return $Best;
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

sub med {
  my @vals = @_;
  @vals = sort {$a <=> $b } (@vals);
  my $medVal = (@vals % 2 == 0) ? ($vals[@vals/2] + $vals[@vals/2 - 1])/2 : $vals[$#vals/2];
  return $medVal;
}
