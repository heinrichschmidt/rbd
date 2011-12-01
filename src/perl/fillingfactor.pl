#!/usr/bin/perl

$pi = 3.141592653589793;

if(-e $ARGV[0]){
	open(STDIN, "<", $ARGV[0]);
}


@max;
@min;
$_ = <>;
@xyzr = split/,/;
$ff =  $xyzr[3]**3 * 4/3 * $pi;
for($i=0;$i<3;$i++)
{
	$max[$i] = $xyzr[$i]+$xyzr[3];
	$min[$i] = $xyzr[$i]-$xyzr[3];
}
$count = 1;
until(eof(STDIN))
{
	$count++;
	$_ = <STDIN>;
	@xyzr = split/,/;
	$ff +=  $xyzr[3]**3 * 4/3 * $pi;
	for($i=0;$i<3;$i++) #get the filled volume
	{
		$tmp = $xyzr[$i] ;#+ $xyzr[3];
		if($max[$i] < $tmp)
		{
			$max[$i] = $tmp;
		}
		$tmp = $xyzr[$i] ;#- $xyzr[3];
		if($min[$i] > $tmp)
		{
			$min[$i] = $tmp;
		}
	}
}
$volume =  ($max[0]-$min[0]) * ($max[1]-$min[1]) * ($max[2]-$min[2]); 
print $ff/($volume)  ."\n";

