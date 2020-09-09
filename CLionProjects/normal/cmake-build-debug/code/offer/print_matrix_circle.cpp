//
// Created by Sharwen on 2020/2/22.
//

#include <iostream>
#include "../../header/primer_header.h"


void print_matrix_by_circle(const std::vector<std::vector<int>> &matrix){
    int top = 0,bottom = matrix.size() - 1,left = 0,right = matrix[0].size() - 1;

    while(top <= bottom && left <= right){

        for(int idx = left;top <= bottom && idx <= right;++idx){
            std::cout << matrix[top][idx] << " ";
        }
        ++top;

        for(int idx = top;left <= right && idx <= bottom;++idx){
            std::cout << matrix[idx][right]<<" ";
        }
        --right;

        for(int idx = right;top <= bottom && idx >= left;--idx){
            std::cout << matrix[bottom][idx] << " ";
        }
        --bottom;

        for(int idx = bottom;left <= right && idx>=top;--idx){
            std::cout << matrix[idx][left] << " ";
        }
        ++left;
    }
}

