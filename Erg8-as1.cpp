#include <iostream>
using namespace std;

// takes as argument 2d array and n,m dimensions and prints row-wise each elemets
void print_r(double **mat, int n, int m) {
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) {
			cout << mat[i][j]<< "  ";
		}
		cout << endl;
	}
}

//swapping two rows
// takes as argument: 2d array, n,m dimensions , index i,j of rows to be swapped
void swap_row(double **mat, int n, int m, int i, int j)
{
	cout << "Swapped rows " << i << "<->" << j << endl;
	for (int k=0;k<m;k++) {
		double temp=mat[i][k];
		mat[i][k]=mat[j][k];
		mat[j][k]=temp;
	}
}
// forward elimination
// gaussian elimination with partial pivoting
// takes 2d array and n,m dimensions
int felim(double **mat, int n, int m) {
	for (int k=0;k<n;k++) {
	    
	    //initialize max value and index of pivot
		int i_max=k;
		int v_max=mat[i_max][k];
		
		//find the greatest amplitude for pivot if 
		for (int i=k+1;i<n;i++) {
			if (abs(mat[i][k])>v_max) {
				v_max=mat[i][k],i_max=i;
			}
		}
		// if a principal diagonal element is zero,
		// it denotes that matrix is singular
		// and will lead to a division by zero later
		if (!mat[k][i_max]) {
			return k;
		}
		/*swap the  greatest value row with current
		row*/
		if (i_max!=k) {
			swap_row(mat,n,m,k,i_max);
		}
		/*factor f to set current row kth element
		to 0 and remaining column to 0*/
		for (int i=k+1;i<n;i++) {
			double f=mat[i][k]/mat[k][k];
			/*subtract fth multiple of corr. kth
			row element*/
			for (int j=k+1;j<m;j++) {
				mat[i][j]-=mat[k][j]*f;
			}
			//filling the row triangular with 0
			mat[i][k]=0;
		}
	}
	return -1;
}
//function to calculate values of uknowns
// returns pointer of type double
// assumes the matrix is upper triang
double *backsub(double **mat, int n, double *y) {
	/*start calculation of last eq back to first*/
	for (int i=n-1;i>=0;i--) {
	//start with the rhs of eq.
	//set y to the "result"
		y[i]=mat[i][n];
	//Initialize j to i+1 since matrix is upper triang.
		for (int j=i+1;j<n;j++) {
			cout <<"(" << i <<"," <<j <<")"<<",";
			/*subtract all the lhs values
			except the coefficient of the variabl
			whose value is being calculated*/
			y[i]-=mat[i][j]*y[j];
		}
		cout << endl;
		/*divide the rhs coeff */
		y[i]=y[i]/mat[i][i];
	}	
	return y;
}
int main(void) {
	/*double mat[3][4]={{3.0,2.0,-4.0,3.0},
			{2.0,3.0,3.0,15.0},
			{5.0,-3.0,1.0,14.0}};
	*/
	//Infinite sollutions
	/*double mat[3][4]={{1.0,1.0,-1.0,3.0},
			{0.0,1.0,-3.0,0.0},
			{2.0,-1.0,7.0,6.0}};*/		
	//Inconsistent system
	double mat[3][4]={{1.0 ,-1.0, 0.0, 1.0},
			          {0.0 ,1.0,  3.0, 2.0},
			          {1.0 ,1.0,  6.0, 2.0}};
			
	// dynamically allocates memory for a 2D array mp using the new operator
	// used to store the pointer references to the rows of the matrix above
	double **mp=new double *[3];
	
	for (int i=0;i<4;i++) {
		mp[i]=mat[i];
	}
	
	// to store results, prints array
	double *y=new double[3];
	print_r(mp,3,4);
	/*GEL*/
	//1. Felim
	// transforms to row-echelon form(bottlom left is 0s)
	int flag=felim(mp,3,4);
	// inf solutions or inconsistent
	if (flag!=-1) {
		//infinitely many sollutions or inconsistent
		cout << "Apeires liseis i adinato" << endl;
		if (mat[flag][3]) {
			cout << "Adinato sistima" <<endl;
		} else {
			cout << "Apeires liseis" << endl;
		}
	// unique solution, calc backsub, print solutions
	} else {
		print_r(mp,3,4);
		y=backsub(mp,3,y);
		cout << "------------------------"<< endl;
		cout  << "Sollution:" << endl;
		cout << "------------------------"<<endl;
		for (int i=0;i<3;i++) 
			cout << y[i] <<endl;
	}
	return 0;
}