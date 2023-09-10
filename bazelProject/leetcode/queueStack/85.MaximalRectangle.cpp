#include "85.MaximalRectangle.h"
#include <vector>
#include "84.LargestRectangleinHistogram.h"


// 单调栈一般用于找左右区间
// https://www.cnblogs.com/grandyang/p/4322667.html ，单调栈的应用场景

int maximalRectangle(vector<vector<char> >& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int iAns = 0;
    std::vector<int> height(matrix[0].size(), 0);
    for(int i = 0 ; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j){
            height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
        }

        iAns = std::max(largestRectangleArea(height), iAns);
    }

    return iAns;
}