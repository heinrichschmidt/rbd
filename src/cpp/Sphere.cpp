#include "Sphere.h"
#include <cmath>
#include <stdio.h>
//bool Sphere::operator<(
Sphere::Sphere(double x, double y, double z, double r){
	x_ = x;
	y_ = y;
	z_ = z;
	r_ = r;
}

Sphere::Sphere(){
	x_ = 0;
	y_ = 0;
	z_ = 0;
	r_ = 0;
}

int Sphere::show(){
	printf("%f,\t%f,\t%f,\t%f\n",x_,y_,z_,r_);
	return 0;
}

double Sphere::distance_xy(class Sphere k2)
{
	return sqrt(pow((x_ - k2.getX()),2) + pow((y_ - k2.getY()),2));
}
