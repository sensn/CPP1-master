#include <iostream>
#include <cmath>               // To get std::sin() and std::cos()
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




//****
class Point {
public:
	static Point rectangular(float x, float y);      // Rectangular coord's
	static Point polar(float radius, float angle);   // Polar coordinates
	// These static methods are the so-called "named constructors"
	// ...
private:
	Point(float x, float y);     // Rectangular coordinates
	float x_, y_;
};
inline Point::Point(float x, float y)
	: x_(x), y_(y) { }
inline Point Point::rectangular(float x, float y)
{
	return Point(x, y);
}
inline Point Point::polar(float radius, float angle)
{
	return Point(radius * std::cos(angle), radius * std::sin(angle));
}


//**********
class Point1 {
public:
	//static Fred* create() { return new Fred(); }
	
	//static Point1 rectangular(float x, float y);      // Rectangular coord's
	static Point1* rectangular1(float x,float y) { return new Point1(x, y); }      // Rectangular coord's

	//static Point1 polar(float radius, float angle);   // Polar coordinates
	static Point1* polar1(float radius, float angle) { return new Point1(radius * std::cos(angle), radius * std::sin(angle)); }   // Polar coordinates
	// These static methods are the so-called "named constructors"
	// ...
	float x_, y_;
private:
	Point1(float x, float y);     // Rectangular coordinates
	
};


 Point1::Point1(float x, float y): x_(x), y_(y) { }
//inline Point1 Point1::rectangular(float x, float y)
//{
//	return Point1(x, y);
//}
//inline Point1 Point1::polar(float radius, float angle)
//{
//	return Point1(radius * std::cos(angle), radius * std::sin(angle));
//}



int  main() {
	Fred* p = Fred::create(55);
	// ...
	std::cout << p->age << std::endl;
	delete p;

	//Point p1 = Point::rectangular(5.7, 1.2);   // Obviously rectangular
	//Point p2 = Point::polar(5.7, 1.2);         // Obviously polar
	// ...
	Point1* p1 = Point1::rectangular1(5.7, 1.2);   // Obviously rectangular
	Point1* p2 = Point1::polar1(5.7, 1.2);         // Obviously polar
	std::cout << "POINT1  X " << p1->x_ << " Y " << p1->y_<<std::endl;
	std::cout << "POINT1  X " << p2->x_ << " Y " << p2->y_<<std::endl;
	delete p1;
	delete p2;

}