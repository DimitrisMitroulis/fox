
// takes 2d array of size nxm
// fills the array with random float points within range b, c
double **fill_a(double **a, int n,int m, int b, int c) {
	//srand(time(0));
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
		a[i][j]=(rand()/(RAND_MAX*1.0))*b +(c*1.0);
		}
	}
	return a;
}

// takes 2d array of size nxm, endoes it's elements 
void encoder(double **mat, int n, int m) {
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) {
			// if not the last element
			if (j!=(m-1)) {
			// prints mat[i][j] with 2 floating point precision
			cout << setprecision(2)<< mat[i][j]<< ",";
			} else {
			cout << mat[i][j];
			}
		}
		cout << endl;
	}
}