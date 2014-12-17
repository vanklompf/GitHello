#include <vector>
#include <functional>
#include <cstdio>
#include <algorithm>
#include "bsearch.h"
#include "benchmark_utils.h"

#ifdef __arm__
static const int32_t BSEARCH_REPEATS = 500000;
static const int32_t BSEARCH_DATA_SIZE = 9600000;
#else
static const int32_t BSEARCH_REPEATS = 5000000;
static const int32_t BSEARCH_DATA_SIZE = 4800000;
#endif

typedef uint32_t(*benchmark_func)();

static glyph_info_t glyph_array[BSEARCH_DATA_SIZE];
static std::vector<glyph_info_t> glyph_vector(BSEARCH_DATA_SIZE);
static const glyph_info_t to_be_found = {0xFFFFFFFF, 0, 0};
static uint32_t anti_optimizer;

struct benchmark_definition_t {
    const char *name;
    uint32_t times;
    void(*func)();
    int32_t time;
};

std::vector<benchmark_definition_t> benchmarks =
        {
                {"Hand crafted binary search", BSEARCH_REPEATS, []() {
                    anti_optimizer += bsearchHandCrafted(glyph_array, BSEARCH_DATA_SIZE, &to_be_found);
                }, -1},
                {"C Style binary search     ", BSEARCH_REPEATS, []() {
                    anti_optimizer += bsearchC_Style(glyph_array, BSEARCH_DATA_SIZE, &to_be_found);
                }, -1},
                {"STL binary search (array) ", BSEARCH_REPEATS, []() {
                    anti_optimizer += bsearchStlPlainArray(glyph_array, BSEARCH_DATA_SIZE, to_be_found);
                }, -1},
                {"STL binary search (vector)", BSEARCH_REPEATS, []() {
                    anti_optimizer += bsearchStlInVector(glyph_vector, to_be_found);
                }, -1},
        };


struct FillGenerator {
    glyph_info_t m_glyph;

    FillGenerator(uint32_t start) {
        m_glyph.glyph_number = start;
    };

    glyph_info_t operator()() {
        m_glyph.glyph_number++;
        return m_glyph;
    }
};

int main() {
    std::generate(glyph_array, glyph_array + BSEARCH_DATA_SIZE, FillGenerator(0));
    std::generate(glyph_vector.begin(), glyph_vector.end(), FillGenerator(0));

    for (auto &b : benchmarks) {
        b.time = runAndMeasure(b.func, b.times);
    }

    printf("Ignore this: %d\n", anti_optimizer);
    for (auto b : benchmarks) {
        printf("%s\t %d\n", b.name, b.time);
    }

    //std::getchar();
}


