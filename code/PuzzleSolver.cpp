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

int PuzzleSolver::printSolution()
{
	printPart1();
	printPart2();
	return 0;
}

int PuzzleSolver::printPart1()
{
	std::cout << "Solution of Day " << dayNum << " in Part 1: " << solutionPart1 << std::endl;
	return 0;
}

int PuzzleSolver::printPart2()
{
	std::cout << "Solution of Day " << dayNum << " in Part 2: " << solutionPart2 << std::endl;
	return 0;
}
