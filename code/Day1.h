#pragma once
#include "PuzzleSolver.h"
class Day1 :
	public PuzzleSolver
{
public:
	//Day1() : PuzzleSolver() {}
	Day1(std::string file, InputStructure type) : PuzzleSolver(1, file, type) {}
	~Day1();

	int solve();

private:
	int getAddedFuel(int fuel);
};

