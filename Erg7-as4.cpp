#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

int main(void) {
    int x = 5;
	int pagesize=getpagesize(); // 4KB
	int *shm;
	cout << "Page size=" << pagesize << endl;
	// create a shared memory of size "pagesize"
	// The map() function maps the shared memory into the processes's address space
	// the resulting pointer 'smh' is cast to an int*
	shm=(int *)mmap(NULL,pagesize,PROT_READ|PROT_WRITE,	MAP_SHARED|MAP_ANONYMOUS,-1,0);
	
	// Starting address of memory region
	// size of memory to allocate
	// desired access permission PROT_READ: memory can be read, PROT_WRITE: can be written 
	// desired attributes MAP_SHARED: can be shared among processes, MAP_ANONYMOUS: no copy-on-write when someone else sharing the mapping writes on the shared mapping
	//mmap(NULL,pagesize,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	
	
	int pid=fork();
	// Child process
	if (pid==0) {
		// 15 is assigned to the memory location pointed by *shm
		*shm=15;
		shm++;
		*shm=20;

	
	// Parent process    
	} else { 
		wait(NULL);
		// after child is done, print what's contained in *shm memory
		cout << *shm << endl;
		shm++;
		cout << *shm << endl;
	    
	}
	return 0;
}