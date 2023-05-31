#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
using namespace std;
// Thread library to create and join multiple threads.


int sum=0;

//Takes an int argument t and prints the current thread ID 
// (boost::this_thread::get_id()) and the value of t.
In the main function:
void *mrun(int t) {
	cout << "TID=" << boost::this_thread::get_id()<<
		",T=" << t <<endl;
}
int main(void) {
    // variable "start" of type boost::chrono::system_clock::time_point
	boost::chrono::system_clock::time_point start=
		boost::chrono::system_clock::now();
	
	// create threads
	boost::thread t1(mrun,1);
	boost::thread t2(mrun,2);
	
	// w8 to end
	t1.join();
	t2.join();
	cout << endl <<  std::flush;
	
    // variable "stop" 
    // calc time in nanoseconds
	boost::chrono::system_clock::time_point stop=
		boost::chrono::system_clock::now();
	boost::chrono::nanoseconds res=
		boost::chrono::duration_cast<
			boost::chrono::nanoseconds>
			(stop-start);
	cout << "Time=" << int(res.count()) 
			<< " ns" << endl;	
}