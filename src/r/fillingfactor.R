#!/usr/bin/Rscript

source('volume.R')

args <- commandArgs(TRUE)

csv <- read.csv(args[1])

filename <- "ff.csv"
zlist <- 0

dz = 0.5

{
if( args[2] == 'x' ) {
	p1 <- genHessPlane( 1, 0, 0,-dz )
	p2 <- genHessPlane( 1, 0, 0, 0  )
	zlist  <- ( -1 : ( max( csv$x ) / dz ) ) * dz
	V <- areaYzMedium( csv ) * dz
	filename <- paste(sep='',args[1],"-x-ff.csv")
}
else if( args[2] == 'y' ) {
	p1 <- genHessPlane( 0, 1, 0,-dz )
	p2 <- genHessPlane( 0, 1, 0, 0  )
	zlist  <- ( -1 : ( max( csv$x ) / dz ) ) * dz
	V <- areaXzMedium( csv ) * dz
	filename <- paste(sep='',args[1],"-y-ff.csv")
}
else {
	p1 <- genHessPlane( 0, 0, 1,-dz )
	p2 <- genHessPlane( 0, 0, 1, 0  )
	zlist  <- ( -1 : ( max( csv$z ) / dz ) ) * dz
	V <- areaXyMedium( csv ) * dz
	filename <- paste(sep='',args[1],"-z-ff.csv")
}
}

ff <- NULL

for( j in zlist ) {
	vs <- 0
	for( i in (1:length(csv$x)) ) {
		erg <- sphereInPlanes(c(csv$x[i], csv$y[i], csv$z[i],csv$r[i]), p1, p2 )
		#if( erg > 0 ) { print(erg) }
		vs <- vs + erg
	}
	ff$x[j] <- mean( p1$a, p2$a )
	ff$y[j] <- vs/V
	p1$a <- p1$a + dz
	p2$a <- p2$a + dz
}
#print(V)
#print(vs)
write.csv( ff, filename , row.names=FALSE )
print(ff)
