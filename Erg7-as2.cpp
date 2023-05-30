#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

int main(void) {
	int pid=fork();
	if (pid==0) {
		cout << "child pid=" << pid << endl;
		while (true) {
			cout << "."; fflush(stdout);
			usleep(40*1000);
		}
		//	cout << "Signal Stop received"
		//	<< endl;
		
	} else {
	    // after 5 sec parent sends SIGSTOP to child, prints "S"
		sleep(2);
		kill(pid,SIGSTOP);
		cout << "S" << fflush(stdout);
		
		// after 2 sec parent sends SIGCONT to child, prints "C"
		sleep(2);
		kill(pid,SIGCONT);
		cout << "C" <<fflush(stdout);
		
		// after 2 sec parent sends kills the child
		sleep(3);
		kill(pid,SIGTERM);
		wait(NULL);
	}
	return 0;
}