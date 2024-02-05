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


// 上下翻转，然后对称翻转
void rotate2(vector<vector<int> >& matrix) { // 2023/08/17
    int i = 0, j = matrix.size() - 1;
    while(i < j) {
        swap(matrix[i], matrix[j]);
        ++i;
        --j;
    }

    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = i + 1; j < matrix.size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// 模拟翻转
void rotate3(vector<vector<int> >& matrix) { // 2023/08/17
    int size = matrix.size();
    int torow = size / 2;
    for(int i = 0; i < torow; ++i) {
        for(int j = i; j < size - i - 1; ++j) {
            swap(matrix[i][j], matrix[j][size - i - 1]); // 前后相邻
            swap(matrix[i][j], matrix[size - i - 1][size - j - 1]); // 前一个交换元素的列就是下一个交换元素的行
            swap(matrix[i][j], matrix[size - j - 1][i]);
        }
    }
}


void rotateUpDownAndSymmetry(vector<vector<int> >& matrix) {
    int i = 0, j = matrix.size() - 1;
    while( i < j) {
        swap(matrix[i], matrix[j]);
        ++i, --j;
    }

    for(int row = 0; row < matrix.size(); ++row) {
        for(int col = row + 1; col < matrix[row].size(); ++col) {
            swap(matrix[row][col], matrix[col][row]);
        }
    }
}


// 直接模拟旋转
void rotateSimulate(vector<vector<int> > &matrix) {
    int iTotalRowNum = matrix.size();
    int iEndRow = iTotalRowNum / 2;
    for(int row = 0; row < iEndRow; ++row) {
        for(int col = row; col < iTotalRowNum - 1 - row; ++col) {
            swap(matrix[row][col], matrix[col][iTotalRowNum - 1 - row]);
            swap(matrix[row][col], matrix[iTotalRowNum - 1 - row][iTotalRowNum - 1 - col]);
            swap(matrix[row][col], matrix[iTotalRowNum - 1 - col][row]);
        }
    }
}