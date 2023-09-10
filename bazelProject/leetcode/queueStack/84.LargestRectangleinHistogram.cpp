#include "84.LargestRectangleinHistogram.h"
#include <climits>
#include <stack>


// 这个题的本质就是找当前高度右边严格比当前高度小的第一个位置和左右第一个小于等于当前的位置高度的区间

int largestRectangleArea(const vector<int>& heights1) {
    std::vector<int> heights = heights1;
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

int largestRectangleAreaConcise(const vector<int>& heights1) {
    vector<int> heights = heights1;
    heights.insert(heights.begin(), -1); // insert这里比较耗时，所以还是上面的方法耗时一般短一些
    heights.push_back(-1);
    int iAns = 0;
    std::stack<int> noDecStack;
    for(int i = 0; i < heights.size(); ++i) {
        while(!noDecStack.empty() && heights[noDecStack.top()] > heights[i]) {
            int idx = noDecStack.top();
            noDecStack.pop();
            int iArea = heights[idx] * (i - noDecStack.top() - 1);
            iAns = std::max(iArea, iAns);
        }
        noDecStack.push(i);
    }

    return iAns;
}


int largestRectangleAreaClearly(vector<int>& heights) {
    int iAns = 0;
    std::vector<int> nextSmaller(heights.size(), heights.size());
    std::vector<int> prevSmaller(heights.size(), -1);
    std::stack<int> noDecStack;
    for(int i = 0;i < heights.size(); ++i) {
        int pre = -1;
        while(!noDecStack.empty() && heights[noDecStack.top()] > heights[i]) {
            pre = noDecStack.top();
            nextSmaller[noDecStack.top()] = i;
            noDecStack.pop();
        }

        prevSmaller[i] = noDecStack.empty() ? -1 : noDecStack.top();
        noDecStack.push(i);
    }

    for(int i = 0; i < heights.size(); ++i) {
        int iArea = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
        iAns = std::max(iAns, iArea);
    }

    return iAns;
}
