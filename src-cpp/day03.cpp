#include "aoc.h"

Solution day03(std::ifstream ifile)
{
	std::string line;
	std::set<int> left, right, sline, temp1, temp2;
	uint16_t score1 = 0, score2 = 0;
	uint8_t count = 0;
	size_t half;
	int output[1];
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{
		left.clear();
		right.clear();

		half = line.size() / 2;
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
		score1 += *output - (*output < 97 ? 38 : 96);

		sline = std::set<int>(line.begin(), line.end());
		switch (count)
		{
		case 0:
			temp1 = sline;
			count = 1;
			continue;
		case 1:
			std::set_intersection(
				temp1.begin(), temp1.end(),
				sline.begin(), sline.end(),
				std::inserter(temp2, temp2.begin())
			);
			count = 2;
			continue;
		case 2:
			std::set_intersection(
				temp2.begin(), temp2.end(),
				sline.begin(), sline.end(),
				output
			);
			temp1.clear();
			temp2.clear();
			score2 += *output - (*output < 97 ? 38 : 96);
			count = 0;
			continue;
		}
	}
	uint64_t duration = getTimeDiff(time_start);
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(score1);
	soln.p2 = std::to_string(score2);
	soln.duration = duration;
	return soln;
}
