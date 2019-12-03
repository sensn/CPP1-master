// bettertimer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>


#include <iostream>
#include <sstream>
#include "timer.h"
#include <chrono>
	using namespace std;
	using namespace chrono;

	int main()
	{
		auto start = high_resolution_clock::now();
		auto duration = [start]() {
			auto now = high_resolution_clock::now();
			auto msecs = duration_cast<milliseconds>(now - start).count();
			stringstream ss;
			ss << msecs / 1000.0;
			cout << "elapsed " << ss.str() << "s\t: ";
		};

		cout << "start" << endl;
		timer t(1ms);
		auto e1 = t.set_timeout(3s, [&]() { duration(); cout << "timeout 3s" << endl; });
		auto e2 = t.set_interval(1s, [&]() { duration(); cout << "interval 1s" << endl; });
		auto e3 = t.set_timeout(4s, [&]() { duration(); cout << "timeout 4s" << endl; });
		auto e4 = t.set_interval(2s, [&]() { duration(); cout << "interval 2s" << endl; });
		auto e5 = t.set_timeout(5s, [&]() { duration(); cout << "timeout that never happens" << endl; });
		e5->signal(); // cancel this timeout
		this_thread::sleep_for(5s);
		e4->signal(); // cancel this interval
		cout << "cancel interval 2" << endl;
		this_thread::sleep_for(5s);
		cout << "end" << endl;
	}


// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
