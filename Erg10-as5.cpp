#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
using namespace std;
void parallel_write(int num, int *a) {
	cout << "Thread num=" <<num << endl;
	a[num]=num;
}
void parallel_read(int num, int *a) {
	cout << a[num] << endl;
}

int main(void) {
    // variable "tg" to manage threads
	boost::thread_group tg;
	int n;
	cout << "Dose n:";
	cin >> n;
	// create array of size n
	int *a=new int[n];
	// create n threads, sets parallel_write as entrypoint
	for (int i=0;i<n;i++) {
		tg.create_thread(boost::bind
		(parallel_write,i,a));
	}
	// waits for all the threads in the thread group tg to complete their execution
	tg.join_all();
	
	// create n threads, sets parallel_read as entrypoint
	for (int i=0;i<n;i++) {
		tg.create_thread(boost::bind
		(parallel_read,i,a));
	}
	tg.join_all();
	//for (int i=0;i<n;i++) {
	//	cout << a[i] << endl;
	//}
}