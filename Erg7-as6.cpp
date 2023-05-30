#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

// Semaphore is used to sync a parent and child process that share a shared memory segment
// used to manage a shared space by blocking or allowing access to a shared space

//  semaphore has a permit which allow a process to manage a shared space
// if the permit it taken from a process the count is decremented and no other process is allowed acces to that space

int main(void) {
	sem_t sem;
	int *shm;
	// shared memory
	shm=(int *)mmap(NULL,4,PROT_READ|PROT_WRITE,
				MAP_SHARED|MAP_ANONYMOUS,
				-1,0);
	// initializes a semaphore at the address of "sem", using 1 concurrent processes allowed to access, with a starting value of 1 
	sem_init(&sem,1,1); 
	int pid=fork();
	
	if (pid==0) {
	//Will block the child process until it acquires the semaphore.
	sem_wait(&sem);
		cout << "locked by child" << endl;
		*shm=3;	
	//child process releases the semaphore  
	sem_post(&sem);
		cout << "cf" << endl;
	} else {
		usleep(50*1000);
		sem_wait(&sem);
		cout << "lock parent" << endl;
		*shm=894;
		sem_post(&sem);
		cout << "pl" << endl;
		wait(NULL);
	  
	}
	return 0;
}
