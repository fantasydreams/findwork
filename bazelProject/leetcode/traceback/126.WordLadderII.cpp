#include "126.WordLadderII.h"
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <queue>
#include <algorithm>

void backtrace(string & beginWord, string & endWord, std::unordered_map<std::string, std::vector<std::string>> & next, std::vector<std::vector<std::string>> & res, std::vector<std::string> & path)
{
    if(beginWord == endWord) 
    {
        res.push_back(path);
        return;
    }

    for(auto & word : next[beginWord])
    {
        path.push_back(word);
        backtrace(word, endWord, next, res, path);
        path.pop_back();
    }
}


// 这种方式要去搜索所有的情况，容易超时
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    std::vector<std::vector<std::string>> res;

    std::unordered_map<std::string, std::vector<std::string>> next;
    std::unordered_set<std::string> wordmap(wordList.begin(), wordList.end());
    if(wordmap.count(endWord) == 0) {
        return res;
    }

    wordmap.erase(beginWord);
    wordmap.erase(endWord);

    bool found = false, reverse = false;
    std::unordered_set<std::string> setbegin{beginWord}, setend{endWord}, settmp;
    while(setbegin.size())
    {
        settmp.clear();
        for(const auto & word : setbegin)
        {
            std::string nextword = word;
            for(int i = 0; i < word.size(); ++i)
            {
                for(char ch = 'a'; ch <= 'z'; ++ch)
                {
                    if(word[i] == ch) {
                        continue;
                    }

                    nextword[i] = ch;
                    if(setend.count(nextword))
                    {
                        reverse ? next[nextword].push_back(word) : next[word].push_back(nextword);
                        found = true;
                    }
                    if(wordmap.count(nextword))
                    {
                        reverse ? next[nextword].push_back(word) : next[word].push_back(nextword);
                        settmp.insert(nextword);
                    }
                }
                nextword[i] = word[i];
            }
        }

        if(found) {
            break;
        }

        for(const auto & word : settmp) {
            wordmap.erase(word);
        }

        if(settmp.size() <= setend.size()) {
            setbegin = settmp;
        }else 
        {
            reverse = !reverse;
            setbegin = setend;
            setend = settmp;
        }
    }

    if(found)
    {
        std::vector<std::string> path{beginWord};
        backtrace(beginWord, endWord, next, res, path);
    }
    return res;
}

bool isAdj(const string & a, const string & b)
{
    if(a.size() != b.size()) return false;
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        cnt += (a[i] != b[i]);
    }

    return cnt == 1;
}

void bfs(int begin, std::vector<std::vector<int>> & parent, const std::vector<std::vector<int>> & adjmetrix)
{
    std::vector<int> dist(505, INT_MAX);
    dist[begin] = 0;
    std::queue<int> q;
    q.push(begin);
    parent[begin] = {-1};
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adjmetrix[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = {u};
                q.push(v);
            }else if(dist[v] == dist[u] + 1) {
                parent[v].push_back(u);
            }
        }
    }
}

void dfs(const vector<string> & wordList, const std::vector<std::vector<int>> & parent, int u, vector<vector<string>> & ans, vector<int> & path)
{
    if(u == -1)
    {
        std::vector<std::string> tmp(path.size() - 1);
        std::transform(path.rbegin() + 1, path.rend(), tmp.begin(), [&](int i) {return wordList[i];});
        ans.push_back(move(tmp));
        return;
    }

    for(auto & v : parent[u])
    {
        path.push_back(v);
        dfs(wordList, parent, v, ans, path);
        path.pop_back();
    }
}

// 使用单词列表初始化邻接矩阵
vector<vector<string>> findLadders1(string beginWord, string endWord, vector<string>& wordList)
{
    int begin = -1, end = -1, n = wordList.size();
    std::vector<std::vector<std::string>> ans;
    for(int i = 0; i < wordList.size(); ++i)
    {
        if(wordList[i] == beginWord) {
            begin = i;
        }
        if(wordList[i] == endWord) {
            end = i;
        }
    }

    if(end == -1) {
        return ans;
    }
    if(begin == -1) 
    {
        wordList.push_back(beginWord);
        begin = n++;
    }

    std::vector<std::vector<int>> adjmetrix(505, std::vector<int>()), parentmetrix(505, std::vector<int>());
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(isAdj(wordList[i], wordList[j]))
            {
                adjmetrix[i].push_back(j);
                adjmetrix[j].push_back(i);
            }
        }
    }

    bfs(begin, parentmetrix, adjmetrix);
    std::vector<int> path{end};
    dfs(wordList, parentmetrix, end, ans, path);

    return ans;
}

    