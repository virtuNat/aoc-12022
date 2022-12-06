#include "aoc.h"

Solution day06(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string buffer;
	std::array<char, 14> word = { 255 };
	size_t idx = 4;
	auto time_start = high_resolution_clock::now();
	std::getline(ifile, buffer);
	for (; idx < buffer.size(); ++idx)
	{
		std::copy(buffer.begin() + idx - 4, buffer.begin() + idx, word.begin());
		for (size_t j = 0; j < 3; ++j)
		{
			for (size_t k = j + 1; k < 4; ++k)
			{
				if (word[j] == word[k])
				{
					goto next_4;
				}
			}
		}
		break;
	next_4: 
		continue;
	}
	soln.p1 = std::to_string(idx);
	for (; idx < buffer.size(); ++idx)
	{
		std::copy(buffer.begin() + idx - 14, buffer.begin() + idx, word.begin());
		for (size_t j = 0; j < 13; ++j)
		{
			for (size_t k = j + 1; k < 14; ++k)
			{
				if (word[j] == word[k])
				{
					goto next_14;
				}
			}
		}
		break;
	next_14: 
		continue;
	}
	soln.p2 = std::to_string(idx);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
