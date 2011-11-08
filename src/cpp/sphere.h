#ifndef SPHERE_H
#define SPHERE_H

class sphere{
	public:
		double x;
		double y;
		double z;
		double r;
		sphere(double x1, double y1, double z1, double r1);
		sphere();
		int show(void);
		bool operator<(class sphere b){
			return (z < b.z);
		}
		double distance_xy(class sphere k2);
};




#endif
