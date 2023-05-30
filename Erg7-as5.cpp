#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;
int main(void) {
	int shmid;
	key_t key=1010; // The key used to access the shared memory segment.
	int *shm;
	//request from system shared memory of size 4 bytes, create if not exists
	 
	// key is a unique identifier
	// size of shared memory 
	// create if not exists
	// specifies permissions of the shared memory 0666: read/write permissions
	// shmid holds the identifier of the memory segment
	shmid=shmget(key,4,IPC_CREAT|0666);
	
	cout << "SHMID=" << shmid <<endl;
	int pid=fork();
	// use shmat to attach a shared memory segment to the address space of a calling process
	// identifier of the shared memory segment
	// Null: the system decides automatically where the segment will start and be placed
	// flags arguments 0: no specific flags
	shm=(int *)shmat(shmid,NULL,0); // cast to (int *)
	
	if (pid==0) {
		cout << "Child var=" << *shm << endl;
		*shm=10;
	} else { 
		wait(NULL);
		cout << "Parent var=" << *shm << endl;
		// memory segment to control
		// command to execute IPC_RMID: remove selected space(de-allocate)
		// optional arguments
		shmctl(shmid,IPC_RMID,NULL);
	}
	
}