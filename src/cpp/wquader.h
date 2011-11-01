#include "sphere.h"
#include <vector>
#include <algorithm>
#include <set>




class ssaeule{
	public:
		ssaeule();
		~ssaeule();
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

class subcubic{
	public:
		subcubic();
		~subcubic();
		class sphere getentry(int i);
		int get_quantity();
		bool collisiondetect(class sphere kugel);
		void putsphere(class sphere kugel);
	protected:
		void addentry(class sphere kugel);
		std::vector<class sphere> Zahlen;
		int quantity;
};


class wquader{
	public:
		wquader(int x, int y, int z);
		~wquader();
		double dropsphere(class sphere kugel);
		int putsphere(class sphere kugel);
		double get_volume();
		int get_quantity();
	protected:
		class ssaeule ** saeulen;
		class subcubic *** cubics;
		int xmax;
		int ymax;
		int zmax;
		int quantity;
		int min(int a, int b);
		int max(int a, int b);
//		double z;
};



