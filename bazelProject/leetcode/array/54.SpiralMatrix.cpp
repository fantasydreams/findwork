#include "54.SpiralMatrix.h"

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> ans;
    if(matrix.empty()) {
        return ans;
    }

    int left = 0, right = matrix[0].size() - 1, up = 0, bottom = matrix.size() - 1;
    while(left <= right && up <= bottom) {
        for(int col = left; col <= right; ++col) {
            ans.push_back(matrix[up][col]);
        }

        ++up;
        for(int row = up; row <= bottom && left <= right; ++row) {
            ans.push_back(matrix[row][right]);
        }        
        
        --right;
        for(int col = right; col >= left && up <= bottom; --col) {
            ans.push_back(matrix[bottom][col]);
        }

        --bottom;
        for(int row = bottom; row >= up && left <= right; --row) {
            ans.push_back(matrix[row][left]);
        }

        ++left;
    }

    return ans;
}


vector<int> spiralOrder1(vector<vector<int> >& matrix) {
    std::vector<int> vecAns;
    if(matrix.empty() || matrix[0].empty()) {
        return vecAns;
    }

    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
    while(top <= bottom) {
        for(int i = left; i <= right; ++i) {
            vecAns.push_back(matrix[top][i]);
        }

        if(++top > bottom) {
            break;
        }

        for(int i = top; i <= bottom; ++i) {
            vecAns.push_back(matrix[i][right]);
        }

        if(--right < left) {
            break;
        }
        
        for(int i = right; i>= left; --i) {
            vecAns.push_back(matrix[bottom][i]);
        }

        if(--bottom < top) {
            break;
        }

        for(int i = bottom; i >=top; --i) {
            vecAns.push_back(matrix[i][left]);
        }
        if(++left > right) {
            break;
        }
    }

    return vecAns;
}