#!/usr/bin/perl
#
# The purpose of this script is to provide a crude yet efficient way 
# to convert a PSSM to a concensus sequence.
# Author: Aviad Rozenhek (aviadr@cs.huji.ac.il)
# Revision Date: 20/3/05 

use strict;
use warnings;
use POSIX;
use SnapUtil;

my $thresh = 0.4;
my $dominance_thresh = "0.55";
my $shortening_factor = "3";

# read data
my @data;
my $i = 1;

open( IN, '<'.$ARGV[0] ) || die( "unable to open file ($ARGV[0])" );
foreach $a ("A", "C", "G", "T") {
	my $line = <IN>;
	chomp $line;
	
	# remove whitespace from beginning and end of line
   $line =~ SnapUtil::trim ($line);

	# transform whitespace into tabs   
	$line =~ tr/ /\t/;

	# split columns by tabs	
	my @parsed_line = split (/\t+/, $line);        
	push(@data, \@parsed_line);
}
close(IN);

my @transposed_data = transpose( @data );

my $seqlen = $#transposed_data;
my $short_seqlen = floor($seqlen / $shortening_factor);

# remove from beginning
for( my $j = 0; $j < $short_seqlen; $j++ ) {
	my @parsed_line = @{ shift @transposed_data };
	if (max (@parsed_line) >= $dominance_thresh) {
		# return this position back to the array
		unshift (@transposed_data, \@parsed_line);
		last;
	}

}

# remove from end
for (my $j=0 ; $j <= $short_seqlen ; $j++) {
	my @parsed_line = @{ pop(@transposed_data) };
	if (max (@parsed_line) >= $dominance_thresh) {
		# return this position back to the array
		push (@transposed_data, \@parsed_line);
		last;
	}
}
        
# convert pssm to character sets
my @sequence;

for( $i = 0; $i < @transposed_data; $i++ ) {
	my @parsed_line = @{ $transposed_data[$i] };
        
	$sequence[$i] = "";
	foreach $a ("A", "C", "G", "T") {        
		my $weight = shift( @parsed_line ) + 0;
		$sequence[$i] = $sequence[$i] . $a if ($weight >= $thresh);
	}
}

#Translation Table
my %codeToIUPAC = (
	'A',    	'A',
	'C',		'C',
	'G',		'G',
	'T',		'T',
	'AG',		'R',
	'CT',		'Y',
	'GT',		'K',
	'AC',		'M',
	'CG',		'S',
	'AT',		'W',
	'CGT',	'B',
	'ACT',	'H',
	'ACG',	'V',
	'AGT',	'D',
	'ACGT',	'N' );

# now convert the sequence to IUPAC
my $output;
for ($i=0 ; $i < scalar (@sequence) ; $i++) {
	my $code = $sequence[$i];
	my $iupac = "N";
	$iupac = $codeToIUPAC{$code} if( exists( $codeToIUPAC{$code} ) );
	$output .= $iupac;
}

# remove the first and the last 'N's 
$output =~ s/^N*//;
$output =~ s/N*$//;
print $output . "\n";



# return the maximum value from an array of values
sub max {
    my $max = shift;
    foreach my $temp (@_) {
        $max = $temp if $temp > $max;
    }
    
    return $max;
}

# tranpose a 2D array - Thanks Jeremy!
sub transpose {
	my @inArray = @_;
	my @ret;

	for( my $i = 0; $i < @inArray; $i++ ) {
		my @innerArray = @{$inArray[$i]};
		for( my $j = 0; $j < @innerArray; $j++ ) {
			$ret[$j] = [] if( !defined($ret[$j]) );
			$ret[$j]->[$i] = $innerArray[$j];
		}
	}
	return @ret;
}
