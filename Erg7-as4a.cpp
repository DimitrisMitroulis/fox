#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>

using namespace std;
int main(void) {
	int *shm=new int[2]; // dynamically allocates an integer array of size 2 and assigns the memory address of the first element to the pointer shm.
	//int v[2]={0};
	//int *shm=v;
	int pagesize=getpagesize(); // 4KB
	shm=(int *)mmap(NULL,pagesize,PROT_READ|PROT_WRITE,	MAP_SHARED|MAP_ANONYMOUS,-1,0);
	int pid=fork();
	if (pid==0) {
		*shm=15;
		shm++;
		*shm=20;
	} else { 
		wait(NULL);
		cout << *shm << endl;
		shm++;
		cout << *shm << endl;
	}
	return 0;
}