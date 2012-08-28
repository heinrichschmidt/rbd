#include "Sphere.h"
#include <vector>
#include <algorithm>
#include <set>




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


class Wquader{
	public:
		Wquader(int x, int y, int z);
		~Wquader();
		double dropSphere(class Sphere kugel);
		int putSphere(class Sphere kugel);
		double get_volume();
		int get_quantity();
	protected:
		class Ssaeule ** saeulen;
		class Subcubic *** cubics;
		int xmax;
		int ymax;
		int zmax;
		int quantity;
		int min(int a, int b);
		int max(int a, int b);
//		double z;
};



