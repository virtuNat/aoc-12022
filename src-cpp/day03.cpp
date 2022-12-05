#include "aoc.h"

int getHalves(std::string line, uint16_t &score)
{
	std::set<int> left, right;
	size_t half = line.size() / 2;
	int output[1];
	for (size_t i = 0; i < half; ++i)
	{
		left.insert(line[i]);
		right.insert(line[half + i]);
	}
	std::set_intersection(
		left.begin(), left.end(),
		right.begin(), right.end(),
		output
	);
	score += *output - (*output < 97 ? 38 : 96);
}

Solution day03(std::ifstream ifile)
{
	std::string line1, line2, line3;
	std::set<int> set1, set2, set3, temp;
	uint16_t score1 = 0, score2 = 0;
	int output[1];
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line1))
	{
		std::getline(ifile, line2);
		std::getline(ifile, line3);
		getHalves(line1, score1);
		getHalves(line2, score1);
		getHalves(line3, score1);
		set1.clear();
		set2.clear();
		set3.clear();
		temp.clear();
		set1 = std::set<int>(line1.begin(), line1.end());
		set2 = std::set<int>(line2.begin(), line2.end());
		set3 = std::set<int>(line3.begin(), line3.end());

		std::set_intersection(
			set1.begin(), set1.end(),
			set2.begin(), set2.end(),
			std::inserter(temp, temp.begin())
		);
		std::set_intersection(
			temp.begin(), temp.end(),
			set3.begin(), set3.end(),
			output
		);
		score2 += *output - (*output < 97 ? 38 : 96);
	}
	uint64_t duration = getTimeDiff(time_start);
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = duration;
	return soln;
}
