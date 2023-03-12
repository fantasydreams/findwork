#include "segmenttree.h"
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) :m_segTree(nums) {
    }
    
    void update(int index, int val) {
        m_segTree.updateTree(index, val);
    }
    
    int sumRange(int left, int right) {
        return m_segTree.sumRange(left, right);
    }

private:
    SegmentTree m_segTree;
};