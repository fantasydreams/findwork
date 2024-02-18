#include "383.RansomNote.h"

bool canConstruct(string ransomNote, string magazine) {
    std::vector<int> vecHash(128, 0);
    for(const auto& ch : magazine) {
        ++vecHash[ch];
    }

    for(const auto& ch : ransomNote) {
        if(--vecHash[ch] < 0) {
            return false;
        }
    }
    return true;
}