#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	// create object "fp" of type ofstream
	ofstream fp;
	// opens file in write mode
	fp.open("example.txt");
	//if successfully opened
	if (fp.is_open()) {
		// writes these lines to the file
		fp << "This is first line" << endl;
		fp << " This is second line" << endl;
		// closes file
		fp.close();
	} else {
		// print error 
		cerr << " Error opening file "<< endl;
	}
	return 0;
}