#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int main(void) {
	int pid=0;
	int x=5;
	pid=fork();
	// child and parent runs async
	if (pid==0) {
		//child
		cout << "This is the child!" << endl;
		x=x+1; // the change is temp
		cout << "Child address="<< &x <<
		" x=" << x << endl;
	} else {
	    //parent
		cout << " This is the parent!" << endl;
		wait(NULL); // wait for child process 
		cout << "Parent address=" << &x
		<<" Parent x=" << x << endl;
	}
	return 0;
}
// not entirely sure why x = 5 in the parent process
// my guess is because the change is the "child branch"