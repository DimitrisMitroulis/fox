#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
using namespace std;
int sum=0;
// object "m" of type mutex to sync access to resources
boost::mutex m;
void *mrun(int t, int *a) {
    // locks the mutex "m", the thread that excecutes this line will get exclusive access 
    // to the following code
	m.lock();
	// excecute first or second part of code
	if (t==1) {
		for (int i=0;i<10;i++) {
			a[i]=i;
			// sleep for 30 ms
			boost::this_thread::sleep_for(
			boost::chrono::milliseconds(300));
		}
		//Edo ekteleite to nima 1
	} else {
	    // read and print contents of "a" with a 290 ms delay, 5 times in total
		int count =0;
		while (true) {
			cout << "-- Read [" << count
				<< "]----" <<endl; 
			for (int i=0;i<10;i++) {
			cout << a[i] <<endl;
			}
			cout <<"------------------"<<endl;
			boost::this_thread::sleep_for(
			boost::chrono::milliseconds(290));
			count++;
			if (count >5) break;
		}
		//Edo ekteleite to nima 2
	}
	//unlocks the mutex, releasing exclusive access
	m.unlock();
}
int main(void) {
    // dynamically allocates an array of 10 integers
	int *a =new int[10];
	// Dinamikos tropos
	// create t1  thread, passes mrun function to run as an entry point along with arguments
	boost::thread *t1 = new boost::thread(mrun,1,a);
	boost::thread *t2 = new boost::thread(mrun,2,a);
	//boost::thread *t2 = new boost::thread(mrun,2,a);
	// wait for threads to finnish 
	t1->join();
	t2->join();
	cout << endl <<  std::flush;
}