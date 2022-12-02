#include "aoc.h"

AoCSolution::AoCSolution(uint8_t day, std::function<int(std::ifstream)> soln)
	: _day(day), _soln(soln)
{
}

uint8_t AoCSolution::getDay()
{
	return _day;
}

uint64_t AoCSolution::runSolution(int &status)
{
	std::ostringstream fname;
	fname << "../input/day" 
		  << std::setfill('0') << std::setw(2) << std::to_string(_day) 
		  << ".txt";
	auto time_start = std::chrono::high_resolution_clock::now();
	status = _soln(std::ifstream(fname.str()));
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - time_start).count();
}

void AoCSolution::runBatch(const size_t total)
{
	std::unique_ptr<uint64_t[]> times(new uint64_t[total]);
	dbl median, mean, stdev = 0;
	int status = 0;

	for (size_t i = 0; i < total; ++i)
	{
		times[i] = runSolution(status);
		if (status)
		{
			std::cerr << "Error: Status Code " << status << std::endl;
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

	std::cout << std::setprecision(3) << std::fixed
			  << "Statistics for Day " << std::to_string(_day) << ":" << std::endl
			  << "Median runtime: " << median << " us." << std::endl
			  << "Mean runtime: " << mean << " us." << std::endl
			  << "Fastest runtime: " << times[0] << " us." << std::endl
			  << "Longest runtime: " << times[total - 1] << " us." << std::endl
			  << "Deviation: " << stdev << " us." << std::endl;
}
