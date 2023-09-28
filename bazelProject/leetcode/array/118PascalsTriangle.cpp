#include "118PascalsTriangle.h"

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    for(int i = 1; i <= numRows; ++i) {
        std::vector<int> row(i, 1);
        for(int j = 1; j < row.size() - 1; ++j) {
            row[j] = ans.back()[j - 1] + ans.back()[j];
        }

        ans.emplace_back(std::move(row));
    }
    return ans;    
}