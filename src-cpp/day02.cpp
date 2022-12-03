#include "aoc.h"

constexpr uint16_t strat1[9] = 
{
	4, 8, 3, 1, 5, 9, 7, 2, 6
};
constexpr uint16_t strat2[9] =
{
	3, 4, 8, 1, 5, 9, 2, 6, 7
};

Solution day02(std::ifstream ifile)
{
	std::string line;
	uint16_t score1 = 0, score2 = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{
		size_t idx = ((size_t)line[0] - (int)'A') * 3 + (size_t)line[2] - (int)'X';
		score1 += strat1[idx];
		score2 += strat2[idx];
	}
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
