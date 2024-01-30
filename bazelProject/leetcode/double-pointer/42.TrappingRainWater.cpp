#include "42.TrappingRainWater.h"
#include <iostream>
#include <stack>

int trap(vector<int>& height) {
    if(height.empty() || height.size() == 1) {
        return 0;
    }

    int LeftMaxH = 0, rightMaxH = 0;
    int water = 0;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        if(height[left] <= height[right]) {
            if(height[left] > LeftMaxH) {
                LeftMaxH = height[left];
            }else {
                water += (LeftMaxH - height[left]);
                ++left;
            }
        }else {
            if(height[right] > rightMaxH) {
                rightMaxH = height[right];
            }else {
                water += (rightMaxH - height[right]);
                --right;
            }
        }
    }

    return water;
}


void PrintVec(const std::vector<int>& vec) {
    for( const auto & iNum : vec) {
        std::cout << iNum << "  ";
    }
    std::cout << std::endl;
}

int trap1(vector<int> &height) {
    if(height.empty() || height.size() == 1) {
        return 0;
    }

    std::vector<int> dpLeft(height.size(), -1), dpRight(height.size(), -1);
    dpLeft[0] = 0; dpRight[height.size() - 1] = height.size() - 1;
    for(int i = 1; i < dpLeft.size(); ++i) {
        if(height[i] <= height[dpLeft[i - 1]]) {
            dpLeft[i] = dpLeft[i - 1];
        }else {
            dpLeft[i] = i;
        }
    }

    // PrintVec(dpLeft);

    for(int i = height.size() - 2; i >= 0; --i) {
        if(height[i] <= height[dpRight[i + 1]]) {
            dpRight[i] = dpRight[i + 1];
        }else {
            dpRight[i] = i;
        }
    }

    // PrintVec(dpRight);

    int iAns = 0;
    for(int i = 0; i < height.size(); ++i) {
        int hei = std::min(height[dpLeft[i]], height[dpRight[i]]) - height[i];
        // std::cout << hei << "   ";
        iAns += hei;
    }

    return iAns;
}


int trapDoublePointer(vector<int>& height) {
    int iAns = 0;
    int iLeftMax = 0, iRightMax = 0;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        if(height[left] <= height[right]) {
            if(height[left] > iLeftMax) {
                iLeftMax = height[left];
            }else {
                iAns += iLeftMax - height[left];
            }
            ++left;
        }else {
            if(height[right] > iRightMax) {
                iRightMax = height[right];
            }else {
                iAns += iRightMax - height[right];
            }
            --right;
        }   
    }

    return iAns;
}


// https://zhuanlan.zhihu.com/p/79811305

//栈

int trapMonoStack(vector<int>& height) {
    int iAns = 0;
    std::stack<int> st;
    int iCur = 0;
    while(iCur < height.size()) {
        while(!st.empty() && height[iCur] > height[st.top()]) {
            int iIdx = st.top();
            st.pop();
            if(st.empty()) {
                break;
            }

            iAns += (std::min(height[st.top()], height[iCur]) - height[iIdx]) * (iCur - st.top() - 1);
        }
        st.push(iCur);
        ++iCur;
    }

    return iAns;
}