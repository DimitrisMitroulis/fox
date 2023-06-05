#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main(void) {
	// create object "out" of type ostringstream
	ostringstream out;
	char ch='y';
	// output file stream
	ofstream fp;
	string data;
	float a,b,c;
	try {
		// opens the file "test.csv" in truncate mode for writing
		// (clears the contents of the file if it alread exists or creates new file)
		fp.open("test.csv",ios::trunc);
		while (ch!='n') {
			cout << "ΞΟΟΞ΅ a:";
			cin >> a;
			cout << "ΞΟΟΞ΅ b:";
			cin >> b;
			cout << "ΞΟΟΞ΅ c:";
			cin >> c;
			out << a <<","<<b <<","<<c;
			// gets sting stored in the "out obj"
			data=out.str();
			fp << data << endl;
			cout << "Write another record[y|n]?:";
			cin >> ch;
		}
		fp.close();
	} catch (...) {
		cerr << "Error writing file" << endl;
	}	
	return 0;
}