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

using std::chrono::high_resolution_clock;

uint64_t getTimeDiff(std::chrono::steady_clock::time_point start);

struct Solution
{
	int status;
	std::string p1;
	std::string p2;
	uint64_t duration;
};

class AoCSolution
{
public:
	AoCSolution(uint8_t day, std::function<Solution(std::ifstream)> solver);
	std::string getDay();
	Solution runSolution();
	void runBatch(const size_t total);
private:
	const uint8_t _day;
	std::function<Solution(std::ifstream)> _solver;
};

Solution day01(std::ifstream ifile);
Solution day02(std::ifstream ifile);
