#include "aoc.h"

int main(int argc, const char* argv[])
{
	AoCSolution day1(1, day01),
	            day2(2, day02);
	day1.runBatch(31);
	day2.runBatch(31);
	return 0;
}
