// TimerShipments.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
class Clock {
private:
	unsigned int time_in_seconds;

public:
	Clock(void) : time_in_seconds(0) {}
	Clock(unsigned int seconds) : time_in_seconds(seconds) {}

	void increase(void) {
		time_in_seconds++;
	}
	unsigned int time(void) {
		return time_in_seconds;
	}
};
class Shipment {
private:
	unsigned int shipping_date;
	unsigned int distance_in_seconds;
	bool         arrived;
	unsigned int recieved_date;
public:
	Shipment(unsigned int date, unsigned int dist_seconds)
		:shipping_date(date), distance_in_seconds(dist_seconds)
		, arrived(false), recieved_date(0)
	{}
	bool hasArrived(unsigned int time_in_seconds) {
		if (arrived) return true;

		if (time_in_seconds < shipping_date + distance_in_seconds)
			return false;

		recieved_date = time_in_seconds;
		arrived = true;
		return true;
	}
	unsigned int time_recieved(void) {
		return recieved_date;
	}
};
int main()
{
	// Create the clock
	Clock myClock;

	// Make some shipments
	Shipment myFirstShipment(myClock.time(), 5);
	Shipment mySecondShipment(myClock.time(), 7);

	// Pass the time
	while (!myFirstShipment.hasArrived(myClock.time())
		|| !mySecondShipment.hasArrived(myClock.time()))
	{
		myClock.increase();
	}

	// Results
	std::cout << "F Shipment @ " << myFirstShipment.time_recieved() << '\n';
	std::cout << "S Shipment @ " << mySecondShipment.time_recieved() << '\n';

	return 0;
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
