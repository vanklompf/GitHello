#include "byte_accumulate.h"
#include <cstdint>
#include <numeric>
#include <vector>

uint64_t byteAccumulate_HandCraftedDoWhilePtr(const uint8_t* byte_array, size_t size)
{
	uint64_t result = 0;
	do
	{
		result += *byte_array++;
	} while (--size);

    return result;
}

uint64_t byteAccumulate_HandCraftedForArray(const uint8_t* byte_array, size_t size)
{
	uint64_t result = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		result += byte_array[i];
	}
	return result;
}

uint64_t byteAccumulate_HandCraftedUnrolledForArray(const uint8_t* byte_array, size_t size)
{
	uint64_t result = 0;
	for (unsigned int i = 0; i < size / 4; i+=4)
	{
		result += byte_array[i];
		result += byte_array[i+1];
		result += byte_array[i+2];
		result += byte_array[i+3];
	}
	return result;
}

uint64_t byteAccumulate_StlPlainArary(const uint8_t* byte_array, size_t size)
{
	return std::accumulate(byte_array, byte_array + size, 0ull);
}

uint64_t byteAccumulate_StlVector(const std::vector<uint8_t> &byte_vector)
{
	return std::accumulate(byte_vector.begin(), byte_vector.end(), 0ull);
}


uint64_t byteAccumulate_Unrolled(const uint8_t* byte_array, size_t size)
{
	uint64_t result = 0;

	while (((uint32_t)byte_array & 0x03) && size)
	{
		size--;
		result += *byte_array++;
	}

	//now we have alligned record
	if (size > 4)
	{
		const uint32_t* p = (const uint32_t*)byte_array;
		uint32_t  s = size & (~(uint32_t)3);
		uint32_t  v;

		while (s)
		{
			v = *p++;
			result += (v & 0xFF); v >>= 8;
			result += (v & 0xFF); v >>= 8;
			result += (v & 0xFF); v >>= 8;
			result += v;
			s -= 4;
		}
		byte_array = (const uint8_t*)p;
		size &= 3;
	}
	// Add rest of bytes
	while (size--) result += *byte_array++;

	return result;
}
