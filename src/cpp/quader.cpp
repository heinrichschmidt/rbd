
#include <cmath>
#include <stdio.h>
#include "quader.h"


double quader::get_volume()
{
	return (xmax*ymax*zmax);
}

int quader::get_quantity(){
	return quantity;
}
