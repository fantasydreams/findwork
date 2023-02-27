#include "384.ShuffleanArray.h"
#include <cstdlib>

Solution::Solution(vector<int>& nums) {
    origin = nums;
    shuffled = nums;
    srand(time(NULL));
}

std::vector<int> Solution::reset() {
    return origin;
}

// fisher- Yates随机序列算法
// 它给出了1 到N 的数字的的随机排列，具体步骤如下：
// 写下从1 到N 的数字
// 取一个从1 到剩下的数字（包括这个数字）的随机数k.
// 从低位开始，得到第k 个数字（这个数字还没有被取出），把它写在独立的一个列表的最后一位
// 重复第2 步，直到所有的数字都被取出
// 第3 步写出的这个序列，现在就是原始数字的随机排列
std::vector<int> Solution::shuffle() {
    for(int i = shuffled.size() - 1; i > 0; --i) {
        int pos = rand() % i;
        swap(shuffled[i], shuffled[pos]);
    }
    return shuffled;
}