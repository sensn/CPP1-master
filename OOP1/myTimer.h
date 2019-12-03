#pragma once
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

class MyTimer {
private:
	
public:
	unsigned int time_in_millis;


	//MyTimer();

	//MyTimer(int themillis);
	MyTimer(void); //: time_in_millis(0) {}
	MyTimer(unsigned int t_millis);// : time_in_millis(t_millis) {}

	//Destructor
	~MyTimer();

	int start();
	
};

