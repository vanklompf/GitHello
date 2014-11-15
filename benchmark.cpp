#include <algorithm>
#include <chrono>
#include <ctime>
//#include <thread>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <array>

struct glyph_info_t
{
    uint32_t glyph_number;
    uint32_t offset;
    uint16_t something_else;
};

#define ARRAY_SIZE(A) (sizeof(A)/sizeof(A[0]))

static const uint32_t HUGE_SIZE = 240000;
static const uint32_t HUGE_LOOP_COUNT = 1000000;

glyph_info_t glyph_array[HUGE_SIZE];
std::vector <glyph_info_t> glyph_vector(HUGE_SIZE);
std::array <glyph_info_t, HUGE_SIZE> glyph_STL_array;

uint32_t measure_time(void (*work)(void))
{
	std::chrono::steady_clock::time_point start, end;
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

int compareGlyph(const void * a, const void * b)
{
    if (((const glyph_info_t *) a)->glyph_number < ((const glyph_info_t *) b)->glyph_number)
  {
	  return -1;
  }
    else if (((const glyph_info_t *) a)->glyph_number == ((const glyph_info_t *) b)->glyph_number)
  {
	  return 0;
  }
  else
  {
	  return 1;
  }
}

static const glyph_info_t to_be_found = {1234567890, 0, 0};

void bsearch_huge()
{
	glyph_info_t* ptr;
	for(int i=0; i<HUGE_LOOP_COUNT; i++)
	{
        ptr = (glyph_info_t *) bsearch(&to_be_found, glyph_array, HUGE_SIZE, sizeof(glyph_info_t), compareGlyph);
	}
    printf("Found: %d\n", ptr - glyph_array);
}

void stl_bsearch_huge()
{
	glyph_info_t* ptr;
	for(int i=0; i<HUGE_LOOP_COUNT; i++)
	{
        ptr = std::lower_bound(&glyph_array[0], &glyph_array[HUGE_SIZE], to_be_found, glyph_compare);
	}
    printf("Found: %d\n", ptr - glyph_array);
}

void stl_bsearch_huge_vector()
{
	std::vector<glyph_info_t>::iterator ptr;
	for(int i=0; i<HUGE_LOOP_COUNT; i++)
	{
        ptr = std::lower_bound(glyph_vector.begin(), glyph_vector.end(), to_be_found, glyph_compare);
	}
    printf("Found: %d\n", ptr - glyph_vector.begin());
}

void manual_bsearch()
{
	int index_found;

	for (int i = 0; i < HUGE_LOOP_COUNT; i++)
	{
		int first = 0;
		int last = HUGE_SIZE - 1;
		int middle = (first + last) / 2;

		while (first <= last)
		{
            if (glyph_array[middle].glyph_number < to_be_found.glyph_number)
			{
				first = middle + 1;
			}
            else if (glyph_array[middle].glyph_number == to_be_found.glyph_number)
			{
				index_found = middle;
				break;
			}
			else
			{
				last = middle - 1;
			}
			middle = (first + last) / 2;
		}
	}
	printf("Found: %d\n", index_found);
}

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

int main()
{
	std::chrono::duration<double> bsearch_timing, stl_bsearch_timing, manual_timing;

    //fill arrays
    std::generate(&glyph_array[0], &glyph_array[HUGE_SIZE], FillGenerator(1));
    std::generate(glyph_vector.begin(), glyph_vector.end(), FillGenerator(1));
    std::generate(glyph_STL_array.begin(), glyph_STL_array.end(), FillGenerator(1));

    printf("bsearch_huge: %d\n", measure_time(bsearch_huge));
	printf("stl_bsearch_huge_vector: %d\n", measure_time(stl_bsearch_huge_vector));
    printf("stl_bsearch_huge: %d\n", measure_time(stl_bsearch_huge));
	printf("manual_bsearch: %d\n", measure_time(manual_bsearch));

    printf("stl_bsearch_huge: %d\n", measure_time(stl_bsearch_huge));
    printf("stl_bsearch_huge_vector: %d\n", measure_time(stl_bsearch_huge_vector));


}




