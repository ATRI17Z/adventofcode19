#include "Day2.h"

Day2::~Day2()
{
}

int Day2::solve()
{
	std::stringstream ss(strInput);
	int pos = 0;
	int res = 0;
	// Read comma delimited string
	for (int num; ss >> num;) {
		this->integerCode.push_back(num);
		this->origCode.push_back(num);
		if (ss.peek() == ',') ss.ignore();

	}

	/* PART ONE */
	startTimer1(); // Starting Timing Part 1

	this->integerCode[1] = 12;
	this->integerCode[2] = 2;
	while (res == 0) {
		res = doOperation(pos);
	}

	if (res == 99) {
		//std::cout << "END: ";
		this->setSolutionPart1(this->integerCode[0]);
	}
	else {
		//std::cout << "ERROR: ";
	}
	stopTimer1(); // Stop Timing Part 1

	/* PART TWO */
	resetCode();
	startTimer2(); // Starting Timing Part 1
	for (int k = 0; k < 100; k++) {
		//noun
		for (int j = 0; j < 100; j++) {
			//verb
			resetCode();
			this->integerCode[1] = k;
			this->integerCode[2] = j;

			pos = 0;
			res = 0;
			while (res == 0) {
				res = doOperation(pos);
			}
			if (this->integerCode[0] == 19690720) {
				this->setSolutionPart2(100 * this->integerCode[1] + this->integerCode[2]);
				break;
			}
		}
	}
	stopTimer2(); // Stop Timing Part 2
	return 0;
}

int Day2::doOperation(int &pos)
{
	/* Executes the operation with the operant at position 'pos' and the adresses of the arguments on the subsequent positions
	   The position indicator 'pos' is set to the address after the last argument after execution */
	if (this->integerCode[pos] == 99) {
		// End Program
		pos++;
		return 99;
	}
	else if (this->integerCode[pos] == 1) {
		// Add value at address [pos+1] and [pos+2] and store it at address [pos+3]
		this->integerCode[this->integerCode[pos + 3]] = this->integerCode[this->integerCode[pos + 2]] + this->integerCode[this->integerCode[pos + 1]];
		// move pos by four (3 arguments)
		pos += 4;
	}
	else if (this->integerCode[pos] == 2) {
		// Multiply value at address [pos+1] and [pos+2] and store it at address [pos+3]
		this->integerCode[this->integerCode[pos + 3]] = this->integerCode[this->integerCode[pos + 2]] * this->integerCode[this->integerCode[pos + 1]];
		// move pos by four (3 argumetns)
		pos += 4;;
	}
	else {
		// Error
		pos++;
		return -1;
	}

	return 0;
}

void Day2::printCode() {
	for (auto it = this->integerCode.begin(); it != integerCode.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}

void Day2::resetCode()
{
	for (size_t i = 0; i < this->integerCode.size(); i++) {
		this->integerCode[i] = this->origCode[i];
	}
}

