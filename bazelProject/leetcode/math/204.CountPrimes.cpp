#include "204.CountPrimes.h"
#include <vector>

int countPrimes(int n) {
    if(n <= 2) {
        return 0;
    }

    std::vector<bool> prime(n, true);
    int ans = 0, cnt = n - 2;
    for(int i = 2; i < n; ++i) {
        if(prime[i] == true) {
            ++ans;
            for(int j = i + 1; j < n; ++j) {
                if(prime[j] == true && (j % i == 0)) {
                    prime[j] = false;
                    --cnt;
                }
            }
        }
    }
    
    return cnt;
}

int countPrimes1(int n) {
    if(n <= 2) {
        return 0;
    }

    std::vector<bool> prime(n, true);
    int ans = 0, cnt = n - 2;
    for(int i = 2; i < n; ++i) {
        if(prime[i] == true) {
            ++ans;
            for(int j = i + 1; j < n; ++j) {
                if(prime[j] == true && (j % i == 0)) {
                    prime[j] = false;
                    --cnt;
                }
            }
        }
    }
    
    return ans;
}

int countPrimes2(int n) {
    if(n <= 2) {
        return 0;
    }

    std::vector<bool> prime(n, true);
    int ans = 0;
    for(int i = 2; i < n; ++i) {
        if(prime[i] == true) {
            ++ans;
            for(int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    
    return ans;
}


int countPrimes3(int n) {
    if(n <= 2) {
        return 0;
    }

    int ans = 0;
    std::vector<bool> prime(n, true);
    for(int i = 2; i < n; ++i) {
        if(prime[i]) {
            ++ans;
            for(int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return ans;
}