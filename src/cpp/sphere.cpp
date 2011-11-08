#include "sphere.h"
#include <cmath>
#include <stdio.h>
//bool sphere::operator<(
sphere::sphere(double x1, double y1, double z1, double r1){
	x = x1;
	y = y1;
	z = z1;
	r = r1;
}

sphere::sphere(){
	x = 0;
	y = 0;
	z = 0;
	r = 0;
}

int sphere::show(){
	printf("%f,\t%f,\t%f,\t%f\n",x,y,z,r);
	return 0;
}

double sphere::distance_xy(class sphere k2)
{
	return sqrt(pow((x - k2.x),2) + pow((y - k2.y),2));
}
