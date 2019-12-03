#include "myTimer.h"
#include <time.h>

MyTimer::MyTimer() {

	this->time_in_millis = 500;
}

MyTimer::MyTimer(unsigned int t_millis) {

	this->time_in_millis = t_millis;
}

int MyTimer::start() {
		bool isplaying = 1;
	long begin = clock();

	int thebpm = time_in_millis;
	double ms = ((60000.0 / (double)thebpm) / (double)4);
	//srand(time(0));
	//ms = 1000;
	double dur = (ms / 1000) * CLOCKS_PER_SEC;
	double theend = (double)clock() + dur;



		begin = clock();
		//theend = (double)(clock() + dur);

		while (1) {
			begin = clock();
			if ((double)begin > theend) {
				theend = (double)(clock() + dur);
				return 1;
			}
		}

	
	//return 0;
}