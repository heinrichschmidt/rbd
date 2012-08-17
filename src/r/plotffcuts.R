#!/usr/bin/Rscript

color <- c("blue","red","yellow","green","brown","cyan","gray","hotpink","orange","tan","sienna","plum","orange")

filenames <- c("medium_rbd_case06_03_input.csv-z-ff.csv")

ffcut <- read.csv(filenames)
	
pdf("ffcuts.pdf")

plot(ffcut$x,ffcut$y,xlim=range(1,180),ylim=range(0,0.2),log="",pch=0,col=color[1],type="b",xlab="cut layer height",ylab="fillingfactor")

	legend("topright", filenames, pch=c(0), col=color[1])

dev.off()
