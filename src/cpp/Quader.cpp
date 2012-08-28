
#include <cmath>
#include <stdio.h>
#include "Quader.h"


double Quader::get_volume()
{
	return (xmax*ymax*zmax);
}

int Quader::get_quantity(){
	return quantity;
}
