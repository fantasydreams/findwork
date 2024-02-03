#include "30.SubstringwithConcatenationofAllWords.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>


// https://www.cnblogs.com/grandyang/p/4521224.html
//https://biaodigit.github.io/LeetCode/0030/#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF
vector<int> findSubstring(string s, vector<string>& words) {
    std::vector<int> ans;
    if(words.empty() || words[0].empty() || s.empty()) {
        return ans;
    }
    
    int wordlen = words[0].size();
    int k = (int)s.size() - (int)words.size() * (int)wordlen;

    std::unordered_map<std::string, int> wordmap;
    for(const auto& word : words) {
        wordmap[word]++;
    }

    for(int i = 0; i <= k; ++i) { // 这里k一定要注意是<= 边界值
        int j = 0;
        std::unordered_map<std::string, int> tmpmap = wordmap;
        // std::unordered_map<std::string, int> tmpmap;
        while(j < words.size()) {
            std::string sTmp = s.substr(i + j * wordlen, wordlen);
            auto pIter = tmpmap.find(sTmp);
            if(pIter == tmpmap.end()) {
                break;
            }
            if((pIter->second)-- == 0) {
                break;
            }

            // if(wordmap.count(sTmp) == 0) {
            //     break;
            // }

            // if(++tmpmap[sTmp] > wordmap[sTmp]) {
            //     break;
            // }
            j++;
        }
        if(j == words.size()) {
            ans.push_back(i);
        }
    }

    return ans;
}

// 滑动窗口
// https://blog.csdn.net/m0_53157173/article/details/117874913
vector<int> findSubstringWindow(string s, vector<string>& words) {
    std::vector<int> ans;
    if(s.empty() || words.empty() || words[0].empty()) {
        return ans;
    }

    unordered_map<std::string, int> dict, stmpDict;
    for(const auto& word : words) {
        ++dict[word];
    }

    int wordlen = words[0].size();
    int wordnum = words.size();
    int len = s.size();
    for(int i = 0; i < wordlen; ++i) {
        int start = i, j = i;
        while(start <= len - wordnum * wordlen) {
            while(j < start + wordlen * wordnum) {
                std::string stmp = s.substr(j, wordlen);
                j += wordlen;
                ++stmpDict[stmp];
                if(dict.count(stmp) == 0) { // 字符不存在，窗口前面的无效
                    stmpDict.clear();
                    start = j;
                    break;
                }else if(stmpDict[stmp] > dict[stmp]) { // 比较组成的多，这种情况要挪动，把当前多的挪走
                    while(stmpDict[stmp] > dict[stmp]) {
                        --stmpDict[s.substr(start, wordlen)];
                        start += wordlen;
                    }
                    break;
                }
            }

            if(j == start + wordlen * wordnum) {
                ans.push_back(start);
                --stmpDict[s.substr(start, wordlen)];
                start += wordlen;
            }
        }
        stmpDict.clear();
    }

    return ans;
}


vector<int> findSubstringHashMap(string s, vector<string>& words) {
    vector<int> vecAns;
    if(s.empty() || words.empty() || words[0].empty()) {
        return vecAns;
    }

    std::unordered_map<std::string, uint32_t> wordCnt;
    for(const auto& sWord : words) {
        ++wordCnt[sWord];
    }

    for(int i = 0; i <= (int64_t)(s.size() - words.size() * words[0].length()); ++i) {
        // printf("idx %d s %d\n", i, s.size());
        std::unordered_map<std::string, uint32_t> tmpWordCnt = wordCnt;
        for(int k = 0; k < words.size() && i + (k + 1) * words[0].length() <= s.length(); ++k) {
            const std::string& sSubStr = s.substr(i + k * words[0].length(), words[0].length());
            auto pIter = tmpWordCnt.find(sSubStr);
            if(pIter == tmpWordCnt.end()) {
                break;
            }
            if(--pIter->second == 0) {
                tmpWordCnt.erase(pIter);
            }
        }
        
        if(tmpWordCnt.empty()) {
            vecAns.push_back(i);
        }
    }

    return vecAns;
}


vector<int> findSubstringSlidingWindow(string s, vector<string>& words) {
    vector<int> vecAns;
    if(s.empty() || words.empty() || words[0].empty()) {
        return vecAns;
    }

    int wordCnt = words.size();
    int wordLen = words[0].length();
    int strLen = s.length();

    std::unordered_map<std::string, int> wordCntMap, tmpWordCntMap;
    for(const auto& sWord : words) {
        ++wordCntMap[sWord];
    }

    for(int i = 0; i < wordLen; ++i) {
        int start = i, end = i;
        while(start <= strLen - wordCnt * wordLen) {
            while(end < start + wordCnt * wordLen) {
                const std::string& sSubStr = s.substr(end, wordLen);
                auto pIter = wordCntMap.find(sSubStr);
                end += wordLen;
                if(pIter == wordCntMap.end()) {
                    tmpWordCntMap.clear();
                    start = end;
                    break;
                }

                ++tmpWordCntMap[sSubStr];
                if(tmpWordCntMap[sSubStr] > pIter->second) {
                    while(tmpWordCntMap[sSubStr] > pIter->second) {
                        --tmpWordCntMap[s.substr(start, wordLen)];
                        start += wordLen;
                    }
                    break;
                }
            }
            
            if(end == start + wordCnt * wordLen) {
                vecAns.push_back(start);
                --tmpWordCntMap[s.substr(start, wordLen)];
                start += wordLen;
            }
        }

        tmpWordCntMap.clear();
    }    

    return vecAns;
}