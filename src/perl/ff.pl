#!/usr/bin/perl

if(-e $ARGV[0]){
#	open(fhz,">","z.dat");
#	open(fhy,">","y.dat");
#	open(fhx,">","x.dat");
#	for($i=0;$i<20;$i+=1)
#	{
		$tmp = `perl subfillingfactor.pl $ARGV[0] 0 0 1 10 5 2000`;
		print "$i\t$tmp";
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

}

