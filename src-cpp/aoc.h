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

struct Solution
{
	int status;
	std::string p1;
	std::string p2;
};

class AoCSolution
{
public:
	AoCSolution(uint8_t day, std::function<Solution(std::ifstream)> solver);
	std::string getDay();
	uint64_t runSolution(Solution &soln);
	void runBatch(const size_t total);
private:
	const uint8_t _day;
	std::function<Solution(std::ifstream)> _solver;
};
