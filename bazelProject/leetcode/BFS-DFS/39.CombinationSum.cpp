#include "39.CombinationSum.h"
#include <ctime>
#include <vector>

void dfs(const vector<int>&candidates, int idx, int cur, int target, vector<int>& tmp, vector<vector<int> >& ans) {
    if(idx < 0 || idx >= candidates.size()) {
        return;
    }

    if(cur > target) {
        return;
    }

    if(cur == target) {
        ans.push_back(tmp);
        return;
    }

    for(int i = idx; i < candidates.size(); ++i) {
        tmp.push_back(candidates[i]);
        dfs(candidates, i, cur + candidates[i], target, tmp, ans);
        tmp.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    vector<int> tmp;
    dfs(candidates, 0, 0, target, tmp, ans);
    return ans;
}

void traceback(vector<int>& candidates, int target, int pos, int curSum, vector<int>& tmp, vector<vector<int> >& vecAns) {
    if(curSum == target) {
        vecAns.push_back(tmp);
        return;
    }
    if(curSum > target) {
        return;
    }

    for(int i = pos; i < candidates.size(); ++i) {
        tmp.push_back(candidates[i]);
        traceback(candidates, target, i, curSum + candidates[i], tmp, vecAns);
        tmp.pop_back();
    }
}

vector<vector<int> > combinationSum1(vector<int>& candidates, int target) {
    vector<vector<int> >vecAns;
    vector<int> tmp;
    traceback(candidates, target, 0, 0, tmp, vecAns);
    return vecAns;
}