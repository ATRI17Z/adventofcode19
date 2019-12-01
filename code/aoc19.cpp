/* This is the main file for the Advent of Code 2019 solutions

aoc19 [day] [input.file]

[day]:        Number of the day, i.e. puzzle selection
[input.file]: Input file in ASCII format

*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

#include "Day1.h"
#include "Day2.h"

typedef std::chrono::system_clock Clock;

static void show_usage(std::string name) {
	std::cerr << "Usage: " << "AoC19.exe [dayNum] [input.file]" << std::endl;
}

int main(int argc, char **argv) {

	int dayNum = 1;
	std::stringstream fName;
	std::string fileName;

	// Parsing the input arguments
	if (argc == 3) { // standard case
		dayNum = std::stoi(argv[1]);
		fileName = argv[2];
	}
	else if (argc == 1) { // no parameters given
	   // No input arguments, using defaults

	   // Get current day of month
		auto now = Clock::now();
		std::time_t now_c = Clock::to_time_t(now);
		struct tm parts;
		if (localtime_s(&parts, &now_c) == 0) {
			if (parts.tm_mon == 11) { // December
				dayNum = parts.tm_mday;
			}
		}
		fName << "../data/" << std::setfill('0') << std::setw(2) << dayNum << "/input.txt";
		fileName = fName.str();
	}
	else if (argc == 2) {// only day as parameter
		dayNum = std::stoi(argv[1]);
		fName << "../data/" << std::setfill('0') << std::setw(2) << dayNum << "/input.txt";
		fileName = fName.str();
	}else {
		show_usage(argv[0]);
		return 0;
	}
	std::cout << "Taking data for day " << dayNum << " with " << fileName << std::endl;


	switch (dayNum) {
		case 1: {
			Day1 day(fileName, IntegerLines);
			day.solve();
			break;
		}
		case 2: {
			Day2 day(fileName, IntegerLines);
			day.solve();
			break;
		}
		default: {
			std::cout << "Day number unknown" << std::endl;
			break;
		}
	}

	return 0;
}

