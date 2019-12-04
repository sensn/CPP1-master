// Lambdas.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <windows.h>
int hotStuff();

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
	}



	return 0;
}

int hotStuff() {
	//system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);   //SCROLLBAR REMOVE
	
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);         //Fullscreen Mode
	return 0;
	
}

