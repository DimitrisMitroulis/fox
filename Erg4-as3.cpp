#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(void) {
	float a[3];
	ifstream fp;
	string data;
	try {
		//if the file was successfully opened
		fp.open("test.csv");
		if (!fp.good()) {
			cerr << " File not found !" <<endl;
			exit(-1);
		}
		while (true) {
			//getline(fp,data);
			//fp>> ss;
			//reads a single line of data from the file and stores it in the data string variable
			 fp >> data;
 			// checks if eol flag existss
			if (fp.eof()) break;
			// to treas string as stream
			istringstream ss(data);			 
			int count=0;
			// extract individual values from ss
			while (ss) {
			string s;
			// read until first ","
			if (!getline(ss,s,',')) break;
			// convert to string and store it in array
				//cout << s << endl;
				a[count]=stof(s);
				count++;
			}
			//cout << data <<endl;
		}
		fp.close();
	} catch (...) {
		cerr << "Error reading file !"<<endl;
	}
	for (int i=0;i<3;i++) {
		cout << a[i] << endl;
	}
	return 0;
}