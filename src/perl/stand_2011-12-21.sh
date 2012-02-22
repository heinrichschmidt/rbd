#!/bin/bash

#masse in groß, oberfläche in klein:
NAME=rbd_masse_in_gr_A_in_kl
../cpp/main  -n 1500000 -b -x 100 -y 100 -z 100 -p 0.1 -q 10 > $NAME.data
perl fillfactor_cuts.pl $NAME.data
convert x.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-x.png
convert y.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-y.png
convert z.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-z.png
echo $NAME > fillingfactors.dat
cat $NAME.data | ./cutcube.pl| ./fillingfactor.pl >> fillingfactors.dat

#masse in groß, oberfläche in groß:
NAME=rbd_masse_in_gr_A_in_gr
../cpp/main  -n 1200000 -b -x 100 -y 100 -z 100 -p 0.05 -q 2 > $NAME.data
perl fillfactor_cuts.pl $NAME.data
convert x.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-x.png
convert y.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-y.png
convert z.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-z.png
echo $NAME >> fillingfactors.dat
cat $NAME.data | ./cutcube.pl| ./fillingfactor.pl >> fillingfactors.dat

#masse in groß, oberfläche in klein:
NAME=rbd_masse_in_kl_A_in_kl
../cpp/main  -n 2000000 -b -x 80 -y 80 -z 80 -p 0.05 -q 100 > $NAME.data
perl fillfactor_cuts.pl $NAME.data
convert x.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-x.png
convert y.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-y.png
convert z.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-z.png
echo $NAME >> fillingfactors.dat
cat $NAME.data | ./cutcube.pl| ./fillingfactor.pl >> fillingfactors.dat


#gaussverteilung:
NAME=gaussdistr
../cpp/main  -n 1200000 -b -x 100 -y 100 -z 100 -g > $NAME.data
perl fillfactor_cuts.pl $NAME.data
convert x.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-x.png
convert y.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-y.png
convert z.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-z.png
echo $NAME >> fillingfactors.dat
cat $NAME.data | ./cutcube.pl| ./fillingfactor.pl >> fillingfactors.dat

#cubic distribution:
NAME=cubicdistr
../cpp/main  -n 2000000 -b -x 100 -y 100 -z 100 -c > $NAME.data
perl fillfactor_cuts.pl $NAME.data
convert x.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-x.png
convert y.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-y.png
convert z.png -fill black -gravity Center -pointsize 20 -annotate +0+5 "$NAME" $NAME-z.png
echo $NAME >> fillingfactors.dat
cat $NAME.data | ./cutcube.pl| ./fillingfactor.pl >> fillingfactors.dat


