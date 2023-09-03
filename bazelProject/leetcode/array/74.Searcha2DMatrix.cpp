#include "74.Searcha2DMatrix.h"

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