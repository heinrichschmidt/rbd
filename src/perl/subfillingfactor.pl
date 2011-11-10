#!/usr/bin/perl

$pi = 3.14159;

$x = $ARGV[1]+0;
$y = $ARGV[2]+0;
$z = $ARGV[3]+0;
$d = $ARGV[4]+0;
$w = $ARGV[5]+0;
$V = $ARGV[6]+0;

if(-e $ARGV[0])
{
	open(fh,"<",$ARGV[0]);
		@file = <fh>;
	close(fh);
	$fvolume = 0;
	foreach(@file)
	{
		chomp();
		@xyzr = split/,/;
#		print "$xyzr[2]\n";
		$hess = ( ($x*$xyzr[0])	+($y*$xyzr[1]) 	+ ($z*$xyzr[2]) - $d );
		if(($hess>=0)and($hess <= $w))
		{
			$fvolume += $xyzr[3]**3 * 4/3 * $pi;
		}
	}
	$ff = $fvolume/$V;
	print "$ff\n";
}else
{
	print "./subfillingfactor.pl filename x y z d w V\n xyzd are the hesse-normal-form parameter, w is the width of the subquader. V is the Volume of the subquader.\n";

}

