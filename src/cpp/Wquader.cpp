//class Sphere geteintrag(int i);
//void addeintrag(class Sphere);
//int getanzahl();
//protected:
//int anzahl;
//class Sphere *liste;

//std::set<class Sphere> Sphereset;

#include <cmath>
#include <stdio.h>
#include "Quader.h"


struct myclass {
	  bool operator() (class Sphere i,class Sphere j) { return (i.getZ()<j.getZ());}
} myobject;

Ssaeule::Ssaeule(){
	anzahl = 0;	
	std::vector<class Sphere> Zahlen(0);
//	printf("bla\n");
	Zahlen.reserve(10000);
//	Zahlen.resize(100000);
//	printf("bli\n");
//	std::set<class Sphere> Sphereset(0);
}

Ssaeule::~Ssaeule(){
	Zahlen.~vector();
}

int Ssaeule::getanzahl(){
	return anzahl;
}

void Ssaeule::addeintrag(class Sphere kugel){
//	std::vector<class Sphere>& Zahlen = new std::vector<class Sphere> ;
	anzahl++;
//	std::vector<class Sphere> Zahlen(0);
	//std::vector<class Sphere>* Zahlen();
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
//	class Sphere ende;
//	ende = Zahlen.at(anzahl-1);
//	printf("akt: ");
//	ende.show();
//	Sphereset.insert(kugel);
//	anzahl++;	
}

double Ssaeule::dropSphere(class Sphere kugel){
//	printf("bla\n");
	kugel.setZ( collisiondetect(kugel) );
//	printf("bla%f\n",kugel.z);
	if(kugel.getZ()<kugel.getR())
		kugel.setZ( kugel.getR() );
	//printf("bla\n");
	addeintrag(kugel);
//	printf("bla\n");
	return kugel.getZ();
}


class Sphere Ssaeule::geteintrag(int i){
//	std::set<class Sphere>::iterator iter;
//	iter= Sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}

double wdistance_xy(class Sphere k1, class Sphere k2)
{
	return sqrt(pow((k1.getX() - k2.getX()),2) + pow((k1.getY() - k2.getY()),2));
}

double Ssaeule::collisiondetect(class Sphere kugel){
	int i;
	class Sphere tmp;
	double zz=0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = anzahl - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(wdistance_xy(tmp,kugel)<(tmp.getR()+kugel.getR())){
//			printf("bla\n");
			zz = sqrt( pow(kugel.getR()+tmp.getR(),2) - pow(kugel.getX()-tmp.getX(),2) - pow(kugel.getY()-tmp.getY(),2)) + tmp.getZ();
			i=0;
		}
	}
	return zz;
}


Subcubic::Subcubic(){
	quantity = 0;	
	std::vector<class Sphere> Zahlen(0);
//	printf("bla\n");
	Zahlen.reserve(1000);
//	Zahlen.resize(100000);
//	printf("bli\n");
//	std::set<class Sphere> Sphereset(0);
}

Subcubic::~Subcubic(){
	Zahlen.~vector();
}

/*int subcubic::getanzahl(){
	return anzahl;
}*/

/*void subcubic::addeintrag(class Sphere kugel){
//	std::vector<class Sphere>& Zahlen = new std::vector<class Sphere> ;
	anzahl++;
//	std::vector<class Sphere> Zahlen(0);
	//std::vector<class Sphere>* Zahlen();
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
//	class Sphere ende;
//	ende = Zahlen.at(anzahl-1);
//	printf("akt: ");
//	ende.show();
//	Sphereset.insert(kugel);
//	anzahl++;	
}
*/

/*
double subcubic::dropSphere(class Sphere kugel){
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
class Sphere subcubic::geteintrag(int i){
//	std::set<class Sphere>::iterator iter;
//	iter= Sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}
*/


/*
double subcubic::collisiondetect(class Sphere kugel){
	int i;
	class Sphere tmp;
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


class Sphere Subcubic::getentry(int i){
	class Sphere bla(1,2,3,4);
	return bla;
}

int Subcubic::get_quantity(){
	return quantity;
}

bool Subcubic::collisiondetect(class Sphere kugel){
	int i;
	class Sphere tmp;
	double zz=0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = quantity - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(wdistance_xy(tmp,kugel)<(tmp.getR()+kugel.getR())){
//			printf("bla\n");
			return true;
		}
	}
	return false;
}
void Subcubic::putSphere(class Sphere kugel){
//	std::vector<class Sphere>& Zahlen = new std::vector<class Sphere> ;
	quantity++;
//	std::vector<class Sphere> Zahlen(0);
	//std::vector<class Sphere>* Zahlen();
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
void Subcubic::addentry(class Sphere kugel){
}


//		quader(int x, int y);
//		dropSphere(class Sphere kugel);
//	protected:
//		class Sphere ** saeulen;

int Wquader::min(int a, int b){
	if(a<b)
		return a;
	return b;
}

int Wquader::max(int a, int b){
	if(a>b)
		return a;
	return b;
}


int Wquader::putSphere(class Sphere kugel){
	if((kugel.getX()>=xmax)or(kugel.getY()>=ymax)or(kugel.getZ()>=zmax))
		return -1;
	if((kugel.getX()<0)or(kugel.getY()<0)or(kugel.getZ()<0))
		return -1;
	int x = int(kugel.getX());
	int y = int(kugel.getY());
	int z = int(kugel.getZ());
	
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
					cubics[i][j][k].putSphere(kugel);
				}
			}
		}
	}
	quantity++;
	return 1;
}

double Wquader::dropSphere(class Sphere kugel){
	if((kugel.getX()>=xmax)or(kugel.getY()>=ymax))
		return -1;
	if((kugel.getX()<0)or(kugel.getY()<0))
		return -1;
	int x = int(kugel.getX());
	int y = int(kugel.getY());
	kugel.setZ( saeulen[int(kugel.getX())][int(kugel.getY())].dropSphere(kugel) );
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
	return kugel.getZ();
}

Wquader::Wquader(int x, int y, int z)
{
	xmax = x;
	ymax = y;
	zmax = z;
	quantity = 0;
//	printf("ble\n");
	saeulen = new Ssaeule* [int(xmax+0.5)];
	int i,j;
	for(i=0;i<xmax;i++)
		saeulen[i] = new Ssaeule[int(ymax+0.5)];

//	printf("blu\n");
	cubics = new Subcubic** [int(xmax+0.5)];
	for(i=0;i<xmax;i++)
	{
		cubics[i] = new Subcubic * [int(ymax+0.5)];
		for(j=0;j<ymax;j++)
			cubics[i][j] = new Subcubic [int(zmax+0.5)];
	}

//	printf("bla\n");
}

Wquader::~Wquader(){
	int i,j;
	for(i=0;i<xmax;i++)
		delete[] saeulen[i];
	
	delete saeulen;

	for(i=0;i<xmax;i++)
	{
		cubics[i] = new Subcubic * [int(ymax+0.5)];
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



