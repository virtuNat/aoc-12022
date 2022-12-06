#include "aoc.h"

Solution day04(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line;
	uint16_t score1 = 0, score2 = 0;
	std::array<uint16_t, 4> input;
	size_t idx;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{
		idx = 0;
		input.fill(0);
		for (int c : line)
		{
			if (48 <= c && c <= 57)
			{
				input[idx] = input[idx] * 10 + c - 48;
			}
			else if (++idx >= 4)
			{
				break;
			}
		}
		if (input[0] <= input[3] && input[2] <= input[1])
		{
			score2++;
			if ((input[0] <= input[2] && input[3] <= input[1]) || (input[2] <= input[0] && input[1] <= input[3]))
			{
				score1++;
			}
		}
	}
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
