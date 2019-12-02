#include <stdlib.h>
#include "CHouse.h"
#include "Input_Buffer_Events.hpp"
#include "windows.h"
#include <iostream>
#include <list>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//#include <stdafx>
#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <math.h>
#include <cmath>
#include <vector>


#define MAXCOL 101 
#define MAXROW 22

void setSine(char[MAXCOL][MAXROW], int);
void ShowConsoleCursor(bool showFlag);


#define PI 3.141592

using namespace std;
void plot(double value);
void sineV();
void sineH();

int main() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	system("pause");
	/*system("pause");
	sineV();
	system("pause");
	sineH();
	system("pause");*/

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//printf("columns: %d\n", columns);
	//printf("rows: %d\n", rows);

	ShowConsoleCursor(false);
	bool issnowing = true;

		//	input_Buffer_Events_main();
	const unsigned n = 5;                   //number of snowflakes
	//House* snow=new House[num];
	std::list<House*> listOfHouses;
	std::list<House*>::iterator it =listOfHouses.begin();

	for (int i = 0; i < n; i++) {
		House* p = new House(rows,columns);
		//p->id = 0;
		listOfHouses.push_back(p);   //ein element einfügen
	}
	//listOfHouses.insert(listOfHouses.begin(),p );

	

	for (auto v : listOfHouses){
		std::cout << v << "\n";
		v->SetCity("Vienna");
		v->Display();
	
		std::cout <<  "LIST\n";
}
	House* p = new House(rows, columns);
	p->SetCity("Vienna");
	it = listOfHouses.begin();
	listOfHouses.remove(*it);

	for (auto v : listOfHouses) {
		std::cout << v << "\n";
		//v->SetCity("Vienna");
		v->Display();

		std::cout << "LIST Now\n";
	}

	system("pause");
	vector <House*> elements;
	House* el = new House(rows, columns);
	//elements.assign(10, el);

	
	
	for (int i = 0; i < n; i++) {
		printf("I : %d\n", i);
		House* el = new House(rows, columns);
		elements.push_back(el);
	}
	int len = elements.size();
	printf("len %d\n", len);

 	for (int i = 0; i < len-3; i++) {
		printf("löschen %d\n", elements.size());
		delete elements[elements.size()-1];
		elements.erase(elements.end()-1);
		//elements.erase(elements.begin() + i);
		
	}
	
	for (auto v : elements) {
		std::cout << v << "\n";
		v->Display();
		std::cout << "VECTOR\n";
		
	}
	system("pause");

	while (issnowing) {

		system("cls");
		/*for (int i = 0; i < n; i++) {
			snow[i]->run();*/

		

		for (auto v : listOfHouses) {
			v->run();
        }
		it = listOfHouses.begin();
		while (it != listOfHouses.end())
		{
			if ((*it)->isDead()) {
				delete (*it);
				it = listOfHouses.erase(it);
				House* p = new House(rows, columns);
				//p->id = 0;
				listOfHouses.push_back(p);
				//it++;
			}
			else {
				//other_code_involving(*i);
				it++;
			}
			if (listOfHouses.size() == 0) {
				issnowing = false;
			}
		}

		Sleep(200);




	}
		
	
	puts("hzuhu");



	//House *myHouse = new House();
	//
	//myHouse[0].Display();
	////myHouse->Display();

	//House yourHouse("Sesamstrasse", "Fohnsdorf", 77, 99);
	//yourHouse.Display();


	//yourHouse.Display();
	std::string mys = "Sesam";
	
	
   char a[5]="fooo";
	const char array[] = "Hello world";
	

	const char* c = "hello";
	size_t objCount = 5;

	// allocates and constructs five objects:
	//House* ourHouse = new House[objCount]{ {1},{3,4},{mys,127,255},{array,mys,127,255},{"Direct Street",mys,127,255} };


	House* ourHouse = new House[5] { {(1)},{3,4},{mys,127,255},{a,mys,127,255},{"Direct Street",mys,127,255} };
	ourHouse++;
	ourHouse++;
	ourHouse->Display();
	// new []
	//delete[5]  ourHouse;
	
	// **************LIST THING

//	std::list<House*> listOfHouses;
//	std::list<House*>::iterator it;
//
//	House *p = new House(123);
//	p->id = 0;
//	listOfHouses.push_back(p);   //ein element einfügen
//	
//	//listOfHouses.insert(listOfHouses.begin(),p );
//
//	for (auto v : listOfHouses){
//		std::cout << v << "\n";
//		v->Display();
//		std::cout <<  "\n";
//}

	//******


	//printf("\x1b[38;2;255;100;0mTRUECOLOR\x1b[0m\n");

//	test();
	/*House* yourHouse[2];
	yourHouse[0] = new House();
	delete yourHouse[1];*/

	//delete [] ourHouse;

	//ourHouse[0].Display();
	

	
		
	//	for (size_t i = 0; i < objCount; i++) {
	//	//std::cout << "______________" << "House Number" << i<< std::endl;
	//	ourHouse[i].Display();
	//}
//		delete [] ourHouse;
		
		//delete yourHouse[0];
   //delete  yourHouse[0];
	    
	
	
	//ourHouse[0].Display();



//***______________
	//int n = 4; // dynamic size of the array;
	House** HouseArray = new House* [n];
	for (int i = 0; i != n; ++i)
	{
		HouseArray[i] = new House(13);
	}

	HouseArray[3]->Display();

	for (int i = 0; i != n; ++i)
	{
		delete HouseArray[i];
	}
	delete[] HouseArray;

	//test();
}



void sineV() {	
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	double x, y;   // radians
	int col, row;  // screen loacations
	for (x = -3.2; x < 6.4; x += 0.1) {
		y = sin(x);
		row = ((int)(x * 10)) + 32;   // cast into positive screen location
		col = ((int)(y * 30)) + 35;   // center this one
		printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n",row, col, rand() % 255, rand() % 255, rand() % 255, 0, 0, 0);
		//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n",col, row, rand() % 255, rand() % 255, rand() % 255, 0, 0, 0);
	}

	cin.get(); // wait
	}


void sineH() {
	char array[MAXCOL][MAXROW];
	int cycles = 1;
	setSine(array, cycles);

	for (int a = 0; a < MAXROW; a++)
	{

		for (int b = 0; b < MAXCOL; b++)
			cout << array[b][a];
		cout << endl;
	}

//	return 0;
}

void setSine(char array[MAXCOL][MAXROW], int cycles)
{
	for (int a = 0; a < MAXCOL; a++)
	{

		for (int b = 0; b < MAXROW; b++)
			array[a][b] = ' ';

	}


	for (int i = 0; i < MAXCOL; i++)
	{
		int X = 5 - (5.0 * sin(i * 2 * cycles * M_PI / MAXCOL));
		array[i][X] = '*';
	}

}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
