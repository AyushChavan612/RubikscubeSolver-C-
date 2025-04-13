#ifndef RUBIKS_CUBE_SOLVER_NIBBLEARRAY_H
#define RUBIKS_CUBE_SOLVER_NIBBLEARRAY_H

#include <vector>
#include <cstdint>
#include <cassert>
#include <algorithm>

using namespace std;

class NibbleArray {
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    void set(const size_t pos, const uint8_t val);

    uint8_t* data();

    const uint8_t* data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t>& dest) const;

    void reset(const uint8_t val = 0xFF);
};

#endif
