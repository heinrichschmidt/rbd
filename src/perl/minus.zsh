#!/bin/zsh

for i (*gd*data)
do
	echo $i
	perl cutcube.pl $i 60 20 20 0 > file.csv
	Rscript minus20.R
	cat fileout.csv| sed -r s/.+\",//|tail -n $[`wc -l fileout.csv|sed -r s/fileout.csv//`-1] > ${i/.data/_input.csv}
done

