#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
/*Montelo Paragogou kataloti - Master/Slave*/
// $nth means that it passes the nth itself, not a copy of the variable
void execute_task(int p, int &nth) {
	//cout << "Nth=" << nth << endl;
	//if (p<=nth) {
		/* To ekteloumeno task*/
		cout << "Child Process ["<<p 
		<<"] started"<< endl;
		usleep(p*100*1000);
		cout << "Child Process [" <<p
		<<"] ended" <<endl;
	//} else {
	//	cout << " Erroneous PID:" << p <<endl;
	//}
}
int main(void) {
	int nth;
	cout << "NP=?";
	cin >> nth;
	int pid[nth]={0}; // integer array "pid" of size nth
	int i=0;
	/*Polyteknopoiisi*/
	// create nth processes 
	for (i=0;i<nth;i++) {
		pid[i]=fork();
		if (pid[i]==0) break;
	}
	/*Empodizo ton master na ektelesei task*/
	// only child process can run this
	if (pid[i]==0) {
		execute_task(getpid()%getppid(),nth);
	} else {
	/*Master barrier*/
	//wait for all child proce to end
		for (i=0;i<nth;i++) 
		wait(NULL);
	}
	return 0;
}