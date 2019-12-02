#include "puzzleSolver.h"

int PuzzleSolver::loadData(InputStructure type)
{
	if (type == IntegerLines) {
		this->intLines = InputLoader::getIntInputPerLine(this->dataFile);
	}else if (type == StringLines) {
		this->strLines = InputLoader::getInputPerLine(this->dataFile);
	}else if (type == String) {
		this->strInput = InputLoader::getInputAsString(this->dataFile);
	}
	return 0;
}

void PuzzleSolver::startTimer1()
{
	this->t1 =  std::chrono::high_resolution_clock::now();
}
void PuzzleSolver::stopTimer1()
{
	std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
	this->executionTime1 = std::chrono::duration_cast<std::chrono::microseconds>(t - this->t1).count();
}

void PuzzleSolver::startTimer2()
{
	this->t2 = std::chrono::high_resolution_clock::now();
}
void PuzzleSolver::stopTimer2()
{
	std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
	this->executionTime2 = std::chrono::duration_cast<std::chrono::microseconds>(t - this->t2).count();
}

int PuzzleSolver::printSolution()
{
	printPart1();
	printPart2();
	return 0;
}

int PuzzleSolver::printPart1()
{
	std::cout << "Solution of Day " << dayNum << " in Part 1: " << solutionPart1 << std::endl;
	printTiming(this->executionTime1);
	return 0;
}

int PuzzleSolver::printPart2()
{
	std::cout << "Solution of Day " << dayNum << " in Part 2: " << solutionPart2 << std::endl;
	printTiming(this->executionTime2);
	return 0;
}

int PuzzleSolver::printTiming(ll t) {
	// Print timing number in a nicer format
	// t is provided in micros seconds
	if (t < 1000) {
		std::cout << "Execution: " << t << " us" << std::endl;
	}
	else if (t < 1000000) {
		std::cout << "Execution: " << std::setprecision(5) << t / 1000.0 << " ms" << std::endl; // std::setw(2)
	}
	else if (t < 60000000) {
		std::cout << "Execution: " << std::setprecision(5) << t / 1000000.0 << " s" << std::endl; // std::setw(2)
	}
	else if (t/60.0 < 60000000) {
		std::cout << "Execution: " << std::setprecision(5) << t / (60*1000000.0) << " min" << std::endl; // std::setw(2)
	}
	return 0;
}
