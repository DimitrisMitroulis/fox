#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// pipe is a for of interprocess communication (IPC) that allows communication between 2 processes
// It provides a unidirectional flow of data, where one process writes on one end called "write end" 
// and the other reads from the "read end"


// pipe() call returns 2 file descriptors representing the write and the read end
// pipe[0] -- pipe 
using namespace std;
int main(void) {
	int pid;
	int pipefd[2]; // create array named "pipefd" of length 2
	int v=0;
	/*try exception*/
	try {
		pipe(pipefd);// create pipe
		pid=fork();
	} catch(exception &e) {
		cout << e.what() <<endl; // e.what() returns a string that describes the exception
		exit(0);
	}
	// if child process
	if (pid==0) {
		for (int i=0;i<100;i++) {
			v=i;
			// write in the pipe 
			// write in the pipe[1] (write end)
			// send the address of &v (function expects a pointer in this parameter)
			// specifies the size of data being written
			write(pipefd[1],&v,sizeof(int));
		}
		// close pipe
		close(pipefd[1]);
	} else {
	    // Parent process
		while (1) {
		    // Read the value from the pipe
			if (read(pipefd[0],&v,sizeof(int))){
				cout << v <<endl;
				//sleep(1);
			} else { 
				cout << "-" << endl;
				break;
			}
		}
		wait(NULL);
	}	
	return 0;
}