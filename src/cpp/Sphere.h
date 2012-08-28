#ifndef SPHERE_H
#define SPHERE_H

class Sphere{
	public:
		Sphere(double x, double y, double z, double r);
		Sphere();
		int show(void);
		bool operator<(class Sphere b){
			return ((z_+r_) < (b.getZ()+b.getR()));
		}
		double distance_xy(class Sphere k2);
		double getX() { return x_;}
		double getY() { return y_;}
		double getZ() { return z_;}
		double getR() { return r_;}
		void setX(double x) { x_ = x;}
		void setY(double y) { y_ = y;}
		void setZ(double z) { z_ = z;}
		void setR(double r) { r_ = r;} 
	private:
		double x_;
		double y_;
		double z_;
		double r_;
};




#endif
