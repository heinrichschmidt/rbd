sphereVolume <- function(radius) {
	
	return( 4/3 * pi * radius^3 )
}

sphericalCapVolume <- function(radius, height) {
	return( pi * height^2 / 3 * ( 3 * radius - height ) )
}

sphereCorpseVolume <- function(radius, height1, height2) {
	return( sphereVolume(radius) - sphericalCapVolume(radius, height1) - sphericalCapVolume(radius, height2) )
}

genHessPlane <- function( x, y, z, a ) { #plane in hesse normal form
	plane <- NULL
	plane$n <- c(x,y,z)
	plane$a <- a
	return( plane )
}

genVector <- function( x, y , z ) {
	return( c( x, y, z ) )
}

vLength <- function( dot ) {
	sqrt( sum( dot * dot ) )
}

distanceDotPlane <- function ( dot, plane ) {
	return( ( sum( dot * plane$n ) - plane$a ) / ( vLength( plane$n ) ) ) 
}

sphereInPlanes <- function( sphere, plane1, plane2 ) {
	d1 <- distanceDotPlane( sphere[1:3], plane1 )
	d2 <- distanceDotPlane( sphere[1:3], plane2 )
	if( d1 > sphere[4] & d2 > sphere[4] ) {
		return(0)
	}
}

