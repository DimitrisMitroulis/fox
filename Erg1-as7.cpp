#include <iostream>
using namespace std;
template<class T>
T **init_a(int n) {
	T **a=new double*[n];
	for (int i=0;i<n;i++) 
		a[i]=new T[n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			a[i][j]=(i==j)?1:0;
		}
	}
	return a;
}
template<class T>
void print_a(T **a,int n) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

int main(void) {
	int n;
	cout << "Dose n:";
	cin >> n;
	double **a,**b,**c;
	a=init_a<double>(n);
	print_a<double>(a,n);
	return 0;
}