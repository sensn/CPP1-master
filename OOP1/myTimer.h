#pragma once
#include <time.h>
#include<thread>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

class MyTimer {
private:
	
public:
	unsigned int time_in_millis;
	int m_row;
	int m_column;
	long begin;
	double ms;
	double dur;
	double theend;
	//MyTimer();

	//MyTimer(int themillis);
	MyTimer(void); //: time_in_millis(0) {}
	MyTimer(unsigned int t_millis);// : time_in_millis(t_millis) {}
	MyTimer(unsigned int t_millis, int rows, int columns);// : time_in_millis(t_millis) {}

	//Destructor
	~MyTimer();
	int thetime = 0;
	int start();
	std::thread runThread() {
		//std::this_thread::sleep_for(chrono::milliseconds(2000));
		//Sleep(199);
		return std::thread(&MyTimer::start, this);
	}
};

