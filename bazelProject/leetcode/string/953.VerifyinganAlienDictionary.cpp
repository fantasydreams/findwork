#include "953.VerifyinganAlienDictionary.h"
#include <unordered_map>


bool stringcompare(const string & str1, const string & str2, std::unordered_map<char, int> & _map)
{
    size_t pos = std::min(str1.size(), str2.size());
    size_t idx = 0;
    while(idx < pos)
    {
        if(_map[str1[idx]] > _map[str2[idx]]) {
            return false;
        }else if(_map[str1[idx]] < _map[str2[idx]]) {
            return true;
        }
        ++idx;
    }

    if(idx < str1.size()) {
        return false;
    }
    return true;
}

bool isAlienSorted(vector<string>& words, string order)
{
    std::unordered_map<char, int> charmap;
    for(int i = 0; i < order.size(); ++i) {
        charmap[order[i]] = i;        
    }

    for(int i = 1; i < words.size(); ++i) 
    {
        if(stringcompare(words[i - 1], words[i], charmap) == false) {
            return false;
        }
    }

    return true;
}