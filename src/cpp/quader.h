#ifndef QUADER_H
#define QUADER_H


#include "sphere.h"
#include <vector>
#include <algorithm>
#include <set>




class saeule{
	public:
		saeule();
		~saeule();
		class sphere geteintrag(int i);
		void addeintrag(class sphere kugel);
		double dropsphere(class sphere kugel);
		double collisiondetect(class sphere kugel);
		int getanzahl();
	protected:
		int anzahl;
		int platz;
		std::vector<class sphere> Zahlen;
		std::set<class sphere> sphereset;
		class sphere *liste;
	
};


class quader{
	public:
//		quader(int x, int y);
//		~quader();
//		double dropsphere(class sphere kugel);
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


class squader : public quader{
	public:
		squader(int x, int y);
		squader(int x, int y, int z);
		~squader();
		double dropsphere(class sphere kugel);
//		double get_volume();
//		int get_quantity();
		double get_fillfactor();
	protected:
		class saeule ** saeulen;
		double filled_volume;
//		int xmax;
//		int ymax;
//		int zmax;
//		int quantity;
		double z;
};

//#include "sphere.h"
//#include <vector>
//#include <algorithm>
//#include <set>




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
		int platz;
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


class wquader: public quader{
	public:
		wquader(int x, int y, int z);
		~wquader();
		double dropsphere(class sphere kugel);
		int putsphere(class sphere kugel);
//		double get_volume();
//		int get_quantity();
	protected:
		class ssaeule ** saeulen;
		class subcubic *** cubics;
//		int xmax;
//		int ymax;
//		int zmax;
//		int quantity;
		int min(int a, int b);
		int max(int a, int b);
//		double z;
};



#endif 
