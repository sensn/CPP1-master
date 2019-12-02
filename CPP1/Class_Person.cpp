// Dateiname: PERSON1.CPP
// Dieses Beispiel zeigt eine einfache Implementierung der Klasse Person

///  / std:c++latest

#include "Header_Cpp1.h"

/*--- Klassenbeschreibung ---*/
using namespace std;

class Person
{
public:

	void setAlter(int einAlter);
	int getAlter();
	void updateAlter();

protected:
	char* name;
	int alter;
	float gehalt;
};
/*--- Implementierung ---*/
// Alter setzen
void Person::setAlter(int einAlter)
{
	alter = einAlter;
}
int Person::getAlter()
{
	return alter;
}
void Person::updateAlter()
{
	alter++;
}
/*--- Testprogramm ---*/
void Person_main()
{
	std::cout << "Hello, world!" << std::endl;
	// Objekt erzeugen
	Person Karl;
	// Attribut alter setzen
	Karl.setAlter(45);
	// Alter ausgeben
	cout << "Alter: " << Karl.getAlter() << "\n";
	// Karl wird älter
	Karl.updateAlter();
	// Alter ausgeben
	cout << "Alter: " << Karl.getAlter() << "\n";
}