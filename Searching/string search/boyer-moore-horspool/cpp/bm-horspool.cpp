#include <cstdint>
#include <cstring>
#include <array>
#include <algorithm>

uint8_t* bm_horspool(uint8_t *source, const char* pattern, uint32_t size, uint32_t pattern_size) {

    if(pattern_size > size) 
        return nullptr;

    std::array<uint32_t, 256> lookup_table;
    std::fill(lookup_table.begin(), lookup_table.end(), pattern_size);

    for(uint32_t i = 0; i < pattern_size - 1; i++)
        lookup_table[pattern[i]] = pattern_size - i - 1;

    uint32_t offset = 0;
    while(offset <= size - pattern_size)
    {
        uint8_t c = source[offset + pattern_size - 1];
        if(pattern[pattern_size - 1] == c &&
            std::memcmp(pattern, source + offset, pattern_size - 1) == 0)
            return source + offset;

        offset += lookup_table[c];
    }

    return nullptr;
}
