#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "lineare.h"
using namespace std;
int main(void) {
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
			if (f==0) {
				a[i][j]=stod(s);
			} else {
				b[i][j]=stod(s);
			}
			j++;
			//cout << stod(s) << endl;
		}
		//EOL
		j=0;i++; if (i>3) {i=0;f++;}
	}
	encoder(a,3,4);
	cout << "-----------------"<<endl;
	encoder(b,3,4);
}