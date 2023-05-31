#include <iostream>
#include <ctime>
#include "lineare.h"
using namespace std;

int main(int argc, char**argv) {
	//seed the random number generator based on the current time.
	srand(time(0));
	int n=0;
	//cout << argc <<endl;
	
	// assign the argument to n after converting to int
	if (argc==2) {
		n=stoi(argv[1]);
		//cout << "Using n="<<n<<endl;
		//exit(0);
	} else {
		cout << "Use: ./main [n_of_arrays]";
		exit(0);
	}
	//cout << " Dose n:";
	//cin >> n;
	for (int i=0;i<n;i++) {
	    // create 2d array 3x4
		double **a=init_a(3,4);
		a=fill_a(a,3,4,10,-3);
		encoder(a,3,4);
		cout << endl;
	}
	//encoder(mp,3,4);
	/* double *y=new double[3];
	int flag=felim(mp,3,4);
	y=backusb(mp,3,y);
	for (int i=0;i<3;i++) {
		cout << y[i] <<endl;
	}*/
	
	return 0;
}
