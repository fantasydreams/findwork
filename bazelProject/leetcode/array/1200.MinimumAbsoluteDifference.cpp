#include "1200.MinimumAbsoluteDifference.h"

std::vector<std::vector<int> > minimumAbsDifference(std::vector<int>& arr)
{
    std::vector<std::vector<int> > res;
    if(arr.size() <= 1) return res;
    std::sort(arr.begin(), arr.end());
    std::map<uint64_t, std::vector<std::vector<int> > > umap;
    for(int i = 0; i < arr.size() - 1; ++i){
        uint64_t absdiff = arr[i + 1] - arr[i];
        if(umap.size() == 0) {
            std::vector<int> tmp = {arr[i], arr[i + 1]};
            umap[absdiff].emplace_back(tmp);
        }else
        {
            auto iter = umap.begin();
            if(absdiff > iter->first){
                continue;
            }else{
                std::vector<int> tmp = {arr[i], arr[i + 1]};
                umap[absdiff].emplace_back(tmp);
            }
        }
    }

    return umap.begin()->second;
}

std::vector<std::vector<int> > minimumAbsDifference1(std::vector<int>& arr)
{
    std::vector<std::vector<int> > res;
    if(arr.size() <= 1) return res;
    std::sort(arr.begin(), arr.end());
    std::map<uint64_t, std::vector<std::vector<int> > > umap;
    for(int i = 0; i < arr.size() - 1; ++i){
        uint64_t absdiff = arr[i + 1] - arr[i];
        std::vector<int> tmp = {arr[i], arr[i + 1]};
        if(umap.size() == 0) 
        {
            umap[absdiff].emplace_back(tmp);
        }else
        {
            auto iter = umap.begin();
            if(absdiff > iter->first){
                continue;
            }else if(absdiff == iter->first) { 
                umap[absdiff].emplace_back(tmp);
            }else
            {
                umap.clear();
                umap[absdiff].emplace_back(tmp);
            }
        }
    }

    return umap.begin()->second;
}


std::vector<std::vector<int> > minimumAbsDifference2(std::vector<int>& arr)
{
    std::vector<std::vector<int> > res;
    if(arr.size() <= 1) return res;
    std::sort(arr.begin(), arr.end());
    uint64_t min = UINT64_MAX;
    for(int i = 0 ;i < arr.size() - 1; ++i)
    {
        std::vector<int> tmp = {arr[i], arr[i + 1]};
        uint64_t absdiff = arr[i + 1] - arr[i];
        if(res.size() == 0)
        {
            res.emplace_back(tmp);
            min = absdiff;
            continue;
        }

        if (absdiff == min){
            res.emplace_back(tmp);
        }else if(absdiff > min) {
            continue;
        }else
        {
            res.clear();
            res.emplace_back(tmp);
            min = absdiff;
        }
    }
    return res;
}