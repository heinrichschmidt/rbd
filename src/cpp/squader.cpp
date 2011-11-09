//class sphere geteintrag(int i);
//void addeintrag(class sphere);
//int getanzahl();
//protected:
//int anzahl;
//class sphere *liste;

//std::set<class sphere> sphereset;

#include <cmath>
#include <stdio.h>
#include "quader.h"


//struct myclass {
//	  bool operator() (class sphere i,class sphere j) { return (i.z<j.z);}
//} myobject;

saeule::saeule(){
	anzahl = 0;	
	std::vector<class sphere> Zahlen(0);
//	printf("bla\n");
	Zahlen.reserve(10000);
//	Zahlen.resize(100000);
//	printf("bli\n");
//	std::set<class sphere> sphereset(0);
	
}

saeule::~saeule(){
	Zahlen.reserve(0);
//	delete Zahlen;
}

int saeule::getanzahl(){
	return anzahl;
}


/*
	routine to add an sphere to the „stack“
*/
void saeule::addeintrag(class sphere kugel){
//	std::vector<class sphere>& Zahlen = new std::vector<class sphere> ;
	anzahl++;
//	std::vector<class sphere> Zahlen(0);
	//std::vector<class sphere>* Zahlen();
	if((anzahl%10000)==1)
	{
		Zahlen.reserve(anzahl+10000);
		Zahlen.resize(anzahl+10000);
//		fprintf(stderr,"si: %d\tca: %d\n",Zahlen.size(),Zahlen.capacity());
	}
//	Zahlen.resize(anzahl+100000);
//	printf("si: %d\tca: %d\n",Zahlen.size(),Zahlen.capacity());
	Zahlen.at(anzahl-1) = kugel;
//	printf("bla\n");
//	std::sort(Zahlen.begin(), Zahlen.end(), myobject);
	int i;
	for(i=anzahl-1;((Zahlen[i]<Zahlen[i-1])&&(i>0));i--)
	{
		Zahlen[i]=Zahlen[i-1];
	}
	Zahlen[i]=kugel;
//	class sphere ende;
//	ende = Zahlen.at(anzahl-1);
//	printf("akt: ");
//	ende.show();
//	sphereset.insert(kugel);
//	anzahl++;	
}

double saeule::dropsphere(class sphere kugel){
//	printf("bla\n");
	kugel.z = collisiondetect(kugel);
//	zmax = kugel.z;
//	printf("bla%f\n",kugel.z);
	if(kugel.z<kugel.r)
		kugel.z = kugel.r;
	//printf("bla\n");
	addeintrag(kugel);
//	printf("bla\n");
	return kugel.z;
}


class sphere saeule::geteintrag(int i){
//	std::set<class sphere>::iterator iter;
//	iter= sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}

double distance_xy(class sphere k1, class sphere k2)
{
	return sqrt(pow((k1.x - k2.x),2) + pow((k1.y - k2.y),2));
}

double saeule::collisiondetect(class sphere kugel){
	int i;
	class sphere tmp;
	double zz=0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = anzahl - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(distance_xy(tmp,kugel)<(tmp.r+kugel.r)){
//			printf("bla\n");
			zz = sqrt( pow(kugel.r+tmp.r,2) - pow(kugel.x-tmp.x,2) - pow(kugel.y-tmp.y,2)) + tmp.z;
			i=0;
		}
	}
	return zz;
}


//		quader(int x, int y);
//		dropsphere(class sphere kugel);
//	protected:
//		class sphere ** saeulen;

double squader::dropsphere(class sphere kugel){
	if((kugel.x>=xmax)or(kugel.y>=ymax))
		return -1;
	if((kugel.x<0)or(kugel.y<0))
		return -1;
	kugel.z = saeulen[int(kugel.x)][int(kugel.y)].dropsphere(kugel);
	if(kugel.z > zmax)
		return -1;
	int x = int(kugel.x-kugel.r);
	int y = int(kugel.y-kugel.r);
	int xm= int(kugel.x+kugel.r);
	int ym = int(kugel.y+kugel.r);
	x = (x<0) ? 0 : x;
	y = (y<0) ? 0 : y;
	xm = (xm > xmax) ? int(xmax) : xm;
	ym = (ym > ymax) ? int(ymax) : ym;
	for(;x<xm;x++)
	{
		for(;y<ym;y++)
		{
			saeulen[x][y].addeintrag(kugel);
		}
	}
//	printf("bli\n");i
//	if(x > 0){
//		saeulen[x-1][y].addeintrag(kugel);
//		if(y > 0)
//			saeulen[x-1][y-1].addeintrag(kugel);
//		if(y < (ymax-1))
//			saeulen[x-1][y+1].addeintrag(kugel);
//	}
//	if(x < (xmax-1)){
//		saeulen[x+1][y].addeintrag(kugel);
//		if(y > 0)
//			saeulen[x+1][y-1].addeintrag(kugel);
//		if(y < (ymax-1))
//			saeulen[x+1][y+1].addeintrag(kugel);
//	}
//	if(y > 0)
//		saeulen[x][y-1].addeintrag(kugel);
//	if(y < (ymax-1))
//		saeulen[x][y+1].addeintrag(kugel);
	quantity++;
	if(z<kugel.z)
		z = kugel.z;
		zmax = z;
	return kugel.z;
}

squader::squader(int x, int y)
{
	xmax = x;
	ymax = y;
	zmax = -1;
	zmax = 20;
	quantity = 0;
	 saeulen = new saeule* [int(xmax+1)];
	 int i;
	 for(i=0;i<xmax;i++)
		 saeulen[i] = new saeule[int(ymax+1)];
//	printf("bla\n");
}

squader::~squader(){
	int i;
	for(i=0;i<=xmax;i++)
	{
		delete[] saeulen[i];
	}
	delete saeulen;
}



