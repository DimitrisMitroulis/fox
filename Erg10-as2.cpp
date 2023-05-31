#include <iostream>
using namespace std;
// namespace is a mechanism that allows you to organize group related name, preventing name conficts
// improves modularity and organization
// similar to classes
namespace test {
// class "MyClass"
class MyClass {
	// public members/functions
	public:
		int a;
		void print_a() {
			cout << a;
		}
		// define constructors of class
		MyClass() { a=0;} // Calls the default constructor, sets x.a to 0
		MyClass(int my_a) {a=my_a;} // calls this constructor, with arguments
};
}
int main(void) {
	//Statikos tropos klisis
	test::MyClass x(3);
	cout << x.a << endl;
	x.print_a();
	//Dinamikos tropos klisis
	// allocates memory for y instance of class, prints a using y-> a
	test::MyClass *y=new test::MyClass(3);
	cout << y->a << endl;
	// Invokes the print_a()  function
	y->print_a();
}


// Static allocation:
// memory is allocated at compile time(on stack)
// objects lifetime is automatically managed (destroyed when out of scope)
// no need to explicitly deallocate


// Dynamic allocation:
// memory allocated at runtime
// lifetime is managed manually 
// control the lifetime, exists beyond scope



