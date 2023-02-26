#include "326.PowerofThree.h"
#include <cmath>
using namespace std;

bool isPowerOfThree(int n) {
    return fmod(log10(n) / log10(3), 1) == 0;
}

bool isPowerOfThree1(int n) {
    return n <= 0 ? false : 1162261467 % n == 0;
}