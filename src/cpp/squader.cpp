#include <cmath>
#include <stdio.h>
#include "quader.h"


saeule::saeule(){
	anzahl = 0;	
	std::vector<class sphere> Zahlen(0);
	Zahlen.reserve(10000);
}

saeule::~saeule(){
	Zahlen.reserve(0);
}

int saeule::getanzahl(){
	return anzahl;
}


	//routine to add an sphere to the „stack“
void saeule::addeintrag(class sphere kugel){
	anzahl++;
	if((anzahl%10000)==1)
	{
		Zahlen.reserve(anzahl+10000);
		Zahlen.resize(anzahl+10000);
	}
	Zahlen.at(anzahl-1) = kugel;
	int i;
	for(i=anzahl-1;((Zahlen[i]<Zahlen[i-1])&&(i>0));i--)
	{
		Zahlen[i]=Zahlen[i-1];
	}
	Zahlen[i]=kugel;
}

double saeule::dropsphere(class sphere kugel){
	kugel.z = collisiondetect(kugel);
//	zmax = kugel.z;
//	printf("bla%f\n",kugel.z);
	if(kugel.z<kugel.r)
		kugel.z = kugel.r;
	//printf("bla\n");
//	addeintrag(kugel);
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
	int i,k;
	k=0;
	class sphere tmp;
	double zz=0;
	double ztmp = 0;
//	printf("for %d: %f %f\n",anzahl,kugel.x,kugel.y);
	for(i = anzahl - 1;i >= 0; i--)
	{
		tmp = Zahlen.at(i);
//		printf("for %d: %f %f\n",i,tmp.x,tmp.y);
		if(distance_xy(tmp,kugel)<(tmp.r+kugel.r)){
//			printf("bla\n");
			ztmp = sqrt( pow(kugel.r+tmp.r,2) - pow(kugel.x-tmp.x,2) - pow(kugel.y-tmp.y,2)) + tmp.z;
			if(ztmp>zz)
				zz = ztmp;
			k++;
			
		}
	}
	return zz;
}



double squader::dropsphere(class sphere kugel){
	if((kugel.x>=xmax)or(kugel.y>=ymax))
		return -1;
	if((kugel.x<0)or(kugel.y<0))
		return -1;
	int x = int(kugel.x-kugel.r)-1;
	int y = int(kugel.y-kugel.r)-1;
	int xm= int(kugel.x+kugel.r)+1;
	int ym = int(kugel.y+kugel.r)+1;
	x = (x<0) ? 0 : x;
	y = (y<0) ? 0 : y;
	xm = (xm > xmax) ? int(xmax) : xm;
	ym = (ym > ymax) ? int(ymax) : ym;
	int ix,iy;
	double zz;
	kugel.z = 0;

	for(ix=x;ix<=xm;ix++)
	{
		for(iy=y;iy<=ym;iy++)
		{
			zz = saeulen[ix][iy].dropsphere(kugel);
			if(zz > kugel.z)
			{
				kugel.z = zz;
				if(kugel.z > zmax)
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
	
	filled_volume += 4*3.14159*pow(kugel.r,3)/3;
	quantity++;
	return kugel.z;
}

double squader::get_fillfactor(){
	return filled_volume/(get_volume());
	
}

squader::squader(int x, int y)
{
	xmax = x;
	ymax = y;
	zmax = -1;
	zmax = (xmax+ymax)/2;
	quantity = 0;
	filled_volume = 0;
	 saeulen = new saeule* [int(xmax+1)];
	 int i;
	 for(i=0;i<=xmax;i++)
		 saeulen[i] = new saeule[int(ymax+1)];
//	printf("bla\n");
}

squader::squader(int x, int y, int z)
{
	xmax = x;
	ymax = y;
	zmax = z;
	quantity = 0;
	filled_volume = 0;
	 saeulen = new saeule* [int(xmax+1)];
	 int i;
	 for(i=0;i<=xmax;i++)
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



