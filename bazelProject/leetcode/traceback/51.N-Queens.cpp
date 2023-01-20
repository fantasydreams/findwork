#include "51.N-Queens.h"
#include <cmath>

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