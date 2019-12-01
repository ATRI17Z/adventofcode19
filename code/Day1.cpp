#include "Day1.h"

Day1::~Day1()
{
}

int Day1::solve()
{
	int rawFuel = 0;
	int totalFuel = 0;
	int moduleFuel = 0;
	int addedFuel = 0;
	
	for (std::vector<ll>::iterator it = this->intLines.begin(); it != this->intLines.end(); it++) {
		moduleFuel = (int)(*it / 3.0) - 2;
		addedFuel = getAddedFuel(moduleFuel);
		rawFuel += moduleFuel;
		totalFuel += moduleFuel + addedFuel;
	}

	this->setSolutionPart1(rawFuel);
	this->setSolutionPart2(totalFuel);

	return 0;
}


int Day1::getAddedFuel(int fuel) {
	int addedFuel = 0;
	int fuelDelta = fuel;
	while (fuelDelta > 0) {
		//fuelDelta = std::rint(fuelDelta / 3.0) - 2;
		fuelDelta = (int)(fuelDelta / 3.0) - 2;
		if (fuelDelta < 1) return addedFuel;
		addedFuel += fuelDelta;
	}
	return 0;
}