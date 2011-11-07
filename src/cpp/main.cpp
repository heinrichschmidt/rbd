#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "sphere.h"
#include "wquader.h"


//using namespace std;

double frand(void)
{
	return (rand()/RAND_MAX);
}


int main(int argc, const char *argv[])
{	
	long nmax = 1000000000;
	double fillf = 0.15;
	if(argc>1)
		fillf = atof(argv[1]);



//	class sphere kugel(1,2,3,0.5);
//	class sphere k3(1,2.5,4,0.5);
//	class saeule test;
//
//	test.dropsphere(kugel);
//	test.dropsphere(k3);
//	double bla;
//	k3.z = test.collisiondetect(k3);
//	fprintf(stderr,"z\n");
//	k3.show();
	class sphere k2;
	k2.r=0.5;
//
//	k2 = test.geteintrag(0);

	/* initialize random seed */
	srand ( time(NULL) );

	int yborder = 10;
	int xborder = 10;
	int zborder = 10;
	class wquader test(xborder, yborder, zborder);
	long i;
//	for(i=0;i<nmax;i++)
	double volumen = test.get_volume();
	double ff = 0;
	while(ff<fillf)
	{
//		printf("%d\n",i);
		k2.x = (frand()*(xborder-1)+0.5);
		k2.y = (frand()*(yborder-1)+0.5);
		k2.z = (frand()*(zborder-1)+0.5);
//		k2.x = ( (rand()%100000)/10000 * 3.9 + 1 );
//		k2.y = ( (rand()%100000)/10000 * 3.9 + 1 );
//		fprintf(stderr,"bli (%f, %f, %f)\n",k2.x,k2.y,k2.z);
		if(test.putsphere(k2)>0){
			k2.show();
			double vkugeln = test.get_quantity()*4*3.14159*0.5*0.5*0.5/3;
			ff = vkugeln/volumen;
		}
	}
	fprintf(stderr,"füllfaktor: %f\n",ff);
//	printf("x:%f\n",k2.x);
//	printf("y:%f\n",k2.y);
//	printf("z:%f\n",k2.z);



//	int MaxVec = 5;
//	vector<int> Zahlen(MaxVec);
//
//
//	cout << Zahlen.size() << " - " << Zahlen.capacity() << endl;
//	Zahlen[MaxVec+1] = 12; // Wird nicht aufgenommen
//	Zahlen.at(MaxVec+1) = 12; // Wird geprüft
//	Zahlen.reserve(20);  // Kapazität ist nun 20
//	cout << Zahlen.size() << " - " << Zahlen.capacity() << endl;
//	for(int i=0; i<MaxVec; i++)
//	{
//		Zahlen[i] = i;
//	}
//	Zahlen.resize(MaxVec+3); // Hier wird die Größe erhöht
//	Zahlen[MaxVec+1] =12; // Nun passt es
//	cout << Zahlen.size() << " - " << Zahlen.capacity() << endl;

	return 0;
}


