#include "inputLoader.h"



InputLoader::InputLoader()
{
}


InputLoader::~InputLoader()
{
}

std::string InputLoader::getInputAsString(std::string fileName)
{
	std::string str;

	// Open File
	std::ifstream in(fileName);
	if (!in.is_open() || !in.good()) {
		std::cout << "Failed to open input" << std::endl;
		return "";
	}

	// Create String
	str.assign((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	in.close();
	return str;
	
}

std::vector<std::string> InputLoader::getInputPerLine(std::string fileName)
{
	std::vector<std::string> lines;
	std::string line;

	// Open File
	std::ifstream in(fileName);
	if (!in.is_open() || !in.good()) {
		std::cout << "Failed to open input" << std::endl;
	}

	// Create Vector of lines
	while (getline(in, line)) {
		lines.push_back(line);
	}
	in.close();
	return lines;
}

std::vector<ll> InputLoader::getIntInputPerLine(std::string fileName)
{
	std::vector<ll> lines;
	std::string line;

	// Open File
	std::ifstream in(fileName);
	if (!in.is_open() || !in.good()) {
		std::cout << "Failed to open input" << std::endl;
	}

	// Create Vector of lines
	while (getline(in, line)) {
		lines.push_back(std::stoll(line));
	}
	in.close();
	return lines;
}
