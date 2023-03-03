#include "342.PowerofFour.h"

bool isPowerOfFour(int n) {
    if(n <= 0) {
        return false;
    }

    bool bPowerOfTwo = !((n) & ((n - 1)));
    int loc = 0;
    if(bPowerOfTwo) {
        while(n) {
            ++loc;
            n >>= 1;
        }

        if(loc & 0x1) {
            return true;
        }
    }
    return false;
}