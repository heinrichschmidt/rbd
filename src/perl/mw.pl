#!/usr/bin/perl

sub adding
{
	$nr = $_[0];
	if($nr<1)
	{
		if($nr==0)
		{
			$nr = 1/$_[2];
		}
		if(((1/$nr)-$_[1])==0)
		{
			$nr = 1/((1/$nr)-$_[1]+$_[1]/10);#sinn?
		}else{
			$nr = 1/((1/$nr)-$_[1]);
		}
	}else
	{
		$nr += $_[1];
	}
	return $nr;
}

print "#size ratio, number of spheres ratio, fillingfactor\n";
for($sr=0.001;$sr<=1;$sr+=0.001) #for-loop for the size-ratio
{
	for($nr=0;$nr<=0.5;$nr+=0.1)
	{
		$ff = `./test/main -n 1000000 -b -x 100 -y 100 -z 100 -p $sr -q $nr | ./cutcube.pl 50 25 25 25 | ./fillingfactor.pl`;
		print "$sr,$nr,$ff ";
	}
}
