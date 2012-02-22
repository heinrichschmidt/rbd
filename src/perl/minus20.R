#!/usr/bin/Rscript

csvfile <- read.csv("file.csv");

csvfile[1] <- csvfile[1]-20;
csvfile[2] <- csvfile[2]-20;
#csvfile[3] <- csvfile[3]-20;

write.csv(csvfile, "fileout.csv");
