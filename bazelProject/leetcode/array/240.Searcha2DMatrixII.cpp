#include "240.Searcha2DMatrixII.h"
#include <algorithm>
#include <iterator>
#include <iostream>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()) {
        return false;
    }

    int col = matrix[0].size() - 1, row = 0;
    while(col >= 0 && row < matrix.size()) {
        if(matrix[row][col] == target) {
            return true;
        }else if (matrix[row][col] > target) {
            --col;
        }else {
            ++row;
        }
    }

    return false;
}

bool searchMatrix_1(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int row = 0, col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0) {
        if(matrix[row][col] == target) {
            return true;
        }else if(matrix[row][col] > target) {
            --col;
        }else {
            ++row;
        }
    }

    return false;
}

bool searchMatrix_2(vector<vector<int> >& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int row = 0, col = matrix[0].size();
    while(row < matrix.size()) {
        // std::cout << *(matrix[row].begin() + col) << std::endl;
        auto pIter = lower_bound(matrix[row].begin(), matrix[row].begin() + col, target);
        if(pIter != matrix[row].end() && *pIter == target) {
            return true;
        }else {
            col = pIter == matrix[row].end() ? matrix[row].size() : std::distance(matrix[row].begin(), pIter);
            ++row;
        }
    }

    return false;
}