#pragma once
#include "Header_A1.h"
using namespace std;


const unsigned int max_entries = 10;

struct GebDat {
	int Tag;
	int Monat;
	int Jahr;
};

struct Student {
	char Vorname[50];
	char Nachname[50];
	char Schulstufe;
	GebDat* pGebdat;

};

/* std::cin.clear(); // Alle Fehlerflags löschen.
  std::cin.ignore(std::cin.rdbuf()->in_avail()); // Alles was noch verfügbar ist, ignorieren.*/

int main(int argc, char** argv) {
	/*short var1;
	long var2;
	cin >> var1 >> var2;
	cout << var1 << var2;
	cin.get();
	exit(0);*/
	
	//****
	
	struct Student studenten[max_entries] = { '\0' };

	int entry = 0;
	int button = 0;

	do {
		button = 0;
		menu(&button, &entry, studenten);
	} while (1);

}


void menu(int* button, int* entry, struct Student* studenten) {
	int validInput = 0;
	char chr;

	do {
		system("cls");

		switch (*button) {
		case 1:

			cout<<"(1) - Daten erfassen\n";
			validInput = 1;
			
			add_person(studenten, &entry);
			break;
		case 2:
			cout<<"(2) - Daten anzeigen\n";
			validInput = 1;
			cout<<"(a) Vorwaerts\n";
			cout<<"(b) Rueckwaerts\n";
			
			//char chr[1];

			//chr = getche();
			//cin.getline(chr, 1);
			fseek(stdin, 0, SEEK_END);
			cin.get(chr);
			cout<<("\n");


			show_person(studenten, &entry, &chr);
			break;
		case 3:
			cout<<"(3) - Suchen nach Student"<<"\n";

			cout<<"(a) nach Vornamen" << "\n";
			cout<<"(b) nach Schulstufe" << "\n";
			
			//chr = getche();
			fseek(stdin, 0, SEEK_END);
			cin.get(chr);
			cout << ("\n");

			find_student(studenten,&chr);
			validInput = 1;
			break;
		case 4:
			cout<<"(4) - Eintrag löschen";
			validInput = 1;

			delete_entry(studenten,&entry);
			
			break;
		case 5:
			cout << "(5) - BEENDEN";
			validInput = 1;


			exit(0);
			break;
		default:
			cout<<"Menueauswahl\n";
			
			cout<<"(1) - Daten erfassen\n";
			cout<<"(2) - Daten anzeigen\n";
			cout<<"(3) - Suchen nach Student\n";
			cout<<"(4) - Eintrag loeschen\n";
			cout<<"(5) - BEENDEN\n";
		}

		if (validInput == 0) {
			fseek(stdin, 0, SEEK_END);
			*button = (int)cin.get() - 48;
		}
		//	cout<<"%d", entry);
	} while (validInput == 0);
}

int add_person(struct Student* studenten, int** entry)
{
	for (int i = 0; i < (**entry); i++) {
		studenten++;
	}

	do
	{
		
		if (**entry > max_entries) {
			cout<<("\nAdressbuch voll! Drücken Sie eine Taste...\n\n");
			fseek(stdin, 0, SEEK_END);
			cin.get();
			break;
		}
		system("cls");
		cout << "\nEintrag Nr. " <<(**entry)<<"\n";
		cout<<("Vorname eingeben:");
		fseek(stdin, 0, SEEK_END);
		cin.clear();								// Alle Fehlerflags löschen.
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(studenten->Vorname,50);



		(**entry)++;
		if (studenten->Vorname[0] == '\0') {             //WENN Enter bei erster stelle im Vornamen feld Return
			(**entry)--;
			cout << "ENTRY:" << (**entry);
			return 0;
		}


		cout<<("Nachname eingeben:");
		fseek(stdin, 0, SEEK_END);
		cin.clear();								// Alle Fehlerflags löschen.
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(studenten->Nachname,50);
		
		cout << ("Schulstufe eingeben:");
		fseek(stdin, 0, SEEK_END);
		cin.clear();								// Alle Fehlerflags löschen.
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> studenten->Schulstufe;

		studenten->pGebdat = new GebDat();
	//	studenten->pGebdat = '\0';
		cout<<("Geburtsdatum eingeben TT MM JJJJ\n");
		
		//fseek(stdin, 0, SEEK_END);
		 cin.clear();								// Alle Fehlerflags löschen.
		 cin.ignore(std::cin.rdbuf()->in_avail());		// Alles was noch verfügbar ist, ignorieren.
		 cin >> studenten->pGebdat->Tag;
		 
		 cin.clear();								// Alle Fehlerflags löschen.
		 cin.ignore(std::cin.rdbuf()->in_avail());		// Alles was noch verfügbar ist, ignorieren.
		 cin >> studenten->pGebdat->Monat;
		 
		 cin.clear();								// Alle Fehlerflags löschen.
		 cin.ignore(std::cin.rdbuf()->in_avail());		// Alles was noch verfügbar ist, ignorieren.
		 cin >> studenten->pGebdat->Jahr;

		 studenten++;
	} while (studenten->Vorname[0] != 10);            //ENTER

	cout<<"ENTRY:"<<(**entry);

	return 0;
}

int show_person(struct Student* studenten, int** entry, char* chr) {

	switch (*chr) {
//*** Vorwärts printen ***
	case ('a'):
		for (int i = 0; i < (**entry); i++) {
			cout<<"\nEintrag Nummer "<< i << "\n";
			cout << "___________________________\n";
			cout<<"Vorname: "<< studenten->Vorname<<"\n";
			cout<<"Nachname: "<< studenten->Nachname<<"\n";
			cout<<"Nachname: "<< studenten->Schulstufe<<"\n";
			cout<<"Geburtsdatum: TAG " << studenten->pGebdat->Tag << "Monat " <<  studenten->pGebdat->Monat <<  "Jahr " << studenten->pGebdat->Jahr<< "\n";
			cout << "___________________________\n";
			cout << "***************************\n";

			studenten++;
		}
		break;
//*** Rückwärts printen ***

	case ('b'):
		for (int i = 0; i < (**entry); i++) {
			studenten++;
		}

		for (int i = (**entry); i > 0; i--) {
			studenten--;
			cout << "\nEintrag Nummer " << i << "\n";
			cout << "___________________________\n";
			cout << "Vorname: " << studenten->Vorname << "\n";
			cout << "Nachname: " << studenten->Nachname << "\n";
			cout << "Nachname: " << studenten->Schulstufe << "\n";
			cout << "Geburtsdatum: TAG " << studenten->pGebdat->Tag << "Monat " << studenten->pGebdat->Monat << "Jahr " << studenten->pGebdat->Jahr << "\n";
			cout << "___________________________\n";
			cout << "***************************\n";
		}
		break;

	default:break;
	}


	fseek(stdin, 0, SEEK_END);
	cin.get();
	return 0;
}

void find_student(struct Student* studenten, char* chr)
{
	int count = 0;
	int monat = 0;
	char f_nachname[50];
	char f_schulstufe;
	bool Entry = 0;
	
	switch (*chr) {
	case ('a'):
		cout << ("\nZu Suchenden Nachnamen eingeben\n");
		fseek(stdin, 0, SEEK_END);
		cin.getline(f_nachname, 50);
		/*cout << f_nachname;
		cout << studenten->Nachname;*/
		while (count < max_entries)                                       //solange werte in struct sind abfragen
		{
			count++;      //counter hier erhöhenum für ausgabe auch verwenden zu können
			
			                                                         //wenn übereinstimmung gefunden wird                                                                               //printen
			if (!strcmp(f_nachname, studenten->Nachname)) {                                                             //wenn übereinstimmung gefunden wird                                                                               //printen
				cout << "\nStudent gefunden" << studenten->Nachname << "\n";                                                //printen
				cout << "___________________________\n";
				cout << "Vorname: " << studenten->Vorname << "\n";
				cout << "Geb.:  " << studenten->pGebdat->Tag;
				cout << "." << studenten->pGebdat->Monat;
				cout << "." << studenten->pGebdat->Jahr << "\n";
				cout << "___________________________\n";
				//}

																							//nächster pointer
			}
			studenten++;
		}
			cout << ("\nDruecken Sie eine Taste\n");
			fseek(stdin, 0, SEEK_END);//zurück zum menü
			cin.get();
			break;

			//****
	case ('b'):
		cout << ("\nZu Suchende Schulstufe eingeben\n");
		fseek(stdin, 0, SEEK_END);
		cin >>f_schulstufe ;

		while (count < max_entries)                                       //solange werte in struct sind abfragen
		{
			count++;                                                                                  //counter hier erhöhenum für ausgabe auch verwenden zu können
			                                                           //wenn übereinstimmung gefunden wird                                                                               //printen
			if ((f_schulstufe == studenten->Schulstufe)) {                                                               //wenn übereinstimmung gefunden wird                                                                               //printen
				cout << "Student gefunden" << studenten->Nachname << "\n";                                                //printen
				cout << "___________________________\n";
				cout << "Vorname: " << studenten->Vorname << "\n";
				cout << "Geb.: " << studenten->pGebdat->Tag;
				cout << " " << studenten->pGebdat->Monat;
				cout << " " << studenten->pGebdat->Jahr << "\n";
				cout << "___________________________\n";
				//}
			}
				studenten++;                                                                                //nächster pointer
		}

			cout << ("\nDruecken Sie eine Taste\n");
			fseek(stdin, 0, SEEK_END);//zurück zum menü
			cin.get();


		break;
	default:break;
	}
}

void delete_entry(struct Student* studenten, int** entry) {
	int number;
	
	
	do {
		std::cout << "\nWelcher Eintrag soll geloescht werden\n";
		std::cin >> number;
	} while (!(number < max_entries && number >= 0));
	if (number < (**entry)) {
		for (int i = 0; i < number; i++) {
			studenten++;

		}
		//zur sicherheit zu überschreibende Felder 0 setzen.
		studenten->Vorname[0] = '\0';
		studenten->Nachname[0] = '\0';
		studenten->Schulstufe = '\0';
		studenten->pGebdat->Tag = '\0';
		studenten->pGebdat->Monat = '\0';
		studenten->pGebdat->Jahr = '\0';


		for (int i = number; i < (**entry) - 1; i++) {

			strcpy(studenten->Vorname, (studenten + 1)->Vorname);
			strcpy(studenten->Nachname, (studenten + 1)->Nachname);
			studenten->Schulstufe = (studenten + 1)->Schulstufe;
			studenten->pGebdat->Tag = (studenten + 1)->pGebdat->Tag;
			studenten->pGebdat->Monat = (studenten + 1)->pGebdat->Monat;
			studenten->pGebdat->Jahr = (studenten + 1)->pGebdat->Jahr;

			studenten++;
		}

		//Letzter eintrag löschen

		studenten->Vorname[0] = '\0';
		studenten->Nachname[0] = '\0';
		studenten->Schulstufe = '\0';
		studenten->pGebdat->Tag = '\0';
		studenten->pGebdat->Monat = '\0';
		studenten->pGebdat->Jahr = '\0';
		delete studenten->pGebdat;

		(**entry)--;

		std::cout << "Eintrag " << number << " wurde geloescht\n";
		std::cout << "Mit beliebiger Taste zum Menue...";										//zurück zum menü
		fseek(stdin, 0, SEEK_END);
		cin.get();
	}
	else {
		std::cout << "Keine Einträge vorhanden ";
		std::cout << "Mit beliebiger Taste zum Menue...";										//zurück zum menü
		fseek(stdin, 0, SEEK_END);
		cin.get();
	}


}