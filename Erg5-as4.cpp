#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(void) {
	int status;
	unsigned int pid;
	if ((pid=fork())<0) { // forks current process and assigns child id to pid
		cout << "Fork error" <<endl;
		exit(1);
	}
	/*Child*/
	if (pid==0) {
	 cout << " ------ In child ---" << endl;
	 cout << "Child pid=" << getpid() <<","
	 	<<"Parent pid=" << getppid() << endl;	
	 //sleep(1000);
	 exit(33);
	} else {
	/*Parent*/
		//sleep(1);
		cout << " ---- In Parent ---" << endl;
		cout << "Parent pid=" << getpid() <<endl;
		pid=wait(&status); // wait for child process to complete and retrieve exit status
		//Check whether child process exited normally
		// WIFEXITED() checks if child process exited normally.
		if (WIFEXITED(status)) {
			cout << "Process[" << pid <<"]="
			<< "exited with status=" << 
			WEXITSTATUS(status)
			<<endl;
		}
	}
}