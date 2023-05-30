#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	unsigned int n;
	cout << "Dose n:";
	cin >> n;
	// Ftiaxnei vector me size n
	//vector<int> a(n);
	vector<int> a(n, 10);// initialize vector with size n filled with 10's
	
	// Iterator "p"
	vector<int>::iterator p;
	
	// Loop through vector and print items
	for (p=a.begin();p!=a.end();p++) {
		cout << *p << " ";
	}
	cout << endl;	
	return 0;
}

// Both vector and list manages a list of items
// Vector: 
// 1. Dynamic array
// 2. Elements are stored in a continuous block. Changes in front/back are efficient but in the middle requires large shifts
// 3. Automatic resizing when adding/removing elements
// 
// List:
// 1. Doubly-linked list container that stores elements as individual nodes linked to each other
// 2. It provides efficient insertion and deletion at both ends and in the middle.