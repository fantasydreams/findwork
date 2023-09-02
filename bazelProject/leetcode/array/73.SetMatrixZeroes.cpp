#include "73.SetMatrixZeroes.h"
#include <algorithm>
#include <iterator>
#include <set>

void setZeroes(vector<vector<int> >& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return;
    }

    std::set<int> cols;
    std::vector<int> zeros(matrix[0].size(), 0);
    for(int i = 0; i < matrix.size(); ++i) {
        bool bSetZero = false;
        for(int j = 0;j < matrix[0].size(); ++j) {
            if(matrix[i][j] == 0) {
                bSetZero = true;
                cols.insert(j);
            }
        }

        if(bSetZero) {
            matrix[i] = zeros;
        }
    }

    for(auto col : cols) {
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][col]) {
                matrix[i][col] = 0;
            }
        }
    }
}

void setZeroes1(vector<vector<int> >& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return;
    }

    std::set<int> cols, rows, allRows;
    std::vector<int> zeros(matrix[0].size(), 0);
    for(int i = 0; i < matrix.size(); ++i) {
        bool bSetZero = false;
        allRows.insert(i);
        for(int j = 0;j < matrix[0].size(); ++j) {
            if(matrix[i][j] == 0) {
                bSetZero = true;
                cols.insert(j);
                rows.insert(i);
            }
        }

        if(bSetZero) {
            matrix[i] = zeros;
        }
    }

    std::set<int> setRows;
    std::set_difference(allRows.begin(), allRows.end(), rows.begin(), rows.end(), std::inserter(setRows, setRows.begin()));
    for(auto col : cols) {
        for(auto row : setRows) {
            matrix[row][col] = 0;
        }
    }
}