#include "217.ContainsDuplicate.h"
#include <unordered_set>

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hash;
    for(const auto & num : nums) {
        if(hash.count(num)) {
            return true;
        }
        hash.insert(num);
    }
    return false;
}