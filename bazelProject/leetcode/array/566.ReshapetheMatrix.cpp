#include "566.ReshapetheMatrix.h"

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = m ? mat[0].size() : 0;
    if(!m || !n || ((m * n) % r) || (m == r && n == ((m * n) / r))) {
        return mat;
    }
    int nCol = (m * n) / r, tmpx, tmpy, tmp;

    vector<vector<int>> reShaped(r, vector<int>(nCol));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < nCol; ++j) {
            tmp = i * nCol + j;
            tmpx = (tmp) / n;
            tmpy = (tmp) % n;
            reShaped[i][j] = mat[tmpx][tmpy];
        }
    }

    return reShaped;
}