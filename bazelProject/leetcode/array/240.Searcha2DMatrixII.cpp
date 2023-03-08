#include "240.Searcha2DMatrixII.h"

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