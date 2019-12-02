#include"Header_Cpp1.h"

void ausgabe() {
	int zahl = 123;
	cout << "Der Wert der Zahl ist: " << zahl << ".\n";

	int z = 123;
	cout << dec << z << ' ' << oct << z << ' ' << hex << z;
	cout << "\n";

	zahl = 567;
	double real = 123.987;
	// --- Standard Ausgabe ---
	cout << "\n" << zahl << "\t" << real << "\n";
	// --- Formatierte Ausgabe ---
	cout << setw(8) << zahl << "\n";
	cout.setf(ios::fixed);
	cout << setw(8) << setfill('*') << setprecision(2) << real;
	cout << "\n";
}
int zahl = 123;

void eingabe() {
	float zahl;
	cout << "Geben Sie eine FließkommaZahl ein: ";
	cin >> zahl;
	cout << "Die eingegebene Zahl war: " << zahl<<endl;
	
}
void eingabe_string() {
	char name[20];
	cout << "Geben Sie Ihren Namen ein: ";
	cin >> name;	//!!Char Array length!
	cin.clear();                     //inputbuffer störungsbit löschen. für mehrere eingaben.
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Der eingegebene Name: " << name<<endl;
 }

void eingabe_string_getline() {
	char str[10];
	// --- Eingabe mit getline ---
	cout << "\nGeben Sie einen String ein: ";
	cin.getline(str, 10); // Es werden max. 9 Zeichen eingelesen!
	// --- Formatierte Ausgabe ---
	cout << "\nIhre Eingabe war " << str << endl;
}


void test_iota() {
	int numbers[10];

	std::iota(numbers, numbers + 10, 100);

	std::cout << "numbers:";
	for (int& i : numbers) {
		std::cout << ' ' << i;
		//i = i * 2;
	}
		/*for (int j = 0; j < 10; j++) {
			std::cout << ' ' << numbers[j];
		}
	*/
		
		std::cout << endl;

}

void vorfunc() {
	show(); // Für alle frei Parameter werden die
// Standardwerte verwendet.
	show(5); // erstes Argument explizit übergeben
	show(5, 7.8f); // erstes und zweites Arg. expl. übergeben
	show(5, 9.9f, 12L); // alle drei Argumente angegeben

}

void show(int erstes, float zweites, long drittes)
{
	cout << "Erstens: " << erstes << " Zweitens: "
		<< zweites << " Drittens: " << drittes << '\n';
}

void scope_main() {
	int zahl = 666;
	cout << "\n Global :" << ::zahl;
	cout << "\n Lokal :" << zahl;

}

void test_inline_func() {
	int i, x = 23, y = 77;
	i = MAX(x++, y++); // Seiteneffekte
	cout << "\nMAX: " << i;
	i = max(x++, y++); // Ok!
	cout << "\nmax: " << i;

	
}

inline int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void test_const() {
	const int size = 5;
	char ca[size];                                    //würde in C nicht gehen
	cout << "Die Groesse von ca: " << sizeof ca;
}

// enum Menü
enum liste
{
	datei = 1, edit, ansicht, fertig
};

void test_enum() {
	int wahl;
	liste ls;
	do
	{
		cout << "\nEingabe einer Nummer: (1..3 / 4=Ende):";
		cin >> wahl;
		ls = (liste)wahl;
		switch (ls)
		{
		case datei:
			cout << " Datei\n";
			break;
		case edit:
			cout << " Bearbeiten\n";
			break;
		case ansicht:
			cout << " Ansicht\n";
			break;
		case fertig:
			cout << " Ende\n";
			break;
		default:
			cout << " Ungültige Nummer!\n";
			break;
		}
	} while (ls != fertig);
}

void test_overload() {

	time_t tim = time(NULL);
	struct tm* ltim = localtime(&tim);
	DisplayTime(ltim);
	DisplayTime(&tim);
}
void DisplayTime(const struct tm* tim)
{
	cout << "1. (struct tm) Die Zeit: " << asctime(tim);
}
void DisplayTime(const time_t* tim)
{
	cout << "2. (time_t ) Die Zeit: " << ctime(tim);
}

void test_overload_strcopy() {
	static char stringA[20], stringB[20];
	stringcopy(stringA, "Das");
	stringcopy(stringB, "Dies ist ein String", 4);
	cout << stringB << " und " << stringA;
}
inline void stringcopy(char* ziel, const char* quelle)
{
	strcpy(ziel, quelle);
}
inline void stringcopy(char* ziel, const char* quelle, int len)
{
	strncpy(ziel, quelle, len);
	ziel[len] = '\0'; // mit NUL-Byte abschließen
}


//QSORT Array of char pointers
void test_extern_C() {
	
	const char* brothers[] =
	{ "Rainer", // Array mit String-Pointern,
	"Arne", // die sortiert werden sollen
	"Joerg",
	"Armin",
	"Martin"
	};
	brothers[0] = "Yubert";
	const int count = sizeof(brothers) / sizeof(*brothers); // = 5
	// Sortierung der Strings des Arrays
	// in alphabetischer Reihenfolge
	qsort(brothers, count, sizeof(*brothers), comp);
	// Ausgabe auf dem Bildschirm
	for (int i = 0; i < count; i++)
		cout << brothers[i] << "\n";
}
extern "C"
{
	int comp(const void* a, const void* b)
	{
		return strcmp(*(char**)a, *(char**)b);
	}
}


void test_referenz(){

	int ivar = 123;

	int& iref = ivar;
	cout << "Adresse von ivar: " << (&ivar) << "\n";
	cout << "Adresse von iref: " << (&iref) << "\n";
}