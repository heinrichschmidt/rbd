#!/usr/bin/Rscript

source('plot.R')

plotstart_ff(c("test3.csv-z-ff.csv"))
plotadd_ff(c("test2.csv-z-ff.csv"),number=2)
labeladd_ff(c("leeres Medium", "volles Medium"))
dev.off()


