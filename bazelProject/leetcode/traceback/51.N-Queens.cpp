#include "51.N-Queens.h"
#include <cmath>
#include <cstdlib>
#include <string>

vector<string> convert(const vector<int> & col)
{
    vector<string> res;
    for(int i = 0; i < col.size(); ++i)
    {
        string tmp(col.size(), '.');
        tmp[col[i]] = 'Q';
        res.push_back(tmp);
    }
    return res;
}

bool isvalid(const vector<int> & col, int new_col)
{
    for(int i = 0; i < col.size(); ++i)
    {
        // col[i] == new_col 是同一列上
        // 行-行=列-列
        if(abs(i - (int)col.size()) == abs(col[i] - new_col) || (col[i] == new_col)){
            return false;
        }
    }

    return true;
}

void traceback(int n, vector<vector<string>> & res, vector<int> & col)
{
    if(n == col.size()) 
    {
        res.push_back(convert(col));
        return;
    }

    for(int new_col = 0; new_col < n; ++new_col)
    {
        if(!isvalid(col, new_col)) {
            continue;
        }
        col.push_back(new_col);
        traceback(n, res, col);
        col.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<int> col;
    traceback(n, res, col);
    return res;
}


std::vector<std::string> conAns(std::vector<int>& col) {
    std::vector<std::string> ans;    
    for(int i = 0; i < col.size(); ++i) {
        std::string tmp(col.size(), '.');
        tmp[col[i]] = 'Q';
        ans.emplace_back(tmp);
    }
    return ans;
}

bool checkValid(const std::vector<int>& col, int new_col) {
    for(int i = 0; i < col.size(); ++i) {
        if(abs(i - (int)col.size()) == abs(new_col - col[i]) || col[i] == new_col) {
            return false;
        }
    }
    return true;
}

void dfs(int n, vector<vector<string> >& ans, std::vector<int> & col) {
    if(n == col.size()) {
        ans.emplace_back(conAns(col));
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!checkValid(col, i)) {
            continue;
        }

        col.push_back(i);
        dfs(n, ans, col);
        col.pop_back();
    }
}


vector<vector<string> > solveNQueens1(int n) // 2023/08/20
{
    vector<vector<string> >ans;
    vector<int> col;
    dfs(n, ans, col);
    return ans;
}