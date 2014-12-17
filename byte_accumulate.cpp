#include "byte_accumulate.h"
#include <cstdint>
#include <numeric>
#include <vector>

uint32_t byteAccumulate_HandCraftedDoWhilePtr(const uint8_t* byte_array, size_t size)
{
	uint32_t result = 0;
	do
	{
		result += *byte_array++;
	} while (--size);

    return result;
}

uint32_t byteAccumulate_HandCraftedForArray(const uint8_t* byte_array, size_t size)
{
	uint32_t result = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		result += byte_array[i];
	}
	return result;
}

uint32_t byteAccumulate_StlPlainArary(const uint8_t* byte_array, size_t size)
{
	return std::accumulate(byte_array, byte_array + size, 0);
}

uint32_t byteAccumulate_StlVector(const std::vector<uint8_t> &byte_vector)
{
	return std::accumulate(byte_vector.begin(), byte_vector.end(), 0);
}
