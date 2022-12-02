#pragma once

#include <functional>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

typedef long double dbl;

class AoCSolution
{
public:
	AoCSolution(uint8_t day, std::function<int(std::ifstream)> soln);
	uint8_t getDay();
	uint64_t runSolution(int &status);
	void runBatch(const size_t total);
private:
	const uint8_t _day;
	std::function<int(std::ifstream)> _soln;
};
