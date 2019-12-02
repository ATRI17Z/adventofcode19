#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>

#include "inputLoader.h"



enum InputStructure {IntegerLines, StringLines, String};
/*
union Input {
	std::vector<ll> intLines;
	std::vector<std::string> strLines;
	std::string string;
	Input() { memset(this,0, sizeof(Input)); }
	~Input() {}
};
*/

class PuzzleSolver
{
public:
	PuzzleSolver() : dayNum(1), dataFile("../data/01/input.txt"), inputType(IntegerLines) { loadData(inputType); }

	PuzzleSolver(int day, std::string file, InputStructure type) : dayNum(day), dataFile(file), inputType(type) { loadData(inputType); }

	virtual ~PuzzleSolver() { printSolution(); };

	virtual int solve() = 0;

protected:
	std::vector<ll> intLines;
	std::vector<std::string> strLines;
	std::string strInput;

	void setSolutionPart1(ll solP1) { solutionPart1 = solP1; }
	void setSolutionPart2(ll solP2) { solutionPart2 = solP2; }

	void startTimer1();
	void stopTimer1();
	void startTimer2();
	void stopTimer2();

	int printSolution();
	
private:
	ll solutionPart1;
	ll solutionPart2;

	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;
	ll executionTime1;
	ll executionTime2;

	int dayNum;
	std::string dataFile;
	InputStructure inputType;
	//union Input input;
	
	int loadData(InputStructure type);
	int printPart1();
	int printPart2();
	int printTiming(ll t);
};

