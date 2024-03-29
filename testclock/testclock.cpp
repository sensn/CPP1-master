/*
	COPYRIGHT © 2018 Ringo Hoffmann (zekro Development)
	READ BEFORE USING: https://zekro.de/policy
*/

#include "timer.h"

using namespace std;


int main() {


	/*
		EXAMPLE 1
		Initialize a timer which will count up
		the integer every second and output the
		result.
	*/

	int countMeUp = 0;

	
	


	

	Timer t1([&]() {
		countMeUp++;
		cout << countMeUp << endl;
		}, 1000);

	t1.start();

	std::cin.get();
	t1.stop();

	/*
		EXAMPLE 2
		Count up an integer and another one down
		every second. If they are at the same value,
		stop the timer from inside.
		This is only possible, when you pass over the
		function with the timer instance reference into
		after initializing the timer instance.
	*/

	//Timer t3[1] = { Timer([&]() {countMeUp++; std::cout << countMeUp << endl; },500) };       //     ????
	//Timer t4[2] = { Timer([&]() {countMeUp++; cout << countMeUp << endl; },500), Timer([&]() {countMeUp++; cout << countMeUp << endl; },100) };       //     ????
	//t3[0].start();


	printf("EXAMPLE 2");
	int iGoUp = 0, iGoDown = 10;
	Timer t2;
	
	t2.setFunc([&]() {
		if (++iGoUp == --iGoDown)
			t2.stop();
		cout << iGoUp << " - " << iGoDown << endl;
		})
		->setInterval(1000)
			->start();


		std::cin.clear();
		std::cin.get();
		return 0;
}