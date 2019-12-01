#pragma once
#include "PuzzleSolver.h"
class Day2 :
	public PuzzleSolver
{
public:
	Day2(std::string file, InputStructure type) : PuzzleSolver(1, file, type) {}
	~Day2();

	int solve();
};

