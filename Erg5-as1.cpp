#include <iostream>
#include <array>
using namespace std;

// auto &x accepts an array of any size
void print_array(auto &x) {
	int n=x.size(); // # of rows
	cout << n << endl; // prints rows
	int m=x[0].size(); // # of collumns
	cout << m << endl; // prints collumns
	
	// prints each element
	for (int i=0;i<n;i++) { 
		for (int j=0;j<m;j++) {
			cout << x[i][j] << "\t";
		}
		cout << endl;
	}
}
int main(void) {
	const size_t m=5;
	const size_t n=5;
	/*cout << "Dose m:";
	cin >> m;
	cout << "Dose n:";
	cin >> n;*/
	
	// initialize arary m*n and initialize each element to 1
	array<array<int, m>,n> a;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			a[i][j]=1;
		}
	}
	print_array(a);
	return 0;
}