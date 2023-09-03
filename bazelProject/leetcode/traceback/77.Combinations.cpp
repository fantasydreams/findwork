#include "77.Combinations.h"


void traceback(int n, int k, int pos, vector<vector<int>> & res, vector<int> & tmp)
{
    if(k == tmp.size()) 
    {
        res.push_back(tmp);
        return;
    }

    for(int i = pos; i < n; ++i)    
    {
        tmp.push_back(i + 1);
        traceback(n, k, i + 1, res, tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> tmp;
    traceback(n, k, 0, res, tmp);
    return res;
}

void traceback1(int n, int k, int cnt, int pos, vector<vector<int>> & res, vector<int> & tmp)
{
    if(cnt == k) 
    {
        res.push_back(tmp);
        return;
    }

    for(int i = pos; i < n; ++i)    
    {
        tmp[cnt] = (i + 1);
        traceback1(n, k, cnt + 1, i + 1, res, tmp);
    }
}

vector<vector<int>> combine1(int n, int k)
{
    vector<vector<int>> res;
    vector<int> tmp(k, 0);
    int cnt = 0;
    traceback1(n, k, cnt, 0, res, tmp);
    return res;
}

void dfs(vector<vector<int> >& ans, int n, int pos, int cnt, std::vector<int>& tmp) {
    if(cnt == tmp.size()) {
        ans.push_back(tmp);
        return;
    }

    for(int i = pos; i < n; ++i) {
        tmp[cnt] = i + 1;
        dfs(ans, n, i + 1, cnt + 1, tmp);
    }
}

vector<vector<int> > combine2(int n, int k) // 2023 / 09 / 03
{
    std::vector<std::vector<int> > res;
    std::vector<int> tmp(k, 0);
    dfs(res, n, 0, 0, tmp);
    return res;
}