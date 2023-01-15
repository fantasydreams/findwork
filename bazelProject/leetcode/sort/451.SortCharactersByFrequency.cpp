#include "451.SortCharactersByFrequency.h"
#include <unordered_map>
#include <vector>
#include <cmath>
#include <functional>
#include <map>

string frequencySort(string s)
{
    std::unordered_map<int, int> mapCnt;
    for(const auto & ch : s) {
        ++mapCnt[ch];
    }

    std::map<int, std::string, std::greater<int>> mapFreq2Ch;
    for(const auto & oPair : mapCnt) {
        mapFreq2Ch[oPair.second] += std::string(oPair.second, oPair.first);
    }

    std::string sRes;
    for(const auto & oPair : mapFreq2Ch) {
        sRes += oPair.second;
    }

    return sRes;
}