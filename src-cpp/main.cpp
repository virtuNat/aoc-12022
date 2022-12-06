#include "aoc.h"

int main(int argc, const char* argv[])
{
	AoCSolution day1(1, day01),
	            day2(2, day02),
	            day3(3, day03),
	            day4(4, day04),
	            day5(5, day05);
	day1.runBatch(31);
	day2.runBatch(31);
	day3.runBatch(31);
	day4.runBatch(31);
	day5.runBatch(31);
	return 0;
}
