#include <array>
#include "aoc.h"

int day01(std::ifstream ifile) 
{
	std::string line;
	std::array<uint32_t, 4> cals = { 0 };
	uint32_t cal = 0;
	while (std::getline(ifile, line)) {
		if (line.empty()) {
			for (int8_t i = 2; i >= 0; --i) {
				if (cal <= cals[i]) break;
				cals[i + 1] = cals[i];
				cals[i] = cal;
			}
			cal = 0;
			continue;
		}
		cal += std::atoi(line.c_str());
	}
	std::cout << "Part 1: " << cals[0] << std::endl
			  << "Part 2: " << cals[0] + cals[1] + cals[2] << std::endl;
	return 0;
}

int main(int argc, const char* argv[]) 
{
	AoCSolution day1(1, day01);
	day1.runBatch(31);
	return 0;
}
