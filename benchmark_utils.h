#ifndef BENCHMARK_UTILS_H
#define BENCHMARK_UTILS_H
#include <functional>
#include <chrono>
#include <iostream>

template<typename T>
uint32_t runAndMeasure(std::function<T(void)> work, int times)
{
	std::chrono::steady_clock::time_point start, end;
	start = std::chrono::steady_clock::now();
	T anti_optimizer = 0;

	for (auto i = 0; i < times; i++)
	{
		anti_optimizer += work();
	}

	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "Ignore this: " << anti_optimizer << std::endl;
	return (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count();
}

template<typename T>
bool checkResult(std::function<T(void)> work, T expected_result)
{
	std::cout << "Result: " << work() << std::endl;
	return expected_result == work();
}


#endif /* BENCHMARK_UTILS_H */
