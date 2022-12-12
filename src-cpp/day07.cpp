#include "aoc.h"
#include <vector>
#include <ranges>

Solution day07(std::ifstream ifile)
{
	Solution soln = Solution();
	std::string line;
	std::vector<uint32_t> dsize { 0 }, path;
	uint32_t val, total = 0, fspace, msize = 70000000;
	size_t idx = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line))
	{
		if (48 <= line[0] && line[0] <= 57)
		{
			line.erase(std::find(line.begin(), line.end(), ' '), line.end());
			val = std::stoi(line);
			for (size_t i = 0; i < path.size(); ++i)
			{
				dsize[path[i]] += val;
			}
			continue;
		}
		if (line[0] == 36 && line[2] == 99)
		{
			if (line[line.size() - 1] == 46)
			{
				path.pop_back();
			}
			dsize.push_back(0);
			path.push_back(idx++);
		}
	}
	fspace = dsize[0] - 40000000;
	for (uint32_t fsize : dsize)
	{
		if (fsize <= 100000)
		{
			total += fsize;
		}
		if (fsize >= fspace && fsize < msize)
		{
			msize = fsize;
		}
	}
	soln.p1 = std::to_string(total);
	soln.p2 = std::to_string(msize);
	soln.duration = getTimeDiff(time_start);
	return soln;
}
