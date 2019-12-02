#pragma once
#include "PuzzleSolver.h"

#include <sstream>
#include <algorithm>
#include <iterator>


class Day2 :
	public PuzzleSolver
{
public:
	Day2(std::string file, InputStructure type) : PuzzleSolver(2, file, type) {}
	~Day2();

	int solve();

private:
	std::vector<int> integerCode;
	std::vector<int> origCode;
	int doOperation(int &pos);
	void printCode();
	void resetCode();
};



