#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "sphere.h"
#include "quader.h"


//using namespace std;

double frand(void)
{
	return (rand()/RAND_MAX);
}

char *helptext ="\
-h         this helptext.\n\
-f number  desired filling factor\n\
\n\
\
\
\
";


int main(int argc, const char *argv[])
{	
	long nmax = 1000000;
	double fillf = 0.14;
//	if(argc>1)
//		fillf = atof(argv[1]);

	long i;
	bool randomBallisticDeposition = false;
	bool randomSequentialPacking   = false;

	for (i = 1; i < argc; i++) {

		/* Check for a switch (leading "-"). */

		if (argv[i][0] == '-') {

			/* Use the next character to decide what to do. */

			switch (argv[i][1]) {

				case '-':   

				case 'a':
//					a_value = atoi(argv[++i]);
					break;

				case 'b':
//					b_value = atof(argv[++i]);
					randomBallisticDeposition = true;
					break;

				case 'c':
//					c_value = argv[++i];
					break;
				case 's':
					randomSequentialPacking = true;
					break;
				case 'h':  
					printf("%s",helptext);
					return 1;
					break;

			}
		}
	}
	if(argc==1){
		printf("use -h for usage\n");
		return 1;
	}

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

	if(randomSequentialPacking)
	{

		class sphere k2;
		k2.r=0.5;

		/* initialize random seed */
		srand ( time(NULL) );

		int yborder = 20;
		int xborder = 20;
		int zborder = 20;
		class wquader test(xborder, yborder, zborder);
		
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
	}


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


