#include "149.MaxPointsonaLine.h"
#include <cmath>
#include <unordered_map>

int maxPoints(vector<vector<int>>& points) {
    int max_cnt = 0, same = 0, same_y = 0;
    for(decltype(points.size()) i = 0; i < points.size(); ++i) {
        same = 1, same_y = 1;
        unordered_map<double, int> hash_map;
        for(decltype(points.size()) j = i + 1; j < points.size(); ++j) {
            if(points[i][1] == points[j][1]) {
                ++same_y;
                if(points[j][0] == points[i][0]) {
                    ++same;
                }
            }else {
                ++hash_map[((double)points[i][0] - points[j][0]) / (points[i][1] - points[j][1])];
            }
        }

        max_cnt = std::max(max_cnt, same_y);
        for(auto pIter = hash_map.begin(); pIter != hash_map.end(); ++pIter) {
            max_cnt = std::max(max_cnt, same + pIter->second);
        }
    }

    return max_cnt;
}