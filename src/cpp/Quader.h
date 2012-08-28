#ifndef QUADER_H
#define QUADER_H


#include "Sphere.h"
#include <vector>
#include <algorithm>
#include <set>




class Saeule{
	public:
		Saeule();
		~Saeule();
		class Sphere geteintrag(int i);
		void addeintrag(class Sphere kugel);
		double dropSphere(class Sphere kugel);
		double collisiondetect(class Sphere kugel);
		int getanzahl();
	protected:
		int anzahl;
		int platz;
		std::vector<class Sphere> Zahlen;
		std::set<class Sphere> Sphereset;
		class Sphere *liste;
	
};


class Quader{
	public:
//		quader(int x, int y);
//		~quader();
//		double dropSphere(class Sphere kugel);
		double get_volume();
		int get_quantity();
	protected:
//		class saeule ** saeulen;
		double xmax;
		double ymax;
		double zmax;
		int quantity;
//		double z;

};


class Squader : public Quader{
	public:
		Squader(int x, int y);
		Squader(int x, int y, int z);
		~Squader();
		double dropSphere(class Sphere kugel);
//		double get_volume();
//		int get_quantity();
		double get_fillfactor();
	protected:
		class Saeule ** saeulen;
		double filled_volume;
//		int xmax;
//		int ymax;
//		int zmax;
//		int quantity;
		double z;
};

//#include "Sphere.h"
//#include <vector>
//#include <algorithm>
//#include <set>




class Ssaeule{
	public:
		Ssaeule();
		~Ssaeule();
		class Sphere geteintrag(int i);
		void addeintrag(class Sphere kugel);
		double dropSphere(class Sphere kugel);
		double collisiondetect(class Sphere kugel);
		int getanzahl();
	protected:
		int anzahl;
		int platz;
		std::vector<class Sphere> Zahlen;
		std::set<class Sphere> Sphereset;
		class Sphere *liste;
	
};

class Subcubic{
	public:
		Subcubic();
		~Subcubic();
		class Sphere getentry(int i);
		int get_quantity();
		bool collisiondetect(class Sphere kugel);
		void putSphere(class Sphere kugel);
	protected:
		void addentry(class Sphere kugel);
		std::vector<class Sphere> Zahlen;
		int quantity;
};


class Wquader: public Quader{
	public:
		Wquader(int x, int y, int z);
		~Wquader();
		double dropSphere(class Sphere kugel);
		int putSphere(class Sphere kugel);
//		double get_volume();
//		int get_quantity();
	protected:
		class Ssaeule ** saeulen;
		class Subcubic *** cubics;
//		int xmax;
//		int ymax;
//		int zmax;
//		int quantity;
		int min(int a, int b);
		int max(int a, int b);
//		double z;
};



#endif 
