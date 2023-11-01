#include "187.RepeatedDNASequences.h"
#include <string>
#include <unordered_set>

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<std::string> setOld, setAns;
    for(int i = 9; i < s.size(); ++i) {
        std::string stmp = s.substr(i - 9, 10);
        auto pIter = setOld.insert(stmp);
        if(!pIter.second) {
            setAns.insert(stmp);
        }
    }

    return std::vector<std::string>(setAns.begin(), setAns.end());
}