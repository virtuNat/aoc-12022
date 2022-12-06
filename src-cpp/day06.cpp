#include "aoc.h"

Solution day06(std::ifstream ifile)
{
	std::string line;
	uint16_t score1 = 0, score2 = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{

	}
	uint64_t duration = getTimeDiff(time_start);
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = duration;
	return soln;
}
