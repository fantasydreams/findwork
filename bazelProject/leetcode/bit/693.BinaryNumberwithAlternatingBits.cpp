#include "693.BinaryNumberwithAlternatingBits.h"

bool hasAlternatingBits(int n) {
    uint32_t x = n ^ (n >> 1);
    return !(x & (x + 1));
}