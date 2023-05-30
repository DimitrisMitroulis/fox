#include <iostream>
#include <list>
using namespace std;
int main(void) {
	// Creates a list of integers
	list<int> l{1,2,3,4,5};
	
	// Adds elements to the (end) of the list
	l.push_back(6);
	l.push_front(8);
	
	// Iterate over the list using iterator
	list<int>::iterator p;
	for (p=l.begin();p!=l.end();p++) {
		*p+=1;
		cout << *p << " ";
	}
	
	// Calculate the sum of the elements on the list
	int sum=0;
	
	while (! l.empty()) {
		sum+=l.front(); //add the first element to the sum
		l.pop_front(); //  remove "pop" the first element
	}
	cout << "Sum=" << sum << endl;
}