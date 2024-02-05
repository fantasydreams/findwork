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


void setZeroes2(vector<vector<int> >& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return;
    }

    std::set<int> rows, cols, allRows;
    for(int row = 0; row < matrix.size(); ++row) {
        bool bSetZero = false;
        for(int col = 0; col < matrix[row].size(); ++col) {
            allRows.insert(row);
            if(matrix[row][col] == 0) {
                rows.insert(row);
                cols.insert(col);
                bSetZero = true;
            }
        }

        if(bSetZero) {
            std::fill(matrix[row].begin(), matrix[row].end(), 0);
        }
    }

    std::set<int> diffRows;
    std::set_difference(allRows.begin(), allRows.end(), rows.begin(), rows.end(), std::inserter(diffRows, diffRows.begin()));
    for(const auto & col : cols) {
        for(const auto& row : diffRows) {
            matrix[row][col] = 0;
        }
    }
}