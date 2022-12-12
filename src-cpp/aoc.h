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
	int status = 0;
	std::string p1;
	std::string p2;
	uint64_t duration = 0;
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
Solution day03(std::ifstream ifile);
Solution day04(std::ifstream ifile);
Solution day05(std::ifstream ifile);
Solution day06(std::ifstream ifile);
Solution day07(std::ifstream ifile);
Solution day08(std::ifstream ifile);
Solution day09(std::ifstream ifile);
Solution day10(std::ifstream ifile);
Solution day11(std::ifstream ifile);
Solution day12(std::ifstream ifile);
Solution day13(std::ifstream ifile);
Solution day14(std::ifstream ifile);
Solution day15(std::ifstream ifile);
Solution day16(std::ifstream ifile);
Solution day17(std::ifstream ifile);
Solution day18(std::ifstream ifile);
Solution day19(std::ifstream ifile);
Solution day20(std::ifstream ifile);
Solution day21(std::ifstream ifile);
Solution day22(std::ifstream ifile);
Solution day23(std::ifstream ifile);
Solution day24(std::ifstream ifile);
Solution day25(std::ifstream ifile);

