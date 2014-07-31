#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include <stdlib.h>

struct glyph_info_t
{
    uint32_t glyph_number;
    uint32_t offset;
    uint16_t something_else;
};

#define ARRAY_SIZE(A) (sizeof(A)/sizeof(A[0]))

static std::default_random_engine generator;
static std::uniform_int_distribution<int> distribution(1,0xAFFFFFFF);
static auto randomize_glyph = std::bind( distribution, generator );

static const uint32_t HUGE_SIZE = 2550000;
glyph_info_t glyph_array_small[255];
glyph_info_t glyph_array_huge[HUGE_SIZE];

uint32_t measure_time(void (*work)(void))
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
    start = std::chrono::steady_clock::now();

    work();

    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count();
}

bool glyph_compare(const glyph_info_t& i, const glyph_info_t& j)
{
    return (i.glyph_number < j.glyph_number);
}

void fill_glyph_array(glyph_info_t* array, size_t size)
{
	int i;
    for(i=0; i<size; i++)
    {
    	array[i].glyph_number = i*2;
    }

    //std::sort(&array[0], &array[size], glyph_compare);
}

int compareGlyph(const void * a, const void * b)
{
  if ( ((glyph_info_t*)a)->glyph_number < ((glyph_info_t*)b)->glyph_number )
  {
	  return -1;
  }
  else if ( ((glyph_info_t*)a)->glyph_number == ((glyph_info_t*)b)->glyph_number )
  {
	  return 0;
  }
  else
  {
	  return 1;
  }
}

static const glyph_info_t to_be_found = {1234, 0, 0};
static const uint32_t HUGE_LOOP_COUNT = 10000000;

void bsearch_huge()
{
	for(int i=0; i<HUGE_LOOP_COUNT; i++)
	{
	    glyph_info_t* ptr = (glyph_info_t*)bsearch(&to_be_found, glyph_array_huge, HUGE_SIZE, sizeof(glyph_info_t), compareGlyph);
	}
}

void stl_bsearch_huge()
{
	for(int i=0; i<HUGE_LOOP_COUNT; i++)
	{
		std::lower_bound(&glyph_array_huge[0], &glyph_array_huge[HUGE_SIZE], to_be_found, glyph_compare);
	}
}

int main()
{
	std::chrono::duration<double> bsearch_timing, stl_bsearch_timing, manual_timing;


	fill_glyph_array(glyph_array_small, ARRAY_SIZE(glyph_array_small));
	fill_glyph_array(glyph_array_huge, ARRAY_SIZE(glyph_array_huge));

    printf("bsearch_huge: %d\n", measure_time(bsearch_huge));
    printf("stl_bsearch_huge: %d\n", measure_time(stl_bsearch_huge));
}




