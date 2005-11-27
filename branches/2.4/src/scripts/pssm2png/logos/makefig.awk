function swap(n, m) {
    TempP = p[n];
    TempQ = q[n];
    p[n] = p[m];
    q[n] = q[m];
    p[m] = TempP;
    q[m] = TempQ;
}

function SortStack() {
    if( p[1] > p[2] ) swap(1,2);
    if( p[1] > p[3] ) swap(1,3);
    if( p[1] > p[4] ) swap(1,4);
    if( p[2] > p[3] ) swap(2,3);
    if( p[2] > p[4] ) swap(2,4);
    if( p[3] > p[4] ) swap(3,4);
}

function PrintStack() {
    SortStack();
    if (p[1] == -1 && p[2] == -1 && p[3] == -1 && p[4] == -1) 
	print "2.4( ) numchar\n0.2(-) numchar";
    else
	for( j = 1; j <= 4; j++ )
	    if( p[j]*H > 0.05 )
		print p[j]*H*5/2.0 "(" q[j] ") numchar";
}

function PrintEPS() {
    for( i = 1; i <= n; i++ ) {
	H = 0;
	N = 0;
	if (Counts[1,i]=="-" && Counts[2,i]=="-" && Counts[3,i]=="-" && Counts[4,i]=="-") {
	    H = 0;
	    p[1] = p[2] = p[3] = p[4] = -1;
	} else {
	    for( j = 1; j  <= 4; j++ )
		N += Counts[j,i] + 0.000001;
	    for( j = 1; j  <= 4; j++ ) {
		p[j] = (Counts[j,i] + 0.000001)/N;
		H += -p[j] * log(p[j])/log(2.0);
	    }
	    H = 2.0 - H;
	}
	print "% at coordinate " i;
	print "numbering {(" i ") makenumber} if";
	print "gsave";
	q[1] = "A";
	q[2] = "C";
	q[3] = "G";
	q[4] = "T";
	PrintStack();
	print "grestore";
	print "shift";
    }
}


BEGIN {
    line = 1;
}

{
    if (/^ *$/) {
	PrintEPS();
	print "shift";
	print "shift";
	for( i = 1; i <= n; i++ )
	    for( j = 1; j  <= 4; j++ )
		Counts[j,i]=0;
	line = 1;
	n = 0;
    } else {
	for( i = 1; i <= NF; i++ )
	    Counts[line,i] = $i;
	n = NF;
	line++ ;
    }
}


END {
    PrintEPS();
}
