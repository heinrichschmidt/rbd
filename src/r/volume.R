

volumeMedium <- function(csv) {
	dx <- max(csv$x + csv$r) - min(csv$x - csv$r)
	dy <- max(csv$y + csv$r) - min(csv$y - csv$r)
	dz <- max(csv$z + csv$r) - min(csv$z - csv$r)
	return <- dx * dy * dz;
}

areaXyMedium <- function(csv) {
	dx <- max(csv$x + csv$r) - min(csv$x - csv$r)
	dy <- max(csv$y + csv$r) - min(csv$y - csv$r)
	return <- dx * dy
}


areaYzMedium <- function(csv) {
	dz <- max(csv$z + csv$r) - min(csv$z - csv$r)
	dy <- max(csv$y + csv$r) - min(csv$y - csv$r)
	return <- dz * dy
}


areaXzMedium <- function(csv) {
	dx <- max(csv$x + csv$r) - min(csv$x - csv$r)
	dz <- max(csv$z + csv$r) - min(csv$z - csv$r)
	return <- dx * dz
}

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
	if( d1 > sphere[4]) {
		if( d2 > sphere[4] ) {
			return(0)
		}
		else if( d2 < -sphere[4] ) {
			return( sphereVolume( sphere[4] ) )
		}
		else {
			return( sphericalCapVolume( sphere[4], sphere[4] - d2 ) )
		}
	}
	else if( d1 < -sphere[4] ) {
		if( d2 > sphere[4] ) {
			print(2) #impossible case if p2>p1
		}
		else if( d2 < -sphere[4] ) {
			return(0)
		}
		else {
			print(3) #impossible case if p2>p1
		}
	}
	else {
		if( d2 > sphere[4] ) {
			print(4) #impossible case if p2>p1
		}
		else if( d2 < -sphere[4] ) {
			#print(5)
			return( sphericalCapVolume( sphere[4], sphere[4] + d1 ) )
		}
		else {
			return( sphereCorpseVolume( sphere[4], sphere[4] - d1, sphere[4] + d2 ) )
		}
	}
	return(-1)
}

