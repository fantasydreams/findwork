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


int maxPoints1(vector<vector<int> >& points) {
    int max_cnt = 0, same = 0, same_y = 0;
    for(int i = 0; i < points.size(); ++i) {
        same = 1; same_y = 1;
        unordered_map<double, int> hash_map;
        for(int j = i + 1; j < points.size(); ++j) {
            if(points[i][1] == points[j][1]) {
                ++same_y;
                if(points[i][0] == points[j][0]) {
                    ++same;
                }
            }else {
                ++hash_map[(double)(points[i][0] - points[j][0]) / (points[i][1] - points[j][1])];
            }
        }

        max_cnt = std::max(max_cnt, same_y);
        for(const auto& oPair : hash_map) {
            max_cnt = std::max(max_cnt, same + oPair.second);
        }
    }

    return max_cnt;
}



int maxPoints2(vector<vector<int> >& points) {
    int max_cnt = 0, same = 0, same_x = 0;
    for(int i = 0; i < points.size(); ++i) {
        same = 1; same_x = 1;
        unordered_map<double, int> hash_map;
        for(int j = i + 1; j < points.size(); ++j) {
            if(points[i][0] == points[j][0]) {
                ++same_x;
                if(points[i][1] == points[j][1]) {
                    ++same;
                }
            }else {
                ++hash_map[(double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])];
            }
        }

        max_cnt = std::max(max_cnt, same_x);
        for(const auto& oPair : hash_map) {
            max_cnt = std::max(max_cnt, same + oPair.second);
        }
    }

    return max_cnt;
}


int maxPoints3(vector<vector<int> >& points)  {
    int max_cnt = 0, same = 0, same_x = 0;
    for(int i = 0; i < points.size(); ++i) {
        same = 1, same_x = 1;
        unordered_map<double, int> hash_map;
        for(int j = i + 1; j < points.size(); ++j) {
            if(points[i][0] == points[j][0]) {
                ++same_x;
                if(points[i][1] == points[j][1]) {
                    ++same;
                }
            }else {
                ++hash_map[((double)points[j][1] - points[i][1]) / ((double)points[j][0] - points[i][0])]; // 注意精度
            }
        }

        max_cnt = std::max(max_cnt, same_x);
        for(const auto & oPair : hash_map) {
            max_cnt = std::max(max_cnt, same + oPair.second);
        }
    }

    return max_cnt;
}