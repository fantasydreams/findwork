#include "40.CombinationSumII.h"
#include <algorithm>

void traceback(vector<int> & candidates, int target, vector<int> & tmp, int pos, int sum, vector<vector<int>> & ans, vector<bool> & picked)
{
    if(target == sum) 
    {
        ans.push_back(tmp);
        return;
    }

    if(pos >= candidates.size() || candidates[pos] > target || sum > target) {
        return;
    }
    
    if((pos > 0 && (candidates[pos] == candidates[pos - 1]) && (!picked[pos - 1]))) { //如果说有重复的且重复的第一个元素还没有被使用，则这个元素也不使用    
        traceback(candidates, target, tmp, pos + 1, sum, ans, picked); //不使用这个元素    
    }else
    {
        //使用这个元素
        picked[pos] = true;
        tmp.push_back(candidates[pos]);
        traceback(candidates, target, tmp, pos + 1, sum + candidates[pos], ans, picked); //不使用这个元素
        tmp.pop_back();

        picked[pos] = false;
        traceback(candidates, target, tmp, pos + 1, sum, ans, picked); //不使用这个元素
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<bool> picked(candidates.size(), false);
    std::vector<int> tmp;

    traceback(candidates, target, tmp, 0, 0, ans, picked);
    return ans;
}




void CombinationToTarget(vector<int> &candidates,vector<int> &combination,vector<vector<int>> &result, int target,int startIndex){
    if(target==0){
        result.push_back(combination);
        return;
    }else if(target < 0) {
        return;
    }else{
        for(int i=startIndex;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i!=startIndex && candidates[i]==candidates[i-1]) continue;
            combination.push_back(candidates[i]);
            CombinationToTarget(candidates,combination,result,target-candidates[i],i+1);
            combination.pop_back();//backtrack
        }
    }
}

vector<vector<int>> combinationSum2_(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    sort(candidates.begin(),candidates.end());
    if(candidates.size()==0) return result;
    CombinationToTarget(candidates,combination,result,target,0);
    return result;
}


void CombinationToTarget1(vector<int> &candidates,vector<int> &combination,vector<vector<int> > &result, int target,int startIndex){
    if(target == 0) {
        result.push_back(combination);
        return;
    }
    // if(target < 0) {
    //     return;
    // }

    for(int i = startIndex; i < candidates.size(); ++i) {
        if(candidates[i] > target){
            break;
        }

        if(i != startIndex && candidates[i] == candidates[i - 1]) { // 这里一定要是 candidates[i] == candidates[i - 1], 如果是 candidates[i] == candidates[startIndex], 则会存在一部分不重合的
            continue;
        }

        combination.push_back(candidates[i]);
        CombinationToTarget1(candidates, combination, result, target - candidates[i], i + 1);
        combination.pop_back();
    }
}


vector<vector<int> > combinationSum3(vector<int>& candidates, int target) { // 2023/08/13
    vector<vector<int> > ans;
    if(candidates.empty()) {
        return ans;
    }

    std::sort(candidates.begin(), candidates.end());
    vector<int> combination;
    CombinationToTarget1(candidates, combination, ans, target, 0);
    return ans;
}