#ifndef BYTE_ACCUMULATE_H
#define BYTE_ACCUMULATE_H

#include <cstdint>
#include <vector>

uint32_t byteAccumulate_HandCraftedDoWhilePtr(const uint8_t* byte_array, size_t size);
uint32_t byteAccumulate_HandCraftedForArray(const uint8_t* byte_array, size_t size);
uint32_t byteAccumulate_StlPlainArary(const uint8_t* byte_array, size_t size);
uint32_t byteAccumulate_StlVector(const std::vector<uint8_t> &byte_vector);

#endif /* BYTE_ACCUMULATE_H */