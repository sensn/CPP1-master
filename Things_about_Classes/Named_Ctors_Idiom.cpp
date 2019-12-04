#include <iostream>
class Fred {
public:
	// The create() methods are the "named constructors":
	static Fred* create() { return new Fred(); }
	static Fred* create(int i) { return new Fred(i); }
	static Fred* create(const Fred& fred) { return new Fred(fred); }
	// ...
	int age=5;


private:
	// The constructors themselves are private or protected:
	Fred();
	Fred(int i);
	Fred(const Fred& fred);
	// ...
};


Fred::Fred(int i) : age(i) {
	//this->age = i;

}


int  main() {
	Fred* p = Fred::create(55);
	// ...
	std::cout << p->age;


	delete p;
	// ...

}