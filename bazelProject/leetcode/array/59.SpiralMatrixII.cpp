#include "59.SpiralMatrixII.h"

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int curNum = 1;
    while(top <= bottom && left <= right) {
        for(int k = left; k <= right; ++k) {
            ans[top][k] = curNum++;
        }
        ++top;

        for(int k = top; k <= bottom && left <= right; ++k) {
            ans[k][right] = curNum++;
        }
        --right;

        for(int k = right; k >= left && top <= bottom; --k) {
            ans[bottom][k] = curNum++;
        }
        --bottom;

        for(int k = bottom; k >= top && left <= right; --k) {
            ans[k][left] = curNum++;
        }
        ++left;
    }

    return ans;
}