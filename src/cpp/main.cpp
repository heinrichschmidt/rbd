#include <stdio.h>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include "sphere.h"
#include "quader.h"


#define SmallToBigRatioDenominator 10000

//using namespace std;

double frand(void)
{
	return (double(rand())/RAND_MAX);
}

char helptext[] ="\
-h         this helptext.\n\
-f number  desired filling factor\n\
-n number  number of desired spheres\n\
-s         use random sequential packing\n\
-b         use random-ballistic-deposition\n\
-x number  x-boundary\n\
-y number  y-boundary\n\
-z number  z-max boundary\n\
-p number  radius ratio for bidisperse\n\
-q number  ratio small to big sphere in bidisperse case\n\
-g	   gaussian distribution with sigma=3 or 1/3 and maximum at 1\n\
-c         power law distribution with r from 0 to 3.5\n\
"; /* remaining charakteres: adeijklmortuvw*/


double gauss(double x, double sigma)
{
//	double x = xx;
	if(x<=0)
		return 0;
	if(x<1)
		x = 1/x;
	
	return ( 1/(sigma*2.506628) ) * exp( -0.5*pow( (x-1)/sigma  ,2) );
	
}


int main(int argc, const char *argv[])
{	
	long nmax = 1000000;
	double fillf = 0.14;
//	if(argc>1)
//		fillf = atof(argv[1]);

	int yborder = 10;
	int xborder = 10;
	int zborder = 10;
	float smallToBigRatio = 0;
	float radiusRatio = 1;
	long i;
	bool randomBallisticDeposition = false;
	bool randomSequentialPacking   = false;
	bool gaussian = false;
	bool powerlaw = false;

	for (i = 1; i < argc; i++) {

		/* Check for a switch (leading "-"). */

		if (argv[i][0] == '-') {

			/* Use the next character to decide what to do. */

			switch (argv[i][1]) {

				case '-':   

				case 'n':
					nmax = atoi(argv[++i]);
//					printf();
					break;

				case 'b':
					randomBallisticDeposition = true;
					break;

				case 'f':
					fillf = atof(argv[++i]);
//					c_value = argv[++i];
					break;
				case 's':
					randomSequentialPacking = true;
					break;
				case 'g':
					gaussian = true;
					break;
				case 'c':
					powerlaw = true;
					break;
				case 'h':  
					printf("%s",helptext);
					return 1;
					break;
				case 'x':
					xborder = atoi(argv[++i]);
					break;
				case 'y':
					yborder = atoi(argv[++i]);
					break;
				case 'z':
					zborder = atoi(argv[++i]);
					break;
				case 'p':
					radiusRatio = atof(argv[++i]);
					break;
				case 'q':
					smallToBigRatio = int(SmallToBigRatioDenominator *atof(argv[++i]));
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
	if(randomBallisticDeposition)
	{
//		int nmax = 1000000;


		//1000000class sphere kugel(1,2,3,0.5);
		//kugelclass sphere k3(1,2.5,4,0.5);
		//k3class saeule test;
		//
		//testtest.dropsphere(kugel);
		//kugeltest.dropsphere(k3);
		//k3double bla;
		//blak3.z = test.collisiondetect(k3);
		//k3printf("z:%f\n",bla);
		//blak3.show();
		class sphere k2;
		k2.r=0.5;
		//
		
		//k2k2 = test.geteintrag(0);

		/* initialize random seed */
		//srand ( time(NULL) );
		struct timeval tv;
		gettimeofday(&tv, 0);
		srand(tv.tv_usec);

		double xmax = xborder;
		double ymax = yborder;
//		fprintf(stderr,"%lf,%lf",xmax,ymax);
		class squader test(xmax,ymax,zborder);
		int i;

		/*convert smallToBigRatio to a fraction*/
//		int numerator, denominator, sumND;
//		double num;
//		denominator = int(1/(modf (smallToBigRatio , &num)));
//		numerator = int(num) * denominator + 1;
//		sumND = numerator + denominator;
//		fprintf(stderr,"ratio small to big: %d/%d\n",numerator, denominator);

		int sumND = SmallToBigRatioDenominator+smallToBigRatio;
		for(i=0;i<nmax;i++)
		{
			//nmaxprintf("%d\n",i);
//			float smallToBigRatio = 0;
//			float radiusRatio = 1;
			if(gaussian)
			{
				bool tru = true;
				double tmpr;
				while(tru)
				{
					tmpr = (rand()%(100000))/10000.0;
					if(gauss(tmpr,1)>((rand()%10000)/10000.0))
					{
						tru = false;
						k2.r = tmpr;
					}
				}
			}else if(powerlaw)
			{
				bool tru = true;
				double alpha = 1.89; // paper: comet 81p/wild 2: the size distribution of finer (sub-10 mum) dust collected by the Stardust spacecraft
				double tmpr;
				double xmin = 0.1; //scale parameter for power law distribution
				while(tru)
				{
					tmpr = (rand()%(100000))/28571.428;

					if( ( ( ( alpha - 1 )/( xmin ) * pow( tmpr / xmin, -alpha )  ) > ((rand()%10000) / 10000.0) ) and ( tmpr > xmin ) ) 
					{
						tru = false;
						k2.r = tmpr;
					}
				}
			}else
			{
				k2.r = ((rand()%(sumND))<smallToBigRatio) ? (0.5*radiusRatio) : 0.5;
			}
//			fprintf(stderr,"r: %f\n",k2.r);
			k2.x = frand()*(xmax - 2 * k2.r)+k2.r;
			k2.y = frand()*(ymax - 2 * k2.r)+k2.r;
			//1000printf("bli\n");
			
			k2.z = test.dropsphere(k2);
			//printf("blo %f\n",k2.z);
			if(k2.z>0)
				k2.show();
		}
		double vkugeln = test.get_quantity()*4*3.14159*0.5*0.5*0.5/3;
		double volumen = test.get_volume();
		double ff = test.get_fillfactor();
		fprintf(stderr,"füllfaktor: %f\n",ff);

	}
	else if(randomSequentialPacking)
	{

		class sphere k2;
		k2.r=0.5;

		/* initialize random seed */
		srand ( time(NULL) );

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


