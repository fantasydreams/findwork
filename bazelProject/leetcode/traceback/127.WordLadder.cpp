#include "127.WordLadder.h"
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

bool isAdj(const std::string& a, const std::string& b) {
    if(a.size() != b.size()) {
        return false;
    }

    int dcnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        dcnt += (a[i] != b[i]);
    }

    return dcnt == 1;
}


void bfs(const std::vector<std::vector<short>>& adjmetrix, std::vector<std::vector<short>>& parentmetrix, int begin) {
    parentmetrix[begin] = {(short)-1};
    std::queue<int> que; que.push(begin);
    std::vector<int> dist(5005, INT_MAX); dist[begin] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(auto v : adjmetrix[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                // printf("u %d v %d\n", u, v);
                parentmetrix[v] = {(short)u};
                que.push(v);
            }else if(dist[v] == dist[u] + 1) {
                parentmetrix[v].push_back(u);
            }
        }
    }
}

void dfs(const std::vector<std::vector<short> >& parentmetrix, int u, int& ans, bool& bFind) {
    if(u == -1) {
        bFind = true;
        return;
    }

    for(int i = 0; i < parentmetrix[u].size() && !bFind; ++i) {
        short v = parentmetrix[u].at(i);
        ans += 1;
        dfs(parentmetrix, v, ans, bFind);
        if(bFind) {
            return;
        }

        ans -= 1;
    }
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    short begin = -1, end = -1;
    for(int i = 0; i < wordList.size(); ++i) {
        if(beginWord == wordList[i]) {
            begin = i;
        }

        if(endWord == wordList[i]) {
            end = i;
        }
    }

    if(end == -1) {
        return 0;
    }

    if(begin == -1) {
        wordList.push_back(beginWord);
        begin = wordList.size() - 1;
    }

    std::vector<std::vector<short> > adjmetrix(5005, std::vector<short>()), parentmetrix(5005, std::vector<short>());

    for(int i = 0; i < wordList.size() - 1; ++i) {
        for(int j = i + 1; j < wordList.size(); ++j) {
            if(isAdj(wordList[i], wordList[j])) {
                adjmetrix[i].push_back(j);
                adjmetrix[j].push_back(i);
            }
        }
    }

    bfs(adjmetrix, parentmetrix, begin);
    int ans = 0;
    bool bfind = false;
    dfs(parentmetrix, end, ans, bfind);

    return ans;
}


bool isAdjStr(const std::string& a, const std::string& b) {
    if(a.length() != b.length()) {
        return false;
    }

    int dcnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        dcnt += (a[i] != b[i]);
    }

    return dcnt == 1;
}


void bfs(const std::vector<std::vector<int>>& adjmetrix, std::vector<std::vector<int>>& parentmetrix, int begin) {
    parentmetrix[begin] = {-1};
    std::queue<int> que; que.push(begin);
    std::vector<int> dist(505, INT_MAX); dist[begin] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(auto v : adjmetrix[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                // printf("u %d v %d\n", u, v);
                parentmetrix[v] = {u};
                que.push(v);
            }else if(dist[v] == dist[u] + 1) {
                parentmetrix[v].push_back(u);
            }
        }
    }
}

void bt(const std::vector<std::vector<int>>& parentmetrix, int u, int& ans, bool& bfind) {
    if(u == -1) {
        bfind = true;
        return;
    }

    for(auto v : parentmetrix[u]) {
        if(bfind) {
            return;
        }
        ans += 1;
        bt(parentmetrix, v, ans, bfind);
        if(bfind) {
            return;
        }
        ans -=1;
    }
}

int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
    int begin = -1, end = -1;
    for(int i = 0; i < wordList.size(); ++i) {
        if(wordList[i] == beginWord) {
            begin = i;
        }
        if(endWord == wordList[i]) {
            end = i;
        }
    }


    if(end == -1) {
        return 0;
    }

    if(begin == -1) {
        wordList.push_back(beginWord);
        begin = wordList.size() - 1;
    }

    std::vector<std::vector<int>> adjmetrix(5005, std::vector<int>()), parentmetrix(5005, std::vector<int>());
    for(int i = 0; i < wordList.size() - 1; ++i) {
        for(int j = i + 1; j < wordList.size(); ++j) {
            if(isAdjStr(wordList[i], wordList[j])) {
                adjmetrix[i].push_back(j);
                adjmetrix[j].push_back(i);
            }
        }
    }
    
    // printf(" end %d\n", end);
    bfs(adjmetrix, parentmetrix, begin);
    int ans = 0; bool bfind = false;
    bt(parentmetrix, end, ans, bfind);
    return ans;
}


// 广度优先搜索 
// https://leetcode.cn/problems/word-ladder/solutions/473600/dan-ci-jie-long-by-leetcode-solution/
// https://zhuanlan.zhihu.com/p/103996384
int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordList) {
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if(dict.count(endWord) == 0) {
        return 0;
    }

    std::queue<std::string> que;que.push(beginWord);
    int level = 0;
    while(!que.empty()) {
        ++level;
        int n = que.size();
        while(n--) {
            std::string sNext = que.front(); que.pop();
            for(int i = 0; i < beginWord.size(); ++i) {
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    char old = sNext[i];
                    sNext[i] = ch;
                    if(sNext == endWord) {
                        return level + 1;
                    }
                    
                    auto pIter = dict.find(sNext);
                    if(pIter != dict.end()) {
                        que.push(sNext);
                        dict.erase(pIter);
                    }

                    sNext[i] = old;
                }
            }
        }
    }

    return 0;
}

// 广度优先 【双向】 搜索
int ladderLengthBiBFS(string beginWord, string endWord, vector<string>& wordList) {
    std::unordered_set<std::string> setBegin, SetEnd, dict(wordList.begin(), wordList.end()); setBegin.insert(beginWord), SetEnd.insert(endWord);

    if(dict.count(endWord) == 0) {
        return 0;
    }

    int level = 0;
    while(!setBegin.empty() && !SetEnd.empty()) {
        if(setBegin.size() > SetEnd.size()) {
            swap(setBegin, SetEnd);
        }

        ++level;
        std::unordered_set<std::string> tmp;
        for(auto& str : setBegin) {
            std::string sNext = str;
            for(int i = 0; i < beginWord.size(); ++i) {
                char oldch = sNext[i];
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    sNext[i] = ch;
                    if(SetEnd.count(sNext)) {
                        return level + 1;
                    }

                    auto pIter = dict.find(sNext);
                    if(pIter != dict.end()) {
                        dict.erase(pIter);
                        tmp.insert(sNext);
                    }
                }
                sNext[i] = oldch;
            }
        }

        swap(tmp, setBegin);
    }

    return 0;
}


int ladderLengthBiBFS1(string beginWord, string endWord, vector<string>& wordList) {
    std::unordered_set<std::string> oWordDict(wordList.begin(), wordList.end()), setBegin, setEnd;
    setBegin.insert(beginWord); setEnd.insert(endWord);
    if(oWordDict.count(endWord) == 0) {
        return 0;
    }
    
    int iAns = 0;
    while(!setBegin.empty() && !setEnd.empty()) {
        if(setBegin.size() > setEnd.size()) {
            swap(setBegin, setEnd);
        }

        ++iAns;
        std::unordered_set<std::string> setTmp;
        for(const auto & word : setBegin) {
            for(int i = 0; i < word.size(); ++i) {
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    std::string sNewWord = word;
                    sNewWord[i] = ch;
                    if(sNewWord == word) {
                        continue;
                    }

                    if(setEnd.count(sNewWord)) {
                        return iAns + 1;
                    }

                    auto pIter = oWordDict.find(sNewWord);
                    if(pIter != oWordDict.end()) {
                        oWordDict.erase(pIter);
                        setTmp.insert(sNewWord);
                    }
                }
            }
        }
        swap(setTmp, setBegin);
    }

    return 0;
}