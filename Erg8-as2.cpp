//Determinant calculation of matrix n,n
#include <iostream>
#include <boost/chrono.hpp>
using namespace std;
//function to get cofactor of mat[p][q] in temp[][].n
// mat,temp -> 2d arrays
// p,q -> row, collumn of element for which the cofactor is calculated
// n -> row, collumns of array
void getCofactor(int **mat, int **temp, int p, int q, int n){
	int i=0,j=0;
	for (int row=0;row<n;row++) {
		for (int col=0;col<n;col++) {
			//Copy into temp the elements
			//which are not in given row,column
			if (row!=p && col!=q) {
				// temp is the matrix without row, collum of selected item
				temp[i][j++]=mat[row][col];
				
			// temp has to be n-1*n-1
			//row is filled so increase row index
			// reset col index
				if (j==n-1) {
					j=0;
					i++;
				}
			}
		}
	}
}
/*Recursive function to get det of matrix*/
int determinantOfMatrix(int **mat, int n) {
	int D=0;
	if (n==1) 
		return mat[0][0];
	int **temp=new int*[n]; // 2d "temp" array to store the cofactors
	
	// copy first row to temp
	for (int i=0;i<n;i++) 
		temp[i]=new int[n];
	
	int sign=1; // sign multiplier
	//iterate for each element of first row
	for (int f=0;f<n;f++) {
		getCofactor(mat,temp,0,f,n);
		D+=sign*mat[0][f]*determinantOfMatrix(temp,n-1);
		sign=-sign;
	}
	return D;
}
// function declaration
void adjoint(int **,int **, int);


//Function to calculate inverse
//returns false if singular matrix
bool inverse(int **a, float **inv,int n) {
	//find determinant
	int det=determinantOfMatrix(a,n);
	if (det==0) {
		cout << "Mi antistrepsimos matrix !" <<endl;
		return false;
	}
	// allocate memory for adj array
	int **adj;
	for (int i=0;i<n;i++) {
		adj=new int *[n];
	}
	for (int i=0;i<n;i++) {
		adj[i]=new int[n];
	}
	//find adjoint
	adjoint(a,adj,n);
	//find inverse
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			inv[i][j]=adj[i][j]/float(det);
		}
	}
	
	return true;
}

// print 2d array
void print_r(int **mat, int row, int col) {
	for (int i=0;i<row;i++) {
		for (int j=0;j<col;j++) {
			cout << mat[i][j] << " " ;
		}
		cout << endl;
	}
} 

// print 2d array of floats
void print_rf(float **mat, int row, int col) {
	for (int i=0;i<row;i++) { 
		for (int j=0;j<col;j++) {
			cout <<mat[i][j] << "  ";
		}
		cout << endl;
	}
}
//Adjoint
void adjoint(int **a, int **adj, int n) {
	if (n==1) {
		adj[0][0]=1;
		return;
	}
	int sign=1; int **temp;
	// allocate memory for temp matrix
	for (int i=0;i<n;i++) {
		temp=new int*[n];
	}
	for (int i=0;i<n;i++) {
		temp[i]=new int[n];
	}
	
	//Cofactor
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
		    // original, temp, row, collum, size
			getCofactor(a,temp,i,j,n);
			// if (i+j) sum is even sign = 1, else sign = -1
			sign=((i+j)%2==0)?1:-1;
			
			
			adj[j][i]=(sign)*
				determinantOfMatrix(temp,n-1);
		}
	}
	// de-allocate memory
	for (int i=0;i<n;i++) 
		delete []temp[i];

}

int main(void) {
	int mat[3][3]={{3,2,-4},
			{2,3,3},
			{5,-3,1}};
	
	// array of pointers with size 3
	int **mp=new int*[3];
	//assign each row of mat to corresponding element in mp
	for (int i=0;i<3;i++) {
		mp[i]=mat[i];
	}
	print_r(mp,3,3);
	cout << "|A|=" << determinantOfMatrix(mp,3) << endl;
	//Make a dynamic inverse array
	float **inv;
	
	// τι θελει να πει ο ποιητης
	// kanei allocate ena array of pointers(type float) of size 3
	// stores the memory address of the new array to the pointer
	for (int i=0;i<3;i++) {
		inv=new float*[3];
	}
	// creates 2d array 3x3
	for (int i=0;i<3;i++) {
		inv[i]=new float[3];
	}
	// measure excecution time
	boost::chrono::system_clock::time_point start,stop;
	// assign current timestamp to start variable
	start=boost::chrono::system_clock::now();
	
	inverse(mp,inv,3);
	print_rf(inv,3,3);
	
	//  calculates the duration between the start and stop 
	// converts it to nanoseconds using the duration_cast function
	stop=boost::chrono::system_clock::now();
	boost::chrono::nanoseconds res=
	boost::chrono::duration_cast
			<boost::chrono::nanoseconds>
					(stop-start);
	cout << "CT=" << res.count() <<" us" <<endl;
	return 0;
}