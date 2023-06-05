
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

double **init_a(int n) {
	srand(time(0));
	double **a=new double*[n];
	for (int i=0;i<n;i++)
		a[i]=new double[n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			a[i][j]=rand()/(RAND_MAX*1.0);
		}
	}
	return a;
}

double **enlarge(double **a, int n, int m) {
	if (m<=n) 
		return a;
	else {
		//assigns the newly allocated memory block back to the variable a. This ensures that the variable a now points to the resized memory block, which can hold m elements of type double *
		a=(double **)realloc(a,sizeof(double *)*m);
		for (int i=0;i<m;i++) {
			a[i]=(double *)realloc(a[i],sizeof(double)*m);
		}
	}
	for (int i=n;i<m;i++) {
		for (int j=0;j<m;j++) {
			a[i][j]=1.0;
		}
	}
	return a;
}

void print_a(double **b, int n) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout << fixed << setprecision(1) << b[i][j] << "\t";
		}
		cout << endl;
	}
	return ;
}


int main(void) {
	int n;
	cout << "ΞΟΟΞ΅ n:";
	cin >> n;
	double **p;
	p=init_a(n);
	p=enlarge(p,n,n+2);
	print_a(p,n+2);
	return 0;
}