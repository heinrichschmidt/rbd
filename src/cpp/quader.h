#include "sphere.h"
#include <vector>
#include <algorithm>
#include <set>




class saeule{
	public:
		saeule();
		class sphere geteintrag(int i);
		void addeintrag(class sphere kugel);
		double dropsphere(class sphere kugel);
		double collisiondetect(class sphere kugel);
		int getanzahl();
	protected:
		int anzahl;
		std::vector<class sphere> Zahlen;
		std::set<class sphere> sphereset;
		class sphere *liste;
	
};


class quader{
	public:
		quader(int x, int y);
		~quader();
		double dropsphere(class sphere kugel);
	protected:
		class saeule ** saeulen;
		int xmax;
		int ymax;
};



