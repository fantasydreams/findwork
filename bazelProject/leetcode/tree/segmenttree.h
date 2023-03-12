
#include <memory>
#include <vector>

class SegmentTreeNode {
public:
    SegmentTreeNode(int start, int end, int val, SegmentTreeNode * left = nullptr, SegmentTreeNode * right = nullptr) : 
        m_start(start), m_end(end), m_val(val),
        m_left(left), m_right(right) {
    }

    SegmentTreeNode(const SegmentTreeNode &) = delete;
    SegmentTreeNode() = delete;
    SegmentTreeNode & operator=(const SegmentTreeNode &) = delete;

    ~SegmentTreeNode() {
        delete m_left;
        delete m_right;
        m_left = m_right = nullptr;
    }

    SegmentTreeNode * m_left, * m_right;
    int m_start, m_end, m_val;      
};


class SegmentTree{
public:
    SegmentTree(const std::vector<int> & vecNums) : m_nums(vecNums) {
        m_root = buildTree(0, m_nums.size() - 1);
    }
    ~SegmentTree() {
        destroyTree(m_root);
    }

    void updateTree(int index, int val) {
        if(index < 0 || index >= m_nums.size()) {
            return;
        }

        m_nums[index] = val;
        updateTree(m_root, index, val);
    }

    int sumRange(int left, int right) {
        return sumRange(m_root, left, right);
    }

private:
    SegmentTreeNode * buildTree(int start, int end) {
        if(start == end) {
            return new SegmentTreeNode(start, end, m_nums[start]);
        }

        int mid = start + ((end - start) >> 1);
        auto left = buildTree(start, mid);
        auto right = buildTree(mid + 1, end);
        auto node = new SegmentTreeNode(start, end, left->m_val + right->m_val, left, right);
        return node;
    }

    void updateTree(SegmentTreeNode * root, int index, int val) {
        if(root->m_start == index && root->m_end == index) {
            root->m_val = val;
            return;
        }

        int mid = root->m_start + ((root->m_end - root->m_start) >> 1);
        if(index <= mid){
            updateTree(root->m_left, index, val);
        }else {
            updateTree(root->m_right, index, val);
        }

        root->m_val = root->m_left->m_val + root->m_right->m_val;
    }

    int sumRange(SegmentTreeNode * root, int left, int right) {
        if(root->m_start == left && root->m_end == right) {
            return root->m_val;
        }

        int mid = root->m_start + (((root->m_end) - (root->m_start)) >> 1);
        if(right <= mid) {
            return sumRange(root->m_left, left, right);
        }else if(left > mid) {
            return sumRange(root->m_right, left, right);
        }else {
            return sumRange(root->m_left, left, mid) + sumRange(root->m_right, mid + 1, right);
        }
    }

    void destroyTree(SegmentTreeNode * root) {
        if(root == nullptr) {
            return;
        }

        destroyTree(root->m_left);
        root->m_left = nullptr;
        destroyTree(root->m_right);
        root->m_right = nullptr;
        delete root;
    }

    std::vector<int> m_nums;
    SegmentTreeNode * m_root;
};