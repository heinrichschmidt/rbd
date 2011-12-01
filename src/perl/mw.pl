#!/usr/bin/perl

print "#size ratio, number of spheres ratio, fillingfactor\n";
for($sr=1;$sr<=10;$sr+=0.1) #for-loop for the size-ratio
{
	for($nr=0;$nr<=10;$nr+=0.1)
	{
		$ff = `./../cpp/main -n 1000000 -b -x 100 -y 100 -z 100 -p $sr -q $nr | ./cutcube.pl| ./fillingfactor.pl`;
		print "$sr,$nr,$ff ";
	}
}
