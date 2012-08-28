#include "Sphere.h"
#include <vector>
#include <algorithm>
#include <set>




class Saeule{
	public:
		Saeule();
		class Sphere geteintrag(int i);
		void addeintrag(class Sphere kugel);
		double dropSphere(class Sphere kugel);
		double collisiondetect(class Sphere kugel);
		int getanzahl();
	protected:
		int anzahl;
		std::vector<class *Sphere> Zahlen;
		std::set<class *Sphere> Sphereset;
		class Sphere *liste;
	
};


class Quader{
	public:
		Quader(int x, int y);
		~Quader();
		double dropSphere(class Sphere kugel);
		double get_volume();
		double get_fillfactor();
		int get_quantity();
	protected:
		class Saeule ** saeulen;
		int xmax;
		int ymax;
		int zmax;
		int quantity;
		double filled_volume;
		double z;
};



