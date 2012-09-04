color <- c("blue","red","yellow","green","brown","cyan","gray","hotpink","orange","tan","sienna","plum","orange")
rrr <- NULL
rrr$exp <- c(1,2,3)
rrr$descr <- c("r","r^2", "r^3")
rrr$col <- c("r","r.2", "r.3")


labels <- NULL
read_files_ff <- function(filenames,radcol=1) {
	#options(error=recover)
	r <- NULL
	for( i in filenames) {
		print(i);
		r1 <- read.csv(i)
		r <- c( r, subset( r1, r1$y<10000 ) )
	}
	return(r);
}

plotstart_ff <- function(filenames, labelname="data",radcol=1) {
	pdf("ffplot.pdf")
	r <- read_files_ff(filenames,radcol=radcol)
	#h <- hist( r, plot=FALSE, breaks=20*max(r) )
	#h$counts <- h$counts / sum( h$counts )
	plot(r$x,r$y,xlim=range(0.1,100),ylim=range(0.050,0.22),log="",pch=0,col=color[1],type="b",xlab=paste("z-Koordinate"),ylab="Volumenfüllfaktor")
#	labels <- c(labels, labelname)

}

plotadd_ff <- function(filenames,labelname="data",number=1,radcol=1) {
	print(number);
	r <- read_files_ff(filenames,radcol=radcol)
	#h <- hist(r,plot=FALSE, breaks=20*max(r))
	#h$counts <- h$counts/sum(h$counts)
	points(r$x,r$y,pch=number-1,col=color[number],type="b")
#	labels <- c(labels, labelname)

}

labeladd_ff <- function(filenames) {
#	legend("topright", c("rbd-case01","rbd-case02","rbd-case03","rbd-case04","rbd-case05","rbd-case06", "gd-case01","gd-case02","gd-case03","gd-case04","gd-case05","gd-case06","aggregate"), pch=c(0,1,2,3,4,5,6,7,8,9,10,11,12), col=color[1:13])
#	legend("topright", labels, pch=c(0:length(labels), col=color[1:length(labels)]))
	legend("topright", filenames, pch=c(0:length(filenames)), col=color[1:length(filenames)])
}


