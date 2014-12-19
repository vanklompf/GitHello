#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include "bsearch.h"
#include "byte_accumulate.h"
#include "benchmark_utils.h"

#ifdef __arm__
static const int32_t BSEARCH_REPEATS = 500000;
static const int32_t BSEARCH_DATA_SIZE = 9600000;

static const int32_t BYTE_ACCUMULATE_DATA_SIZE = 16777216;
static const int32_t BYTE_ACC_REPEATS = 8;
#else
static const int32_t BSEARCH_REPEATS = 5000000;
static const int32_t BSEARCH_DATA_SIZE = 4800000;

static const int32_t BYTE_ACCUMULATE_DATA_SIZE = 268435456;
static const int32_t BYTE_ACC_REPEATS = 8;
#endif

typedef uint32_t(*benchmark_func)();

static uint32_t anti_optimizer;

static glyph_info_t glyph_array[BSEARCH_DATA_SIZE];
static std::vector<glyph_info_t> glyph_vector(BSEARCH_DATA_SIZE);
static const glyph_info_t to_be_found = {0xFFFFFFFF, 0, 0};

static uint8_t byte_array[BYTE_ACCUMULATE_DATA_SIZE];
static std::vector<uint8_t> byte_vector(BYTE_ACCUMULATE_DATA_SIZE);

struct benchmark_definition_t {
    const char *name;
    uint32_t times;
    void(*func)();
    int32_t time;
};

std::vector<benchmark_definition_t> benchmarks =
{
    {"Manual binary search             ", BSEARCH_REPEATS,  []() {anti_optimizer += bsearchHandCrafted(glyph_array, BSEARCH_DATA_SIZE, &to_be_found);}, -1},
    {"C Style binary search            ", BSEARCH_REPEATS,  []() {anti_optimizer += bsearchC_Style(glyph_array, BSEARCH_DATA_SIZE, &to_be_found);}, -1},
    {"STL binary search (array)        ", BSEARCH_REPEATS,  []() {anti_optimizer += bsearchStlPlainArray(glyph_array, BSEARCH_DATA_SIZE, to_be_found);}, -1},
    {"STL binary search (vector)       ", BSEARCH_REPEATS,  []() {anti_optimizer += bsearchStlInVector(glyph_vector, to_be_found);}, -1},
	{"Manual byte accumulate (do/while)", BYTE_ACC_REPEATS, []() {anti_optimizer += byteAccumulate_HandCraftedDoWhilePtr(byte_array, BYTE_ACCUMULATE_DATA_SIZE);}, -1},
	{"Manual byte accumulate (for)     ", BYTE_ACC_REPEATS, []() {anti_optimizer += byteAccumulate_HandCraftedForArray(byte_array, BYTE_ACCUMULATE_DATA_SIZE); }, -1 },
	{"STL byte accumulate (C array)    ", BYTE_ACC_REPEATS, []() {anti_optimizer += byteAccumulate_StlPlainArary(byte_array, BYTE_ACCUMULATE_DATA_SIZE); }, -1 },
	{"STL byte accumulate (vector)     ", BYTE_ACC_REPEATS, []() {anti_optimizer += byteAccumulate_StlVector(byte_vector); }, -1 },
	{"Unrolled byte accumulate (array) ", BYTE_ACC_REPEATS, []() {anti_optimizer += byteAccumulate_Unrolled(byte_array, BYTE_ACCUMULATE_DATA_SIZE); }, -1 },
};

struct GlyphFillGenerator {
    glyph_info_t m_glyph;

	GlyphFillGenerator(uint32_t start) {
        m_glyph.glyph_number = start;
    };

    glyph_info_t operator()() {
        m_glyph.glyph_number++;
        return m_glyph;
    }
};

int main() 
{
    std::generate(glyph_array, glyph_array + BSEARCH_DATA_SIZE, GlyphFillGenerator(0));
    std::generate(glyph_vector.begin(), glyph_vector.end(), GlyphFillGenerator(0));

	std::iota(byte_array, byte_array+BYTE_ACCUMULATE_DATA_SIZE, 1);
	std::iota(byte_vector.begin(), byte_vector.end(), 1);

    for (auto &b : benchmarks) {
        b.time = runAndMeasure(b.func, b.times);
    }

    printf("Ignore this: %d\n", anti_optimizer);
    for (auto b : benchmarks) 
	{
		//if (b.times == BYTE_ACC_REPEATS)
		{
			printf("%s\t %d\n", b.name, b.time);
		}
    }
}


