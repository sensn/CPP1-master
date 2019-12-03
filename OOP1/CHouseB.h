//#pragma once
//#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
//
//class House {
//private:
//	char* m_street = nullptr;
//	std::string m_city = "Initcity";
//	size_t m_width = 0;
//	size_t m_height = 0;
//
//	int yloc = rand() % 10;
//	int xloc = rand() % 200;
//	float lifespan = rand() % 15 + 25;
//public:
//
//
//	//Constructor
//	House();
//	//Overloaded-Parameterized Constructor
//	House(size_t t_height);
//	House(size_t t_height, size_t t_width);
//	House(int t_height, int t_width);
//	House(std::string t_city, size_t t_width, size_t t_height);
//	House(const char* t_street, std::string t_city, size_t t_width, size_t t_height);
//	//Destructor
//	~House();
//	//Getter-Setter 
//	char* GetStreet() { return this->m_street; }
//	std::string GetCity() { return this->m_city; }
//	size_t GetWidth() { return this->m_width; }
//	size_t GetHeight() { return this->m_height; }
//
//	void SetStreet(const char* t_street);
//	void SetCity(std::string t_city);
//	void SetWidth(size_t t_width);
//	void SetHeight(size_t t_height);
//
//	//Zum Anzeigen von den Werten
//	void Display();
//
//	//***Schneeflocke
//	void run();
//	void Update();
//	void DisplaySnowflake();
//	bool isDead();
//
//	//Kopierkonstruktor
//	House(House& const original);
//
//	//ü. Zuweisungsoperator
//	//House& operator=(House& const original);
//
//	bool operator == (const House& original) const { return m_city == original.m_city; }   // && id == s.id
//	bool operator != (const House& original) const { return !operator==(original); }
//
//	unsigned int id;  //for list of objects
//};
//
//#pragma once
