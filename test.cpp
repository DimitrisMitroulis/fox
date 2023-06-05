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


int main(void) {


double mat[3][4]={{1.0 ,-1.0, 0.0, 1.0},
			          {0.0 ,1.0,  3.0, 2.0},
			          {1.0 ,1.0,  6.0, 2.0}};
			
// dynamically allocates memory for a 2D array mp using the new operator
// used to store the pointer references to the rows of the matrix above
double **mp=new double *[3];

for (int i=0;i<4;i++) {
		mp[i]=mat[i];
	}
	
int flag=felim(mp,3,4);