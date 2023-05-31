#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "lineare.h"
using namespace std;

void loadf(int n,int tot) {
	double ***arr=new double**[tot];
	//double **p=&arr[0];
	 for (int i=0;i<tot;i++) {
		arr[i]=init_a(3,4);
	}
	// create object named "infile" of type "ifstream" to read the csv
	ifstream infile("eq.csv");
	
	int i=0;int j=0;int f=0;
	while (!infile.eof()) {
		string s;
		if (!getline(infile,s)) break;
		istringstream ss(s);
		//Edo einai oi eggrafes
		//cout << ss.str() << endl;
		while (ss) {
			string s;
			if (!getline(ss,s,',')) break;
			    // convert S to double, assign to corresponding place
				arr[f][i][j]=stod(s);
			j++;
			//cout << stod(s) << endl;
		}
		//EOL
		j=0;i++; if (i>n) {i=0;f++;}
		// break loop if all subarrays have been filled
		if (f==tot) break;
	}
	/*for (int i=0;i<n;i++) {
		encoder(arr[i],n,n+1);
		cout << "-----------------"<<endl;
	}*/
	/*Epilisi */
	for (int i=0;i<tot;i++) {
		cout << "--Solve System ["<<i<<"]--"<<endl;
	//1. Felim-backusb
	int flag=felim(arr[i],3,4);
	if (flag!=-1) {
		cout << "Adinato i apeires liseis" <<endl;
	} else {
		double *y=new double[3];
		y=backusb(arr[i],3,y);
		for (int i=0;i<3;i++) {
			cout << "Sol=" <<y[i] <<",";
		}
		cout << "------------------"<<endl;
	}//EOF sollution
	}
	
}
// takes cl argumemnts
int main(int argc, char ** argv) {
	// if one cl argument
	if (argc==2) {
		// load and process 3 arrays, integer value from argument (convert from string to int )
		loadf(3,stoi(argv[1]));
		
	} else {
		cout << "Usage ./decoder [n_of_arrays]";
	}
	//loadf(3,100);
	return 0;
}	