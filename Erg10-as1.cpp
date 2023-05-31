#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
using namespace std;
// will be excecuted on a seperate thread
void* mrun(){
    // print thread id
	cout << "TID=" <<boost::this_thread::get_id() << endl;
	// sleep for 3 secs
	boost::this_thread::sleep_for
		(boost::chrono::seconds(3));

}
int main(void) {
    // declare boost:thread object "t", passes function to costuctor
    // resulting in creating a new thread to run the function
	boost::thread t(mrun);
	// blocks excecution of main thread until thread completes its excecution
	t.join();
	return 0;
}