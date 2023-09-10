#include "89.GrayCode.h"

// gray 码镜面反射
vector<int> grayCode(int n) {
    vector<int> vecAns = {0};
    for(int i = 0;i < n; ++i) {
        int size = vecAns.size();
        for(int k = size - 1; k >= 0; --k) {
            vecAns.push_back(vecAns[k] | 1 << i);
        }
    }

    return vecAns;
}


// https://www.cnblogs.com/grandyang/p/4315607.html
// gray to number and number to gray
vector<int> grayCode1(int n) {
    vector<int> vecAns;
    for(int i = 0; i < pow(2, n); ++i) {
        vecAns.push_back(i ^ (i >> 1));
    }

    return vecAns;
}