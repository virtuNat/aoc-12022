#include "aoc.h"

Solution day01(std::ifstream ifile) 
{
	std::string line;
	uint32_t cal = 0, cal1 = 0, cal2 = 0, cal3 = 0;
	auto time_start = high_resolution_clock::now();
	while (std::getline(ifile, line)) {
		if (line.empty()) {
			if (cal > cal1)
			{
				cal3 = cal2;
				cal2 = cal1;
				cal1 = cal;
			}
			else if (cal > cal2)
			{
				cal3 = cal2;
				cal2 = cal;
			}
			else if (cal > cal3)
			{
				cal3 = cal;
			}
			cal = 0;
			continue;
		}
		cal += std::atoi(line.c_str());
	}
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(cal1);
	soln.p2 = std::to_string(cal1 + cal2 + cal3);
	soln.duration = getTimeDiff(time_start);
	return soln;
}

