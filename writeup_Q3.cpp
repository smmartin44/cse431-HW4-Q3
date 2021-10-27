#include <iostream>
#include <unordered_map>
#include <map>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

/**
Will use this function to time how long it takes for insertions
of input n size, built by generating random values (unordered multimap)
*/
void insertions_unordered(int n) {
	unordered_multimap<int, int> unordered;

	// https://en.cppreference.com/w/cpp/numeric/random/rand
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	// For each value of n, we will add a value to a dictionary with i as a key,
	// and a random int as the value
	for (int i = 0; i < n; i++) {
		int random_variable = std::rand();
		pair<int, int> mypair(i, random_variable);

		// insert pair to the unordered multimap
		unordered.insert(mypair);
	}
}

/**
Will use this function to time how long it takes for insertions
of input n size, built by generating random values (multimap)
*/
void insertions_multimap(int n) {
	multimap <int, int> multi;

	// https://en.cppreference.com/w/cpp/numeric/random/rand
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	// For each value of n, we will add a value to a dictionary with i as a key,
	// and a random int as the value
	for (int i = 0; i < n; i++) {
		int random_variable = std::rand();
		pair<int, int> mypair(i, random_variable);

		// insert pair to the unordered multimap
		multi.insert(mypair);
	}
}

int main() {
	// I will be comparing unordered_multimaps and multimaps as
	// backends for dictionaries

	std::cout << std::fixed;
	std::cout << std::setprecision(10);

    // Vector of inputs of size n to test each insertion method
	vector<int> inputs = { 10, 100, 1000, 10000, 50000, 100000, 500000 };
	for (int input : inputs) {
		// multimap first
		std::clock_t start_time = std::clock();
		insertions_multimap(input);
		std::clock_t tot_time = std::clock() - start_time;

		// check for values of 0 to do an extra test estimation
		if (tot_time == 0) {
			start_time = std::clock();
			// run 10000 times for an estimation
			for (int i = 0; i < 10000; i++) {
				insertions_multimap(input);
			}
			tot_time = (double)(std::clock() - start_time);

            // Divide by 10000 to get the appropriate estimation of seconds for small times
			cout << input << ": " << ((double)tot_time) / (double)CLOCKS_PER_SEC / 10000 << endl;
		}
		else {
			cout << input << ": " << ((double)tot_time) / (double)CLOCKS_PER_SEC << endl;
		}

	}

	for (int input : inputs) {
		// unordered_multimap next
		std::clock_t start_time = std::clock();
		insertions_unordered(input);
		std::clock_t tot_time = std::clock() - start_time;

		// check for values of 0 to do an extra test estimation
		if (tot_time == 0) {
			start_time = std::clock();
			// run 10000 times for an estimation
			for (int i = 0; i < 10000; i++) {
				insertions_unordered(input);
			}
			tot_time = (double)(std::clock() - start_time);

            // Divide time by 10000 to get estimation in seconds for small times
			cout << input << ": " << ((double)tot_time) / (double)CLOCKS_PER_SEC / 10000 << endl;
		}
		else {
			cout << input << ": " << ((double)tot_time) / (double)CLOCKS_PER_SEC << endl;
		}

	}

	return 0;
}