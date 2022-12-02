#include "aoc.h"

AoCSolution::AoCSolution(uint8_t day, std::function<Solution(std::ifstream)> solver)
	: _day(day), _solver(solver)
{
}

std::string AoCSolution::getDay()
{
	return std::to_string(_day);
}

uint64_t AoCSolution::runSolution(Solution &soln)
{
	std::ostringstream fname;
	fname << "../input/day" 
		  << std::setfill('0') << std::setw(2) << getDay()
		  << ".txt";
	auto time_start = std::chrono::high_resolution_clock::now();
	soln = _solver(std::ifstream(fname.str()));
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
}

void AoCSolution::runBatch(const size_t total)
{
	std::unique_ptr<uint64_t[]> times(new uint64_t[total]);
	dbl median, mean, stdev = 0;
	Solution soln = Solution();

	for (size_t i = 0; i < total; ++i)
	{
		times[i] = runSolution(soln);
		if (soln.status)
		{
			std::cerr << "Error: Status Code " << soln.status << std::endl;
			return;
		}
	}
	std::sort(times.get(), times.get() + total);
	size_t idx = total / 2;
	median = (dbl)times[idx];
	if (total % 2 == 0)
	{
		median = (median + times[idx]) * 0.5l;
	}
	mean = (dbl)std::accumulate(times.get(), times.get() + total, 0) / total;
	for (size_t i = 0; i < total; ++i)
	{
		dbl diff = times[i] - mean;
		stdev += diff * diff;
	}
	stdev = std::sqrtl(stdev / (total - 1));

	std::cout << "Solution for Day " << getDay() << ":" << std::endl
			  << "  Part 1: " << soln.p1 << std::endl
			  << "  Part 2: " << soln.p2 << std::endl
			  << std::setprecision(3) << std::fixed
			  << "------------------------------" << std::endl
			  << "Statistics for Day " << getDay() << ":" << std::endl
			  << "  Median runtime: " << median << " us." << std::endl
			  << "  Mean runtime: " << mean << " us." << std::endl
			  << "  Fastest runtime: " << times[0] << " us." << std::endl
			  << "  Longest runtime: " << times[total - 1] << " us." << std::endl
			  << "  Deviation: " << stdev << " us." << std::endl
			  << "------------------------------" << std::endl;
}
