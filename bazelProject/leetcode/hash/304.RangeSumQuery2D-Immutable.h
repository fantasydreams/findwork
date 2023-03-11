#include <vector>
using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        vector<vector<int>> mSum(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                mSum[i][j] = mSum[i-1][j] + mSum[i][j-1] - mSum[i - 1][j - 1] + matrix[i-1][j-1];
            }
        }

        partial_sum = std::move(mSum);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return partial_sum[row2 +1][col2 + 1] - partial_sum[row2 + 1][col1] - partial_sum[row1][col2 + 1] + partial_sum[row1][col1];
    }

private:
    vector<vector<int>> partial_sum;
};