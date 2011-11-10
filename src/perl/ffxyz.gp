#!/usr/bin/gnuplot

set terminal png
set output "x.png"
plot "./x.dat" with lines

set output "y.png"
plot "./y.dat" with lines

set output "z.png"
plot "./z.dat" with lines
