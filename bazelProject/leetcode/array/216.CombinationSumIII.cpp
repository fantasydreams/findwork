#include "216.CombinationSumIII.h"

void combinationSum3(int c, int k, int cur, int n, int s, std::vector<int>& vecTmp, vector<vector<int> >& vecAns) {
    if(c >= k) {
        if(cur == n) {
            vecAns.push_back(vecTmp);
        }
        return;
    }

    for(int i = s; i < 10; ++i) {
        vecTmp.push_back(i);
        combinationSum3(c + 1, k, cur + i, n, i + 1, vecTmp, vecAns);
        vecTmp.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    std::vector<int> vecTmp;
    std::vector<std::vector<int> > vecAns;
    combinationSum3(0, k, 0, n, 1, vecTmp, vecAns);
    return vecAns;
}