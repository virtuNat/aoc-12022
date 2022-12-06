#include "aoc.h"

Solution day05(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line;
	std::array<std::string, 9> stacks1, stacks2;
	int cnt, src, dst;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line) && line[1] != '1')
	{
		for (size_t i = 1; i < line.length(); i += 4)
		{
			if (line[i] != ' ')
			{
				size_t j = (i - 1) / 4;
				stacks1[j] += line[i];
				stacks2[j] += line[i];
			}
		}
	}
	std::getline(ifile, line);
	while (std::getline(ifile, line))
	{
		if (line.size() == 18)
		{
			cnt = line[5] - 48;
			src = line[12] - 49;
			dst = line[17] - 49;
		}
		else
		{
			cnt = line[5] * 10 + line[6] - 528;
			src = line[13] - 49;
			dst = line[18] - 49;
		}
		stacks1[dst].insert(stacks1[dst].begin(), stacks1[src].rbegin() + (stacks1[src].size() - cnt), stacks1[src].rend());
		stacks1[src].erase(stacks1[src].begin(), stacks1[src].begin() + cnt);
		stacks2[dst].insert(0, stacks2[src], 0, cnt);
		stacks2[src].erase(stacks2[src].begin(), stacks2[src].begin() + cnt);
	}
	
	for (std::string str : stacks1)
	{
		soln.p1 += str.front();
	}
	for (std::string str : stacks2)
	{
		soln.p2 += str.front();
	}
	soln.duration = getTimeDiff(time_start);
	return soln;
}
