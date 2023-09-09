#include "84.LargestRectangleinHistogram.h"
#include <climits>
#include <stack>

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(-1);
    int iAns = 0;
    std::stack<int> noDecStack;
    for(int i = 0; i < heights.size(); ++i) {
        while(!noDecStack.empty() && heights[noDecStack.top()] > heights[i]) {
            int idx = noDecStack.top();
            noDecStack.pop();
            int iArea = 0;
            if(noDecStack.empty()) {
                iArea = heights[idx] * i;
            }else {
                iArea = heights[idx] * (i - noDecStack.top() - 1);
            }
            iAns = std::max(iArea, iAns);
        }
        noDecStack.push(i);
    }

    return iAns;
}