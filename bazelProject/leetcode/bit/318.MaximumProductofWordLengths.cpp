#include "318.MaximumProductofWordLengths.h"
#include <unordered_map>

int maxProduct(vector<string>& words) {
    std::unordered_map<int, int> hash;

    int ans = 0;
    for(const auto & str : words) {        
        int mask = 0, len = str.length();
        for(const auto & ch : str) {
            mask |= 1 << (ch - 'a');
        }

        hash[mask] = max(hash[mask], len);
        for(const auto & [_mask, _size] : hash) {
            if(!(mask & _mask)) {
                ans = max(ans, hash[mask] * _size);
            }
        }
    }   

    return ans;
}