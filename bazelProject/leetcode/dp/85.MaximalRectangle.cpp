#include "85.MaximalRectangle.h"
#include <stack>

int getmaxrect(const std::vector<int> & height)
{
    std::stack<int> st;
    int maxarea = 0;
    for(int i = 0; i <= height.size(); ++i)
    {
        while(!st.empty() && (i == height.size() || height[st.top()] >= height[i]))
        {
            int hei = height[st.top()];
            int width = 0;
            st.pop();
            if(st.empty()) {
                width = i;
            }else {
                width = i - st.top() - 1;
            }

            maxarea = std::max(maxarea, hei * width);
        }
        st.push(i);
    }

    return maxarea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int area = 0;
    if(matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }

    int m = matrix.size(), n = matrix[0].size();
    std::vector<int> height(n, 0);

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] != '1') {
                height[j] = 0;
            }else {
                height[j] = height[j] + 1;
            }
        }

        area = std::max(area, getmaxrect(height));
    }
    return area;
}