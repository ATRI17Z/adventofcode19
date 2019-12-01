#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

typedef long long ll;

class InputLoader
{
public:
	InputLoader();
	~InputLoader();

	static std::string getInputAsString(std::string fileName);
	static std::vector<std::string> getInputPerLine(std::string fileName);
	static std::vector<ll> getIntInputPerLine(std::string fileName);
};

