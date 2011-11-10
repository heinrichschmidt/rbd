#!/usr/bin/perl

if(-e $ARGV[0]){
	open(fhz,">","z.dat");
	open(fhy,">","y.dat");
	open(fhx,">","x.dat");
	for($i=0;$i<20;$i+=0.1)
	{
		$tmp = `perl subfillingfactor.pl ../cpp/rbd05.data 0 0 1 $i 1 400`;
		print fhz "$i\t$tmp";
		$tmp = `perl subfillingfactor.pl ../cpp/rbd05.data 0 1 0 $i 1 400`;
		print fhy "$i\t$tmp";
		$tmp = `perl subfillingfactor.pl ../cpp/rbd05.data 1 0 0 $i 1 400`;
		print fhx "$i\t$tmp";
	}
	close(fhz);
	close(fhy);
	close(fhz);
	system("gnuplot ffxyz.gp");
}else{

}

