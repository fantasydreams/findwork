#include "74.Searcha2DMatrix.h"
#include <algorithm>

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int row = 0, col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0) {
        if(matrix[row][col] == target) {
            return true;
        }else if(matrix[row][col] < target) {
            ++row;
        }else {
            --col;
        }
    }

    return false;
}


bool searchMatrix1(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }

    for(int row = 0; row < matrix.size(); ++row) {
        if(matrix[row][matrix[row].size() - 1] < target) {
            continue;
        }

        auto pIter = std::find(matrix[row].begin(), matrix[row].end(), target);
        if(pIter == matrix[row].end()) {
            return false;
        }else {
            return true;
        }
    }

    return false;
}


bool searchMatrix2(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }

    for(int row = 0; row < matrix.size(); ++row) {
        if(matrix[row][matrix[row].size() - 1] < target) {
            continue;
        }

        return std::binary_search(matrix[row].begin(), matrix[row].end(), target);
    }

    return false;
}


// 把二维数组平铺，用二分查找去寻找
bool searchMatrix3(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }    

    int rowSize = matrix.size(), colSize = matrix[0].size();
    int start = 0, end = rowSize * colSize - 1;
    int mid;
    while(start <= end) {
        mid = start + ((end - start) >> 1);
        int row = mid / colSize;
        int col = mid % colSize;
        if(matrix[row][col] == target) {
            return true;
        }else if(matrix[row][col] < target) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    return false;
}