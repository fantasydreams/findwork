#include "60.PermutationSequence.h"
#include <vector>
#include <algorithm>

string getPermutation(int n, int k) {
    std::vector<int> per;
    per.reserve(n);
    for(int i = 1; i <= n; ++i) {
        per.push_back(i);
    }

    for(int i = 0; i < k - 1; ++i) {
        next_permutation(per.begin(), per.end());
    }

    std::string ans;
    for(int i = 0; i < per.size(); ++i) {
        ans += '0' + per[i];
    }

    return ans;
}

void getNextPermuation(std::vector<int>& vec) {
    int i = vec.size() - 2;
    while(i >= 0 && vec[i + 1] <= vec[i]) {
        --i;
    }

    if(i >= 0) {
        int k = vec.size() - 1;
        while(k > i && vec[k] <= vec[i]) {
            --k;
        }
        swap(vec[i], vec[k]);
    }
    reverse(vec.begin() + i + 1, vec.end());
}

string getPermutation1(int n, int k) {
    std::vector<int> per;
    per.reserve(n);
    for(int i = 1; i <= n; ++i) {
        per.push_back(i);
    }

    for(int i = 0; i < k - 1; ++i) {
        getNextPermuation(per);
    }

    std::string ans;
    for(int i = 0; i < per.size(); ++i) {
        ans += '0' + per[i];
    }

    return ans;
}