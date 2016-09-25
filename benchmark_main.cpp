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

template <typename T>
struct benchmark_definition_t 
{
    const char *name;
	const T expected_result;
    uint32_t times;
	std::function<T(void)> func;
    int32_t time;
};

std::vector<benchmark_definition_t<uint32_t>> benchmarks_bsearch =
{
    {"Manual binary search                  ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchHandCrafted, glyph_array, BSEARCH_DATA_SIZE, &to_be_found), -1},
    {"C Style binary search                 ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchC_Style, glyph_array, BSEARCH_DATA_SIZE, &to_be_found), -1},
    {"STL function binary search (array)    ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchFuncStlPlainArray, glyph_array, BSEARCH_DATA_SIZE, to_be_found), -1},
	{"STL functor binary search (array)     ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchFunctorStlPlainArray, glyph_array, BSEARCH_DATA_SIZE, to_be_found), -1 },
	{"STL lambda binary search (array)      ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchLambdaStlPlainArray, glyph_array, BSEARCH_DATA_SIZE, to_be_found), -1 },
	{"STL function binary search (vector)   ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchFuncStlInVector, glyph_vector, to_be_found), -1 },
	{"STL functor binary search (vector)    ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchFunctorStlInVector, glyph_vector, to_be_found), -1 },
	{"STL lambda binary search (vector)     ", BSEARCH_DATA_SIZE, BSEARCH_REPEATS,  std::bind(bsearchLambdaStlInVector, glyph_vector, to_be_found), -1 }
};

std::vector<benchmark_definition_t<uint64_t>> benchmarks_byte_accumulate =
{
	{"Byte accumulate (array, do/while)     ", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_HandCraftedDoWhilePtr, byte_array, BYTE_ACCUMULATE_DATA_SIZE), -1 },
	{"Byte accumulate (array, unrolled)     ", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_Unrolled, byte_array, BYTE_ACCUMULATE_DATA_SIZE), -1 },
	{"Byte accumulate (array, for)          ", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_HandCraftedForArray, byte_array, BYTE_ACCUMULATE_DATA_SIZE), -1 },
	{"Byte accumulate (array, for, unrolled)", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_HandCraftedForArray, byte_array, BYTE_ACCUMULATE_DATA_SIZE), -1 },
	{"Bbyte accumulate (array, STL)         ", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_StlPlainArary, byte_array, BYTE_ACCUMULATE_DATA_SIZE), -1 },
	{"Byte accumulate (vector, STL)         ", 34225520640, BYTE_ACC_REPEATS, std::bind(byteAccumulate_StlVector, byte_vector), -1 },
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

    for (auto &b : benchmarks_bsearch) 
	{
		if (checkResult(b.func, b.expected_result))
		{
			b.time = runAndMeasure(b.func, b.times);
		}
		else
		{
			printf("Invalid result in: %s\n", b.name);
			b.time = -1;
		}
    }

	for (auto &b : benchmarks_byte_accumulate)
	{
		if (checkResult(b.func, b.expected_result))
		{
			b.time = runAndMeasure(b.func, b.times);
		}
		else
		{
			printf("Invalid result in: %s\n", b.name);
			b.time = -1;
		}
	}

    for (auto b : benchmarks_bsearch)
	{
	    printf("%s\t %d\n", b.name, b.time);
    }

	for (auto b : benchmarks_byte_accumulate)
	{
		printf("%s\t %d\n", b.name, b.time);
	}

	system("pause");
}


