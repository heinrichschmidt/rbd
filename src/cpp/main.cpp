#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "sphere.h"
#include "quader.h"


//using namespace std;

int main(int argc, const char *argv[])
{
	int nmax = 1000000;


//	class sphere kugel(1,2,3,0.5);
//	class sphere k3(1,2.5,4,0.5);
//	class saeule test;
//
//	test.dropsphere(kugel);
//	test.dropsphere(k3);
//	double bla;
//	k3.z = test.collisiondetect(k3);
//	printf("z:%f\n",bla);
//	k3.show();
	class sphere k2;
	k2.r=0.5;
//
//	k2 = test.geteintrag(0);

	/* initialize random seed */
	srand ( time(NULL) );


	class quader test(10,10);
	int i;
	for(i=0;i<nmax;i++)
	{
//		printf("%d\n",i);
		k2.x = (rand()%10000)/1000.1;
		k2.y = (rand()%10000)/1000.1;
//		printf("bli\n");
		k2.z = test.dropsphere(k2);
//		printf("blo\n");
		k2.show();
	}

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


