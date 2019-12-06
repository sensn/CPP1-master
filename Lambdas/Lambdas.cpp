// Lambdas.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <windows.h>
int hotStuff();
void odd_lambda();
void odd_func();


using namespace std;

int main()
{
	hotStuff();
	
	//lambda with explicit datatype
	{
		auto sum = [](int a, int b) {                          // nimmt nur diesen Datentyp werte
			return a + b;
		};
		cout << "Sum of two integers:" << sum(5, 6) << endl;
		sum(5, 6);
	}
	//generalized lamda
	{
		
		auto sum = [](auto a, auto b) {
			return a + b;
		};
		cout << "Sum(5,6) = " << sum(5, 6) << endl; // sum of two integers
		cout << "Sum(2.0,6.5) = " << sum(2.0, 6.5) << endl; // sum of two float numbers
		cout << "Sum((string(\"SoftwareTesting\"), string(\"help.com\")) = " << sum(string("SoftwareTesting"), string("help.com")) << endl; // sum of two strings
		cout << "Sum(7.5,7) = " << sum(7, 7.5) << endl; // sum of two strings
		cout << "Sum(0xffff,7) = " << sum(0xffff, 7.5) << endl; // sum of two strings
		cout << "Sum(0xffff,0B1111'0000'1010'0101) = " << sum(0xff, 0B1111'0000'1010'0101) << endl; // sum of two strings
		cout << "Sum(0xffff,0B1111'0000'1010'0101) = " << sum(046, 0B0'1) << endl; // sum of two strings          //046 Oktal Darstellung! dez 38!!
	}
	
	// lambda gleich mit Paraeter aufrufen
	{
		int n = [](int x, int y) { return x + y; }(8, 9);               //
		cout << n << endl;
	
		cout <<"D  "<< n << endl;
	}

	

	odd_lambda();
	odd_func();
	return 0;
}

void odd_lambda() {
	{
		// Create a vector object that contains 9 elements.
		vector<int> v;
		for (int i = 1; i < 10; ++i) {
			v.push_back(i);
		}

		// Count the number of even numbers in the vector by
		// using the for_each function and a lambda.
		int evenCount = 0;
		for_each(v.begin(), v.end(), [&evenCount](int n) {
			cout << n;
			if (n % 2 == 0) {
				cout << " is even " << endl;
				++evenCount;
			}
			else {
				cout << " is odd " << endl;
			}
			});

		// Print the count of even numbers to the console.
		cout << "There are " << evenCount
			<< " even numbers in the vector." << endl;
	}


}

class FunctorClass
{
public:
	// The required constructor for this example.
	explicit FunctorClass(int& evenCount)
		: m_evenCount(evenCount) { }

	// The function-call operator prints whether the number is
	// even or odd. If the number is even, this method updates
	// the counter.
	void operator()(int n) const {
		cout << n;

		if (n % 2 == 0) {
			cout << " is even " << endl;
			++m_evenCount;
		}
		else {
			cout << " is odd " << endl;
		}
	}

private:
	// Default assignment operator to silence warning C4512.
	FunctorClass& operator=(const FunctorClass&);

	int& m_evenCount; // the number of even variables in the vector.
};


void odd_func() {
	//The next example uses a function object instead of a lambda                    FUNCTORCLASS
	// Create a vector object that contains 9 elements.
	vector<int> v;
	for (int i = 1; i < 10; ++i) {
		v.push_back(i);
	}

	// Count the number of even numbers in the vector by
	// using the for_each function and a function object.
	int evenCount = 0;
	for_each(v.begin(), v.end(), FunctorClass(evenCount));

	// Print the count of even numbers to the console.
	cout << "There are " << evenCount
		<< " even numbers in the vector." << endl;
}

int hotStuff() {
	//system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);   //SCROLLBAR REMOVE
	
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);         //Fullscreen Mode
	return 0;
	
}

