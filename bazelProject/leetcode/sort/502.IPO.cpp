#include "502.IPO.h"
#include <functional>
#include <queue>

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    std::priority_queue<int, std::vector<int>, less<int> >  que;
    std::vector<std::pair<int, int> > vecArr;
    for(int i = 0; i < profits.size(); ++i) {
        vecArr.push_back({capital[i], profits[i]});
    }

    int curr = 0;
    std::sort(vecArr.begin(), vecArr.end());
    for(int i = 0; i < k; ++i)  {
        while(curr < vecArr.size() && vecArr[curr].first <= w)  {
            que.push(vecArr[curr].second);
            ++curr;
        }

        if(!que.empty()) {
            w += que.top(); que.pop();
        }else {
            break;
        }
    }
    return w;
}