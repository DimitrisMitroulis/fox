#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int main(void) {
	int pid=0;
	int x=5;
	
	// creates child process
	pid=fork();
	// if child process
	if (pid==0) {
		cout << "This is the child!" << endl;
		for (int i=0;i<10;i++) {
			cout << ".";
			// flush the output stream
			fflush(stdout);
			// 50ms delay after each flush
			usleep(100*1000);
		}
	} else {
		cout << " This is the parent!" << endl;
		for (int i=0;i<10;i++) {
			cout << "#";
			fflush(stdout);
			usleep(50*1000);
		}
		// wait for child process
		wait(NULL);
		//parent
	}
	return 0;
}