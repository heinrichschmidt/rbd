#include <cmath>
#include <stdio.h>
#include "Quader.h"


Saeule::Saeule(){
	anzahl = 0;	
	std::vector<class Sphere> Zahlen(0);
	platz = 4;
	Zahlen.reserve(platz+2);
}

Saeule::~Saeule(){
	Zahlen.reserve(0);
}

int Saeule::getanzahl(){
	return anzahl;
}


	//routine to add an Sphere to the „stack“
void Saeule::addeintrag(class Sphere kugel){
	anzahl++;
	if((anzahl>=platz)or(anzahl==1))
	{
		platz*=platz;
		Zahlen.reserve(platz+2);
		Zahlen.resize(platz+2);
	}
	Zahlen.at(anzahl-1) = kugel;
	int i;
	for(i=anzahl-1;((Zahlen[i]<Zahlen[i-1])&&(i>0));i--)
	{
		Zahlen[i]=Zahlen[i-1];
	}
	Zahlen[i]=kugel;
}

double Saeule::dropSphere(class Sphere kugel){
	Sphere kugel_;
	kugel_ = kugel;
	kugel.setZ( collisiondetect(kugel) );
//	zmax = kugel.z;
//	printf("bla%f\n",kugel.z);
	if(kugel.getZ()<kugel.getR())
		kugel.setZ( kugel.getR() );
	//printf("bla\n");
//	addeintrag(kugel);
//	printf("bla\n");
	return kugel.getZ();
}


class Sphere Saeule::geteintrag(int i){
//	std::set<class Sphere>::iterator iter;
//	iter= Sphereset.end();
//	--iter;
//	return *iter;
	return Zahlen.at(i);
}

double distance_xy(class Sphere k1, class Sphere k2)
{
	return sqrt(pow((k1.getX() - k2.getX()),2) + pow((k1.getY() - k2.getY()),2));
}

double Saeule::collisiondetect(class Sphere kugel){
	int i,k;
	k=0;
	class Sphere tmp;
	double zz=0;
	double ztmp = 0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = anzahl - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(distance_xy(tmp,kugel)<(tmp.getR()+kugel.getR())){
//			printf("bla\n");
			ztmp = sqrt( pow(kugel.getR()+tmp.getR(),2) - pow(kugel.getX()-tmp.getX(),2) - pow(kugel.getY()-tmp.getY(),2)) + tmp.getZ();
			if(ztmp>zz)
				zz = ztmp;
			k++;
			
		}
	}
	return zz;
}



double Squader::dropSphere(class Sphere kugel){
	if((kugel.getX()>=xmax)or(kugel.getY()>=ymax))
		return -1;
	if((kugel.getX()<0)or(kugel.getY()<0))
		return -1;
	int x = int(kugel.getX()-kugel.getR())-1;
	int y = int(kugel.getY()-kugel.getR())-1;
	int xm= int(kugel.getX()+kugel.getR())+1;
	int ym = int(kugel.getY()+kugel.getR())+1;
	x = (x<0) ? 0 : x;
	y = (y<0) ? 0 : y;
	xm = (xm > xmax) ? int(xmax) : xm;
	ym = (ym > ymax) ? int(ymax) : ym;
	int ix,iy;
	double zz;
	kugel.setZ( 0 );

	for(ix=x;ix<=xm;ix++)
	{
		for(iy=y;iy<=ym;iy++)
		{
			zz = saeulen[ix][iy].dropSphere(kugel);
			if(zz > kugel.getZ())
			{
				kugel.setZ( zz );
				if(kugel.getZ() > zmax)
					return -1;
			}
		}
	}
	
	for(ix=x;ix<=xm;ix++)
	{
		for(iy=y;iy<=ym;iy++)
		{
			saeulen[ix][iy].addeintrag(kugel);
		}
	}
	
	filled_volume += 4*3.14159*pow(kugel.getR(),3)/3;
	quantity++;
	return kugel.getZ();
}

double Squader::get_fillfactor(){
	return filled_volume/(get_volume());
	
}

Squader::Squader(int x, int y)
{
	xmax = x;
	ymax = y;
	zmax = -1;
	zmax = (xmax+ymax)/2;
	quantity = 0;
	filled_volume = 0;
	 saeulen = new Saeule* [int(xmax+1)];
	 int i;
	 for(i=0;i<=xmax;i++)
		 saeulen[i] = new Saeule[int(ymax+1)];
//	printf("bla\n");
}

Squader::Squader(int x, int y, int z)
{
	xmax = x;
	ymax = y;
	zmax = z;
	quantity = 0;
	filled_volume = 0;
	 saeulen = new Saeule* [int(xmax+1)];
	 int i;
	 for(i=0;i<=xmax;i++)
		 saeulen[i] = new Saeule[int(ymax+1)];
//	printf("bla\n");
}
Squader::~Squader(){
	int i;
	for(i=0;i<=xmax;i++)
	{
		delete[] saeulen[i];
	}
	delete saeulen;
}



