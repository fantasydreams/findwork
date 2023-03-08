#include "48.RotateImage.h"

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size() / 2;
    int size = matrix.size();
    for(int i = 0; i < row; ++i) {
        for(int s = i; s < size - i - 1; ++s) {
            swap(matrix[i][s], matrix[s][size - 1 - i]);
            swap(matrix[i][s], matrix[size - 1 - i][size - 1 - s]);
            swap(matrix[i][s], matrix[size - 1 - s][i]);
        }
    }
}


void rotate1(vector<vector<int>>& matrix)
{
    int size= matrix.size();
    for(int i = 0; i < size / 2; ++i) {
        swap(matrix[i], matrix[size - 1 - i]);
    }

    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            if(i != j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
}