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


struct myclass {
	  bool operator() (class sphere i,class sphere j) { return (i.z<j.z);}
} myobject;

ssaeule::ssaeule(){
	anzahl = 0;	
	std::vector<class sphere> Zahlen(0);
//	printf("bla\n");
	Zahlen.reserve(10000);
//	Zahlen.resize(100000);
//	printf("bli\n");
//	std::set<class sphere> sphereset(0);
}

ssaeule::~ssaeule(){
	Zahlen.~vector();
}

int ssaeule::getanzahl(){
	return anzahl;
}

void ssaeule::addeintrag(class sphere kugel){
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

double ssaeule::dropsphere(class sphere kugel){
//	printf("bla\n");
	kugel.z = collisiondetect(kugel);
//	printf("bla%f\n",kugel.z);
	if(kugel.z<kugel.r)
		kugel.z = kugel.r;
	//printf("bla\n");
	addeintrag(kugel);
//	printf("bla\n");
	return kugel.z;
}


class sphere ssaeule::geteintrag(int i){
//	std::set<class sphere>::iterator iter;
//	iter= sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}

double wdistance_xy(class sphere k1, class sphere k2)
{
	return sqrt(pow((k1.x - k2.x),2) + pow((k1.y - k2.y),2));
}

double ssaeule::collisiondetect(class sphere kugel){
	int i;
	class sphere tmp;
	double zz=0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = anzahl - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(wdistance_xy(tmp,kugel)<(tmp.r+kugel.r)){
//			printf("bla\n");
			zz = sqrt( pow(kugel.r+tmp.r,2) - pow(kugel.x-tmp.x,2) - pow(kugel.y-tmp.y,2)) + tmp.z;
			i=0;
		}
	}
	return zz;
}


subcubic::subcubic(){
	quantity = 0;	
	std::vector<class sphere> Zahlen(0);
//	printf("bla\n");
	Zahlen.reserve(1000);
//	Zahlen.resize(100000);
//	printf("bli\n");
//	std::set<class sphere> sphereset(0);
}

subcubic::~subcubic(){
	Zahlen.~vector();
}

/*int subcubic::getanzahl(){
	return anzahl;
}*/

/*void subcubic::addeintrag(class sphere kugel){
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
*/

/*
double subcubic::dropsphere(class sphere kugel){
//	printf("bla\n");
	kugel.z = collisiondetect(kugel);
//	printf("bla%f\n",kugel.z);
	if(kugel.z<kugel.r)
		kugel.z = kugel.r;
	//printf("bla\n");
	addeintrag(kugel);
//	printf("bla\n");
	return kugel.z;
}
*/

/*
class sphere subcubic::geteintrag(int i){
//	std::set<class sphere>::iterator iter;
//	iter= sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}
*/


/*
double subcubic::collisiondetect(class sphere kugel){
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
}*/


class sphere subcubic::getentry(int i){
	class sphere bla(1,2,3,4);
	return bla;
}

int subcubic::get_quantity(){
	return quantity;
}

bool subcubic::collisiondetect(class sphere kugel){
	int i;
	class sphere tmp;
	double zz=0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = quantity - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(wdistance_xy(tmp,kugel)<(tmp.r+kugel.r)){
//			printf("bla\n");
			return true;
		}
	}
	return false;
}
void subcubic::putsphere(class sphere kugel){
//	std::vector<class sphere>& Zahlen = new std::vector<class sphere> ;
	quantity++;
//	std::vector<class sphere> Zahlen(0);
	//std::vector<class sphere>* Zahlen();
	if((quantity%1000)==1)
	{
		Zahlen.reserve(quantity+1000);
		Zahlen.resize( quantity+1000);
//		fprintf(stderr,"si: %d\tca: %d\n",Zahlen.size(),Zahlen.capacity());
	}
//	Zahlen.resize(anzahl+100000);
//	printf("si: %d\tca: %d\n",Zahlen.size(),Zahlen.capacity());
	Zahlen.at(quantity-1) = kugel;
//	printf("bla\n");
//	std::sort(Zahlen.begin(), Zahlen.end(), myobject);
	int i;
	for(i=quantity-1;((Zahlen[i]<Zahlen[i-1])&&(i>0));i--)
	{
		Zahlen[i]=Zahlen[i-1];
	}
	Zahlen[i]=kugel;
}
void subcubic::addentry(class sphere kugel){
}


//		quader(int x, int y);
//		dropsphere(class sphere kugel);
//	protected:
//		class sphere ** saeulen;

int wquader::min(int a, int b){
	if(a<b)
		return a;
	return b;
}

int wquader::max(int a, int b){
	if(a>b)
		return a;
	return b;
}


int wquader::putsphere(class sphere kugel){
	if((kugel.x>=xmax)or(kugel.y>=ymax)or(kugel.z>=zmax))
		return -1;
	if((kugel.x<0)or(kugel.y<0)or(kugel.z<0))
		return -1;
	int x = int(kugel.x);
	int y = int(kugel.y);
	int z = int(kugel.z);
	
	if(cubics[x][y][z].collisiondetect(kugel))
	{
		return -1;
	}else
	{
		int i,j,k;
		for(i=max(x-1,0);i<=min(x+1,xmax-1);i++)
		{
			for(j=max(y-1,0);j<=min(y+1,ymax-1);j++)
			{
				for(k=max(z-1,0);k<=min(z+1,zmax-1);k++)
				{
					cubics[i][j][k].putsphere(kugel);
				}
			}
		}
	}
	quantity++;
	return 1;
}

double wquader::dropsphere(class sphere kugel){
	if((kugel.x>=xmax)or(kugel.y>=ymax))
		return -1;
	if((kugel.x<0)or(kugel.y<0))
		return -1;
	int x = int(kugel.x);
	int y = int(kugel.y);
	kugel.z = saeulen[int(kugel.x)][int(kugel.y)].dropsphere(kugel);
//	printf("bli\n");
	if(x > 0){
		saeulen[x-1][y].addeintrag(kugel);
		if(y > 0)
			saeulen[x-1][y-1].addeintrag(kugel);
		if(y < (ymax-1))
			saeulen[x-1][y+1].addeintrag(kugel);
	}
	if(x < (xmax-1)){
		saeulen[x+1][y].addeintrag(kugel);
		if(y > 0)
			saeulen[x+1][y-1].addeintrag(kugel);
		if(y < (ymax-1))
			saeulen[x+1][y+1].addeintrag(kugel);
	}
	if(y > 0)
		saeulen[x][y-1].addeintrag(kugel);
	if(y < (ymax-1))
		saeulen[x][y+1].addeintrag(kugel);
	quantity++;
//	if(z<kugel.z)
//		z = kugel.z;
	return kugel.z;
}

wquader::wquader(int x, int y, int z)
{
	xmax = x;
	ymax = y;
	zmax = z;
	quantity = 0;
//	printf("ble\n");
	saeulen = new ssaeule* [int(xmax+0.5)];
	int i,j;
	for(i=0;i<xmax;i++)
		saeulen[i] = new ssaeule[int(ymax+0.5)];

//	printf("blu\n");
	cubics = new subcubic** [int(xmax+0.5)];
	for(i=0;i<xmax;i++)
	{
		cubics[i] = new subcubic * [int(ymax+0.5)];
		for(j=0;j<ymax;j++)
			cubics[i][j] = new subcubic [int(zmax+0.5)];
	}

//	printf("bla\n");
}

wquader::~wquader(){
	int i,j;
	for(i=0;i<xmax;i++)
		delete[] saeulen[i];
	
	delete saeulen;

	for(i=0;i<xmax;i++)
	{
		cubics[i] = new subcubic * [int(ymax+0.5)];
		for(j=0;j<ymax;j++)
			delete[] cubics [i][j];
		delete[] cubics[i];
	}
	delete cubics;
}


//double wquader::get_volume()
//{
//	return (xmax*ymax*zmax);
//}
//
//int wquader::get_quantity()
//{
//	return quantity;
//}



