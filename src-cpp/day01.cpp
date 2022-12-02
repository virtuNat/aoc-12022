#include <array>
#include "aoc.h"

Solution day01(std::ifstream ifile) 
{
	std::string line;
	std::array<uint32_t, 3> cals = { 0 };
	uint32_t cal = 0;
	while (std::getline(ifile, line)) {
		if (line.empty()) {
			if (cal > cals[0])
			{
				cals[2] = cals[1];
				cals[1] = cals[0];
				cals[0] = cal;
			}
			else if (cal > cals[1])
			{
				cals[2] = cals[1];
				cals[1] = cal;
			}
			else if (cal > cals[2])
			{
				cals[2] = cal;
			}
			cal = 0;
			continue;
		}
		cal += std::atoi(line.c_str());
	}
	Solution soln = Solution();
	soln.status = 0;
	soln.p1 = std::to_string(cals[0]);
	soln.p2 = std::to_string(cals[0] + cals[1] + cals[2]);
	return soln;
}

int main(int argc, const char* argv[]) 
{
	AoCSolution day1(1, day01);
	day1.runBatch(31);
	return 0;
}
