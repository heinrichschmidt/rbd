#!/usr/bin/perl

$stdin=0;

if(-e $ARGV[0]){
	open(STDIN, "<", $ARGV[0]);
#	open(fhz,">","z.dat");
#	open(fhy,">","y.dat");
#	open(fhx,">","x.dat");
#	for($i=0;$i<20;$i+=1)
#	{
#		$tmp = `perl subfillingfactor.pl $ARGV[0] 0 0 1 10 5 2000`;
#		print "$i\t$tmp";
#		$tmp = `perl subfillingfactor.pl $ARGV[0] 0 1 0 $i 2 20000`;
#		print fhy "$i\t$tmp";
#		$tmp = `perl subfillingfactor.pl $ARGV[0] 1 0 0 $i 2 20000`;
#		print fhx "$i\t$tmp";
#	}
#	close(fhz);
#	close(fhy);
#	close(fhz);
#	system("gnuplot ffxyz.gp");
	
}else{
	$stdin=1;
}

$xa = 0;
$ya = 0;
$za = 0;
$xe = 10;
$ye = 10;
$ze = 10;
if(defined $ARGV[1-$stdin])
{
	$a = $ARGV[1-$stdin]+0;
	if(defined $ARGV[2-$stdin])
	{
		$xa = $ARGV[2-$stdin]+0;
		if(defined $ARGV[3-$stdin])
		{
			$ya = $ARGV[3-$stdin]+0;
			if(defined $ARGV[4-$stdin])
			{
				$za = $ARGV[4-$stdin]+0;
			}
		}
	}
	$xe = $xa + $a;
	$ye = $ya + $a;
	$ze = $za + $a;
}


until(eof(STDIN))
{
	$_ = <>;
	@xyzr = split/,/;
	if(($xyzr[0]<$xe)and($xyzr[0]>$xa)and($xyzr[1]<$ye)and($xyzr[1]>$ya)and($xyzr[2]<$ze)and($xyzr[2]>$za))
	{
		print $_;
	}
}


