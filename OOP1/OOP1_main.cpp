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
#include <ctime>
#include "myTimer.h"


#define MAXCOL 101 
#define MAXROW 22

void setSine(char[MAXCOL][MAXROW], int);
void ShowConsoleCursor(bool showFlag);
void wait_for_key_event();

#define PI 3.141592

using namespace std;
void plot(double value);
void sineV();
void sineH();


///******
DWORD WINAPI ThreadFunc(void* data);
void get_input_events();
extern int posX;
extern int posY;
extern int myMouseB;
extern int myKey;
extern int thebpm;
int thebpm = 150;
int posX = 0;
int posY = 0;
int myMouseB = 0;
int myKey = 0;


double ms;
double dur;
double swing = 0;
double theswing = 0.33;

////*****


#ifdef max
#undef max
#endif

using std::cin;
using std::endl;
using std::cerr;


int main() {
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);   //Playsequence in own Thread
	

	CONSOLE_SCREEN_BUFFER_INFO csbi;     //get wigth height of screenbuffer
	int columns, rows;

	//MyTimer* tim=new MyTimer(10);   //BPM

	//while (1) {
	//	if (tim->start())
	//		printf("500");

	//}


	//system("pause");
	wait_for_key_event();
	/*system("pause");
	sineV();
	system("pause");
	sineH();
	system("pause");*/

	//
	SetConsoleTitle("IT'S SNOWING IN THE SNOW, IT'S SNOWING IN THE SNOW");        

	//remove ScrollBars

	try {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(console, &csbi);
		COORD scrollbar = {
			csbi.srWindow.Right - csbi.srWindow.Left + 1,
			csbi.srWindow.Bottom - csbi.srWindow.Top + 1
		};

		if (console == 0) {
			throw 0;
		}
		else {
			SetConsoleScreenBufferSize(console, scrollbar);
		}
	}
	catch (...) {
		cerr << "Error removing scrollbar" << endl;
	}

	// End remove Scrollbars
      //ShowScrollBar(Console.WindowHandle, SB_BOTH, FALSE);
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
//	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);            // Get wigth height
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;                       // used to create SNowflake
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//printf("columns: %d\n", columns);
	//printf("rows: %d\n", rows);

	
	bool issnowing = true;

		//	input_Buffer_Events_main();
	const unsigned n = 500;                   //number of TimerThreads ->Objects  



	int ci = 0;
	//std::thread tw1[n];
	std::thread timerthread[n];
	
	//number of snowflakes
	//House* snow=new House[num];
	std::list<House*> listOfHouses;
	std::list<House*>::iterator it =listOfHouses.begin();
	std::list<MyTimer*> listOfTimers;
	std::list<MyTimer*>::iterator ittim = listOfTimers.begin();
	srand(time(NULL));
	double myrnd;
	for (int i = 0; i < n; i++) {
		House* p = new House(rows,columns);
		//p->id = 0;
		listOfHouses.push_back(p);   //ein element einfügen
		myrnd = (RANDOM() * 1000);
		MyTimer* tim = new MyTimer((int) myrnd, rows,columns);                            //MYTIMER INIT
		listOfTimers.push_back(tim);
		
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
	
	wait_for_key_event();
	vector <House*> elements;
	House* el = new House(rows, columns);
	
	//std::thread tw1 = el->runThread();
	//tw1.join();
	
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
	wait_for_key_event();
	system("cls");
	ShowConsoleCursor(false);
	ittim = listOfTimers.begin();
	for (int i = 0; i < n; i++) {
		
		timerthread[i] = (*ittim)->runThread();
	timerthread[i].detach();
			ittim++;
		}
	while (1) {
	
	/*	for (auto v : listOfTimers) {
		

			
				


		}*/
	
	}

	while (issnowing) {
		//system("cls");
		//system("cls");
		/*for (int i = 0; i < n; i++) {
			snow[i]->run();*/
		
		
		ci = 0;
		ittim = listOfTimers.begin();
		

		for (auto v : listOfHouses) {

			
			

			//	v->thebpm = rand()%180+30;
				//while (1) {
			
		//	while(1){

				it = listOfHouses.begin();
				ittim = listOfTimers.begin();
		//	while (ittim != listOfTimers.end()) {
				if ((*ittim)->thetime == 1) {
					printf("HUHU %d", (*ittim)->time_in_millis);
					ittim++;
					//it++;
					(*it)->Update();
					//v->Update();
				}
				else {
					ittim++;
					//printf("nono");
				}
				
			}
		
//		}


			////***
			//v->dur = rand()%99;
			//if (v->isDead() == 0) {
			//	tw1[ci] = v->runThread();
			//	tw1[ci].detach();
			//}
			////****


			//std::thread tw1 = v->runThread();
			
			//printf("THEBPM %d", v->thebpm);
			//std::this_thread::sleep_for(2s);

			
			//tw1.[ci]->swap();
		//tw1[ci].join();
		//	v->run();
		//	Sleep(300);
			//tw1[ci].join();
			ci++;
       // }
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
		
		//Sleep(200);


		
		
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

DWORD WINAPI ThreadFunc(void* data) {
	get_input_events();
	//playSequence(lib);
	// Do stuff.  This will be the first function called on the new thread.
	// When this function returns, the thread goes away.  See MSDN for more details.
	return 0;
}

void get_input_events() {
	while (1){
		do
		{

		} while (!input_Buffer_Events_main());
}
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

void setBpm(int updown) {
	(updown > 0) ? thebpm++ : thebpm--;

	ms = ((60000.0 / (double)thebpm) / (double)4);  //Milliseconds per quarternote
	//ms = 125;  //Millisecond per quarternote
	dur = (ms / 1000) * CLOCKS_PER_SEC;
	//printf("MILLIS PER QUATER:%f\n", ms);
	//printf("ms/Clocks :%f\n", dur);
	//SetPosition(0, 0);
	printf("\033[%d;%dH %d BPM",1,1, thebpm);
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dmBPMCHANGE\x1b[0m\n", 1, 1, rand() % 255, rand() % 255, rand() % 255, 0, 0, 0);
}

void wait_for_key_event() {

printf("Pressen sie irgendeinen Schlüssel zum fortfahren...");

	while(!myKey){}
	myKey = 0;
}