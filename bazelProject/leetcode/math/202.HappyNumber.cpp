#include "202.HappyNumber.h"
#include <cmath>
#include <unordered_map>
#include <unordered_set>

int nextNum(int n) {
    int ans = 0, mod;
    while(n) {
        mod = n % 10;
        n /= 10;
        ans += pow(mod, 2);
    }
    return ans;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = nextNum(slow);
        fast = nextNum(nextNum(fast));
    }while(slow != fast);
    if(slow == 1) {
        return true;
    } else { 
        return false;
    }
}

bool isHappyMap(int n) {
    std::unordered_set<int> setRecord;
    while(n != 1) {
        if(setRecord.count(n)) {
            return false;
        }
        setRecord.insert(n);
        n = nextNum(n);
    }

    return true;
}


bool isHappyHash(int n) {
    if(n <= 0) {
        return false;
    }

    std::unordered_set<int> hash;
    while(n != 1) {
        auto oPair = hash.insert(n);
        if(oPair.second == false) {
            return false;
        }

        n = nextNum(n);
    }

    return true;
}


bool isHappyHash1(int n) {
    if(n <= 0) {
        return false;
    }

    std::unordered_set<int> map;
    while(n != 1) {
        auto oPair = map.find(n);
        if(oPair != map.end()) {
            return false;
        }
        map.insert(n);
        n = nextNum(n);
    }

    return true;
}