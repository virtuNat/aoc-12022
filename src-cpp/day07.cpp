#include "aoc.h"

Solution day06(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{

	}
	soln.p1 = std::to_string(0);
	soln.p2 = std::to_string(0);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
