#ifndef BSEARCH_H
#define BSEARCH_H

#include <array>

struct glyph_info_t {
    uint32_t glyph_number;
    uint32_t offset;
    uint16_t something_else;
};

inline bool glyphCompareTyped(const glyph_info_t &i, const glyph_info_t &j)
{
	return (i.glyph_number < j.glyph_number);
}
int bsearchHandCrafted(const glyph_info_t *glyph_array, size_t size, const glyph_info_t *to_be_found);

int bsearchC_Style(const glyph_info_t *glyph_array, size_t size, const glyph_info_t *to_be_found);

int bsearchStlPlainArray(const glyph_info_t *glyph_array, size_t size, const glyph_info_t &to_be_found);

int bsearchStlInVector(const std::vector<glyph_info_t> &glyph_vector, const glyph_info_t &to_be_found);

template<size_t ARRAY_SIZE>
int bsearchStlContainerArray(const std::array<glyph_info_t *, ARRAY_SIZE> glyph_array, const glyph_info_t &to_be_found) {
    const glyph_info_t *found = std::lower_bound(glyph_array.begin, glyph_array.end(), to_be_found, glyphCompareTyped);
    return std::distance(glyph_array.begin(), found);
}


#endif /* BSEARCH_H */