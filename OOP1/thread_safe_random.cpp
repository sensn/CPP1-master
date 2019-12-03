#include <iostream>
#include <chrono>
#include <random> // requires flag --std=c++11 (or higher)
#include <mutex> // requires flag -pthread

#include "thread_safe_random.hpp"

std::mt19937_64 my_rng; // Defines an engine
std::uniform_real_distribution<double> my_unif_real_dist(0.0, 1.0); // Define distribution
std::mutex my_rng_mutex; // a mutex to guard my_rng

// This is the function to call if you want a random number in the interval [0,1)

double RANDOM() {
	std::lock_guard<std::mutex> lock(my_rng_mutex);
	return my_unif_real_dist(my_rng);
	// mutex is released when lock goes out of scope
}

/* Function to seed the random number generator from main file
 * This function again locks the mutex for when a thread decides
 * to re-seed the RNG.
 */

void Seed(int seed) {
	std::lock_guard<std::mutex> lock(my_rng_mutex);
	my_rng.seed(seed);
	// mutex is released when lock goes out of scope
}