#include "myTimer.h"
#include <time.h>
#include "CHouse.h"

MyTimer::MyTimer() {
	
	this->time_in_millis = 50;
}
MyTimer::MyTimer(unsigned int t_millis) {
	
	this->time_in_millis = t_millis;
}
MyTimer::MyTimer(unsigned int t_millis,int rows,int columns) {
	
	this->time_in_millis = t_millis;
	this->m_row = rows;
	this->m_column = columns;
}

int MyTimer::start() {
		bool isplaying = 1;
	this->begin = clock();

	int thebpm = this->time_in_millis;
	//double ms = ((60000.0 / (double)thebpm) / (double)4);
	this->ms = ((60000.0 / (double)this->time_in_millis) / (double)4);
	//srand(time(0));
	//ms = 1000;
	this->dur = (ms / 1000) * CLOCKS_PER_SEC;
	this->theend = (double)clock() + dur;
	p = new House(m_row, m_column);
	//House* p = new House(rand()%20, rand() % 20);


		this->begin = clock();
		//theend = (double)(clock() + dur);
		//thetime = 0;
		while (1) {
			this->begin = clock();
			if ((double)this->begin > this->theend) {
				this->theend = (double)(clock() + dur);
				p->Update();
				
					//this->dur =(RANDOM() * 1000);
					//myrnd = (RANDOM() * 1000);
				//thetime = 1;
				//return 1;
			}
			//thetime = 0;
			if (p->isDead()) {

				this->dur = (((60000.0 / (double)((RANDOM()*1000))) / (double)4) / 1000) * CLOCKS_PER_SEC;
				//printf("DEAD");
			}
		}

	
	//return 0;
}