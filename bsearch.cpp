#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "bsearch.h"

static int glyphCompareVoid(const void *a, const void *b) 
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

uint32_t bsearchHandCrafted(const glyph_info_t *glyph_array, size_t size, const glyph_info_t *to_be_found)
{
    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;

    while (first <= last) 
	{
        if (glyph_array[middle].glyph_number < to_be_found->glyph_number) {
            first = middle + 1;
        }
        else if (glyph_array[middle].glyph_number == to_be_found->glyph_number) {
            return middle;
        }
        else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }

    return size;
}

inline bool glyphCompareTyped(const glyph_info_t &i, const glyph_info_t &j)
{
	return (i.glyph_number < j.glyph_number);
}

struct GlyphComparatorFunctor
{
	inline bool operator()(const glyph_info_t &i, const glyph_info_t &j)
	{
		return (i.glyph_number < j.glyph_number);
	}
};

uint32_t bsearchC_Style(const glyph_info_t *glyph_array, size_t size, const glyph_info_t *to_be_found) 
{
    const glyph_info_t *found = (glyph_info_t *) bsearch(to_be_found, glyph_array, size, sizeof(glyph_info_t), glyphCompareVoid);
	return found ? std::distance(glyph_array, found) : size;
}

uint32_t bsearchFuncStlPlainArray(const glyph_info_t *glyph_array, size_t size, const glyph_info_t &to_be_found)
{
    const glyph_info_t *found = std::lower_bound(&glyph_array[0], &glyph_array[size], to_be_found, glyphCompareTyped);
    return std::distance(glyph_array, found);
}

uint32_t bsearchFunctorStlPlainArray(const glyph_info_t *glyph_array, size_t size, const glyph_info_t &to_be_found)
{
	const glyph_info_t *found = std::lower_bound(&glyph_array[0], &glyph_array[size], to_be_found, GlyphComparatorFunctor());
	return std::distance(glyph_array, found);
}

uint32_t bsearchLambdaStlPlainArray(const glyph_info_t *glyph_array, size_t size, const glyph_info_t &to_be_found)
{
	const glyph_info_t *found = std::lower_bound(&glyph_array[0], &glyph_array[size], to_be_found, [](const glyph_info_t &i, const glyph_info_t &j)->bool { return i.glyph_number < j.glyph_number; });
	return std::distance(glyph_array, found);
}

uint32_t bsearchFuncStlInVector(const std::vector<glyph_info_t> &glyph_vector, const glyph_info_t &to_be_found)
{
    std::vector<glyph_info_t>::const_iterator found = std::lower_bound(glyph_vector.begin(), glyph_vector.end(), to_be_found, glyphCompareTyped);
    return std::distance(glyph_vector.begin(), found);
}

uint32_t bsearchFunctorStlInVector(const std::vector<glyph_info_t> &glyph_vector, const glyph_info_t &to_be_found)
{
	std::vector<glyph_info_t>::const_iterator found = std::lower_bound(glyph_vector.begin(), glyph_vector.end(), to_be_found, GlyphComparatorFunctor());
	return std::distance(glyph_vector.begin(), found);
}

uint32_t bsearchLambdaStlInVector(const std::vector<glyph_info_t> &glyph_vector, const glyph_info_t &to_be_found)
{
	std::vector<glyph_info_t>::const_iterator found = std::lower_bound(glyph_vector.begin(), glyph_vector.end(), to_be_found, [](const glyph_info_t &i, const glyph_info_t &j)->bool { return i.glyph_number < j.glyph_number; });
	return std::distance(glyph_vector.begin(), found);
}