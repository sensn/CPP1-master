#include <stdio.h> 
#include <stdlib.h> 

#include "CHouse.h"
#include <time.h>
#include <Windows.h>
#include<thread>
#include <chrono>
#include <thread>
#include "fast_hsv2rgb.h"

//Standardkonstruktor
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

House::House() {
	this->m_street = nullptr;
	this->m_city = "";
	this->m_width = 0;
	this->m_height = 0;
}

//überladener Konstruktor
House::House(const char* t_street, std::string t_city, size_t t_width, size_t t_height) {
	
	this->SetStreet(t_street);		//Char* Pointer
	this->m_city = t_city;
	this->m_width = t_width;
	this->m_height = t_height;
	std::cout << "K4\n";

	/*(t_width > 0) ? this->m_width = t_width : 0;
	(t_height > 0) ? this->m_height = t_width : 0;*/
}

House::House(std::string t_city, size_t t_width, size_t t_height) {

	//this->SetStreet(t_street);		//Char* Pointer
	this->m_city = t_city;
	this->m_width = t_width;
	this->m_height = t_height;
	std::cout << "K3\n";

	/*(t_width > 0) ? this->m_width = t_width : 0;
	(t_height > 0) ? this->m_height = t_width : 0;*/
}


House::House(size_t t_height, size_t t_width) {
	this->m_height = t_height;
	this->m_width = t_width;
	std::cout << "K2\n";
}
House::House(int t_height, int t_width) {
	
	this->yloc = (int)((RANDOM()* t_height)/4)+1;
	this->xloc = (int) (RANDOM() * t_width);
	this->lifespan = (int)((RANDOM()*  t_height) - yloc);
	this->m_height = t_height;
	this->m_width = t_width;
	this->thechar = (rand() & 90 + 33);
//	std::cout << "P Konstruktor Int Int \n";
}
House::House(int t_height, int t_width, char t_tchar) {

	this->yloc = (int)((RANDOM() * t_height) / 4) + 1;
	this->xloc = (RANDOM()*90)+33;
	//this->xloc = (int)(RANDOM() * t_width);
	this->lifespan = (int)((RANDOM() * t_height) - yloc);
	this->m_height = t_height;
	this->m_width = t_width;
	this->thechar = t_tchar;
	//	std::cout << "P Konstruktor Int Int \n";
}
House::House(int t_height, int t_width,char t_tchar,int t_xloc) {

	//this->yloc = (int)((RANDOM() * t_height) / 4) + 1+ yoffset;
	this->yloc = yoffset;

	this->xloc = t_xloc+xoffset;
	//this->xloc = (int)(RANDOM() * t_width);
	this->lifespan = (int)((RANDOM() * t_height) - yloc);
	this->m_height = t_height;
	this->m_width = t_width;
	this->thechar = t_tchar;
	//	std::cout << "P Konstruktor Int Int \n";
}





House::House(size_t t_height) {
	this->m_height = t_height;
	std::cout << "K1\n";
}


//Destruktor
House::~House() {
//	std::cout << "Destructor called\n";
	// Speicher von char* freigeben. 
	
	if (this->m_street){
		delete[] this->m_street;
		this->m_street = nullptr;
	}
}

void House::SetStreet(const char* t_street)
{
	//Step1: Ist in m_Name schon etwas drin
	if (this->m_street!= nullptr) {
		delete[] this->m_street;
		
	}
	size_t len;
	//Step2: Hat der Parameter einen Inhalt
	if (t_street != nullptr)
	{
		len = strlen(t_street);
		if (len > 0) {
			//Step3 : Speicher reservieren für Pointer
			this->m_street = new char[len + 1];
			
			//Step4: Überprüfung von m_Name & Speicherung in Member
			if (m_street != nullptr)
			{
				strncpy(this->m_street, t_street, len + 1);
			}
		}
	}
}

void House::SetCity(std::string t_city)
{
	if (t_city != "") {
		this->m_city = t_city;

	}
}

void House::SetWidth(size_t t_width)
{
	if (t_width > 0) {
		this->m_width = t_width;
	}

}

void House::SetHeight(size_t t_height)
{
	if (t_height > 0) {
		this->m_height = t_height;
	}
}


void House::run() {
	
	  //Milliseconds per quarternote
	//ms = 125;  //Millisecond per quarternote
	
	//ms = 1000;
	//dur = (ms / 1000) * CLOCKS_PER_SEC;
	//theend = (double)clock() + dur;

	//int mi = 0;

	//while (!mi) {
	//	begin = clock();
	//	//theend = (double)(clock() + dur);
	//	if ((double)begin > theend) {

	//		theend = (double)(clock() + dur);
	//		//theend = (double)clock() + dur + (dur * (swing));
	//		yloc += 1;
	//		lifespan -= 1;
	//		DisplaySnowflake();
	//		mi = 1;

	//	}
	//}

	
		//Update();
	


	//Sleep(599);

	while (isDead()==false) {
		////std::this_thread::sleep_for(2s);
		//int mi = 0;
	
		//begin = clock();
		////theend = (double)(clock() + dur);
		//if ((double)begin > theend) {

		//	theend = (double)(clock() + dur);
		//	//theend = (double)clock() + dur + (dur * (swing));
		
			yloc += 1;
			lifespan -= 1;
			
		
			DisplaySnowflake();
		

		//}
	//}
		
	}
	
}

void House::Update(void) {
	//Sleep(rand() % 300);
	
	//Sleep(rand() % 3000);

	// ms = ((60000.0 / (double)thebpm) / (double)4);
	//srand(time(0));
	yloc += 1;
	lifespan -= 1;
	//std::cout << lifespan;
	
	DisplaySnowflake();
	//isDead();
	}


bool House::isDead() {
	if (lifespan < 1.0) {
		
		printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm%c\x1b[0m\n", yloc, xloc, 12, 12, 12, 12, 12, 12,thechar);
	
		
		//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc, xloc, 0, 0, 0, 0, 0, 0);
		//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc-1, xloc, 0, 0, 0, 0, 0, 0);
		//Seed(rand() % 12);
		
		//this->yloc = (int)(RANDOM() * (m_height / 8))+ yoffset;
		this->yloc = yoffset;
		//Seed(rand() % 120);
		//this->xloc = (int)(RANDOM() * m_width);
		//Seed(rand() % 1200);
		lifespan = (int)((RANDOM() * m_height) - yloc);
		return true;
	}
	else {
		return false;
	}
}

void House::Display()
{
	std::cout << "Street....:" << (this->m_street ? this->m_street : "Street noch nicht vorhanden!") << std::endl;
	std::cout << "City....:" << ((this->m_city!="")? this->m_city : "City noch nicht vorhanden!") << std::endl;
	
	std::cout << "Width....:" << ((this->m_width >0)? this->m_width : 0) << std::endl;
	std::cout << "Height....:" << ((this->m_height>0)? this->m_height : 0) << std::endl;
}

void House::DisplaySnowflake()
{
	fast_hsv2rgb_32bit((yloc * 5)*6,255, 255, &r, &g, &b);
	//Sleep(20);
//	printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc, xloc, 255, 255, 255, 0, 0, 0);    //mit Pos
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc-1, xloc, 12, 12, 12, 12, 12, 12);
	
	
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc-1,xloc ,0,0,0,0, 0,0);    //mit Pos
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc,xloc ,rand()% 255, rand() % 255, rand() % 255,0 , 0,0);    //mit Pos
	
	printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm%c\x1b[0m\n", yloc-1, xloc, 12, 12, 12, 12, 12, 12,thechar);   //DELETE PREV
	printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm%c\x1b[0m\n", yloc,xloc ,r, g,b,0 , 0,0,thechar);    //mit Pos  //WRITE THIS
	printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm%c\x1b[0m\n", yoffset, xloc, r, g, b, 0, 0, 0, thechar);        // THE MESSAGE


	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm%c\x1b[0m\n", yloc,xloc ,rand()% 255, rand() % 255, rand() % 255,0 , 0,0,thechar);    //mit Pos
	
//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc,xloc ,rand()% 255, rand() % 255, rand() % 255,0 , 0,0);    //mit Pos

	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc,xloc , 255,  255, 255,0 , 0,0);    //mit Pos
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dmTRUECOLORS\x1b[0m\n", i, 7, r, g, b, r, g, b, i / 6);    //mit Pos
}


//void House::fetch_random_number(double& x) {
	
//}