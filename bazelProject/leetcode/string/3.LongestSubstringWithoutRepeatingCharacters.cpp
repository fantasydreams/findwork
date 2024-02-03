#include "3.LongestSubstringWithoutRepeatingCharacters.h"
#include <map>
#include <set>
#include <unordered_set>

void printMap(const std::map<char,size_t> & Map)
{
    auto iter = Map.begin();
    while(iter != Map.end())
    {
        printf("%c %lu ", iter->first, iter->second);
        ++iter;
    }
}

int lengthOfLongestSubstring(std::string s) 
{
    int64_t start = 0;
    int maxLen = 0;

    std::map<char, size_t> idxMap;

    for(size_t i = 0; i < s.size(); ++i)
    {
        if(idxMap.find(s[i]) == idxMap.end())
        {
            idxMap[s[i]] = i;
            if(maxLen < i - start + 1){
                maxLen = i - start + 1;
            }
        }else
        {
            auto iRepeat = idxMap[s[i]];
            for(int idx = start; idx < iRepeat; ++idx)
            {
                auto iter = idxMap.find(s[idx]);
                idxMap.erase(iter);
            }
            // printMap(idxMap);

            start = iRepeat + 1;
            idxMap[s[i]] = i;
        }
    }
    return maxLen;        
}



int lengthOfLongestSubstringWithSet(std::string s) 
{
    int maxLen = 0;
    size_t start = 0;
    std::set<char> cSet;
    for(size_t i = 0; i< s.size(); ++i)
    {
        while(true)
        {
            if(cSet.find(s[i]) != cSet.end())
            {
                auto iter =cSet.find(s[start++]);
                cSet.erase(iter);
            }else{
                break;
            }
        }
        cSet.insert(s[i]);
        maxLen = (i - start + 1) > maxLen ? (i - start + 1) : maxLen;
    }
    return maxLen;
}

int lengthOfLongestSubstringWithSet1(std::string s) 
{  
    std::unordered_set<char> eSet;
    int start = 0, maxLen = 0, i = 0;
    while(i < s.size()) {
        if(eSet.count(s[i]) == 0) {
            eSet.insert(s[i++]);
            maxLen = std::max(maxLen, (int)eSet.size());
        }else {
            while(s[start] != s[i]) {
                eSet.erase(s[start]);
                ++start;
            }
            eSet.erase(s[start++]);
        }
    }

    return maxLen;
}

int lengthOfLongestSubstringWithBitMap(std::string s) {
    std::vector<bool> bitmap(256, false);
    int iLeft = 0, iRight = 0, ans = 0;
    while(iRight < s.size()) {
        if(bitmap[s[iRight]] == true) {
            bitmap[s[iLeft]] = false;
            ++iLeft;
        }else {
            bitmap[s[iRight]] = true;
            ans = std::max(ans, iRight - iLeft + 1);
            ++iRight;
        }
    }

    return ans;
}

int lengthOfLongestSubstringWithWindow(std::string s) {
    int iLeft = 0, iRight = 0, ans = 0;
    std::vector<int> freq(256, 0);
    while(iRight < s.size()) {
        if(freq[s[iRight]] == 0) {
            ++freq[s[iRight]];
            ++iRight;
            ans = std::max(ans, iRight - iLeft);
        }else {
            --freq[s[iLeft]];
            ++iLeft;
        }
    }
    return ans;
}


int lengthOfLongestSubstringWithWindow1(std::string s) {
    int left = 0, right = 0, ans = 0;
    std::vector<int> vec(256, 0);
    while(right < s.size()) {
        if(vec[s[right]] == 0) {
            ans = std::max(ans, right - left + 1);
            ++vec[s[right++]];
        }else {
            --vec[s[left++]];
        }
    }

    return ans;
}