#!/usr/bin/perl

if(-e $ARGV[0]){
	open(fhz,">","z.dat");
	open(fhy,">","y.dat");
	open(fhx,">","x.dat");
	for($i=0;$i<45;$i+=1)
	{
		$tmp2 = $i * 2;
		$tmp = `perl cutcube.pl $ARGV[0] 10 50 50 $tmp2 | perl fillingfactor.pl`;
		print fhz "$i\t$tmp";
		$tmp = `perl cutcube.pl $ARGV[0] 10 50 $tmp2 50 | perl fillingfactor.pl`;
		print fhy "$i\t$tmp";
		$tmp = `perl cutcube.pl $ARGV[0] 10 $tmp2 50 50 | perl fillingfactor.pl`;
		print fhx "$i\t$tmp";
	}
	close(fhz);
	close(fhy);
	close(fhz);
	system("gnuplot ffxyz.gp");
}else{

}

