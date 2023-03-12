#include "313.SuperUglyNumber.h"
#include <map>

int nthSuperUglyNumber(int n, vector<int>& primes) {
    if(n == 1) {
        return 1;
    }
    
    int ans = 1, cnt = 1;
    std::sort(primes.begin(), primes.end());
    std::vector<int> ugly(n, 1); 
    std::vector<int> idx(primes.size(), 0);

    while(cnt < n) {
        long tmp = INT_MAX;
        for(int i = 0; i < primes.size(); ++i) {
            tmp = std::min(tmp, (long)primes[i] * ugly[idx[i]]);
        }        

        ugly[cnt++] = tmp;
        for(int i = 0; i < primes.size(); ++i) {
            if(tmp == (long)primes[i] * ugly[idx[i]]) {
                ++idx[i];
            }
        }
    }

    return ugly[n - 1];
}