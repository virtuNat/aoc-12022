#include "aoc.h"

void getHalves(std::string line, uint16_t &score)
{
	size_t half = line.size() / 2;
	for (size_t i = 0; i < half; ++i)
	{
		for (size_t j = half; j < line.size(); ++j)
		{
			if (line[i] == line[j])
			{
				score += line[i] - (line[i] < 97 ? 38 : 96);
				return;
			}
		}
	}
}

Solution day03(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line1, line2, line3;
	uint16_t score1 = 0, score2 = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line1))
	{
		std::getline(ifile, line2);
		std::getline(ifile, line3);
		getHalves(line1, score1);
		getHalves(line2, score1);
		getHalves(line3, score1);

		for (int i : line1)
		{
			for (int j : line2)
			{
				for (int k : line3)
				{
					if (i == j && j == k)
					{
						score2 += i - (i < 97 ? 38 : 96);
						goto next_3_lines;
					}
				}
			}
		}
	next_3_lines: 
		continue;
	}
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
