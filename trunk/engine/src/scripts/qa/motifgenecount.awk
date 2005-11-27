#!/usr/bin/gawk -f
#usage: motifgenecount.awk <.motif file>
# this is how a motif line looks like
# TGCGAT TCCCCACGC TATTA	2	YDL130W-A	[0.989932912817]	189	+
#         $1			$2	$3		$4			$5	$6

BEGIN {
	current_seq = ""
	gene_count = 0
	FS="\t"
}

{
	if ($3 != current_seq) {
		gene_count++;
		current_seq = $3;
	}
}

END {
	print gene_count;
}
