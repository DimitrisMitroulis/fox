#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;
int main(void) {
	int pid;
	// create 3 child processes
	for (int i=0;i<3;i++) {
		pid=fork();
		if (pid==0) break;
	}
	
	if (pid==0) {
		// child process
		// getpid() % getppid() calculates the remainder of the child process's ID divided by its parent process's ID.
		cout << "Child:" << getpid()%getppid() << endl; 
	} else {
	    // parent process
		cout << "Parent:" << getpid() << endl;
		// wait for 3 children processes
		for (int i=0;i<3;i++)
		wait(NULL);
	}
	return 0;
}