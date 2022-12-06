#include "aoc.h"

Solution day06(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line;
	uint16_t score1 = 0, score2 = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{

	}
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
