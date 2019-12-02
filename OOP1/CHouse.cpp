#include "CHouse.h"
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
	this->yloc = rand()% t_height/4;
	this->xloc = rand()%t_width;
	this->lifespan = rand() % t_height;
	//std::cout << "P Konstruktor Int Int \n";
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
	Update();
	DisplaySnowflake();
}

void House::Update() {
	yloc += 1;
	lifespan -= 1;
}

bool House::isDead() {
	if (lifespan < 0.0) {
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
	printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dm*\x1b[0m\n", yloc,xloc ,rand()% 255, rand() % 255, rand() % 255,0 , 0,0);    //mit Pos
	//printf("\033[%d;%dH\x1b[38;2;%d;%d;%dm\x1b[48;2;%d;%d;%dmTRUECOLORS\x1b[0m\n", i, 7, r, g, b, r, g, b, i / 6);    //mit Pos

}
