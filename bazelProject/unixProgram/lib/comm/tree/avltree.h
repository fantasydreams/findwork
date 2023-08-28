#pragma once

// https://zhuanlan.zhihu.com/p/34899732
// https://www.cnblogs.com/skywang12345/p/3577360.html
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <queue>
#include <stack>

template <typename Type>
struct AvlTreeNode {
    AvlTreeNode * m_pLeft;
    AvlTreeNode * m_pRight;
    int m_iHeight;
    Type m_value;

    AvlTreeNode<Type>(Type value) : m_value(value), m_pLeft(nullptr), m_pRight(nullptr) {};
    AvlTreeNode<Type>(): m_pLeft(nullptr), m_pRight(nullptr){};
    AvlTreeNode<Type>(Type value, const AvlTreeNode<Type>* pleft, const AvlTreeNode<Type>* pright): m_value(value), m_pLeft(pleft), m_pRight(pright){};
};


template <typename Type>
class AvlTree {
    using Node = AvlTreeNode<Type>;
    using NodePtr = AvlTreeNode<Type>*; 
    using NodePtrRef = AvlTreeNode<Type>*&; 
public:
    AvlTree<Type>() : m_pRoot(nullptr){};
    AvlTree<Type>(NodePtr pNode): m_pRoot(pNode){};
    bool Insert(const Type& value);
    bool Remove(const Type& value);
    const NodePtr Find() const;
    const AvlTree<Type> GetTree() const {return m_pRoot;};
private:
    int GetHeight(NodePtr pRoot);
    int GetBalanceFactor(NodePtr pRoot);
    NodePtr RotateRight(NodePtr);
    NodePtr RotateLeft(NodePtr);
    AvlTreeNode<Type>* Insert(NodePtrRef pNode, const Type& value, bool& bSucc);
    AvlTreeNode<Type>* Remove(NodePtrRef pNode, const Type& value, bool& bSucc);
    const Type& GetTreeMin(NodePtr pNode);
    const Type& GetTreeMax(NodePtr pNode);

    AvlTreeNode<Type> * m_pRoot;
};

template <typename Type> bool AvlTree<Type>::Insert(const Type& val) {
    bool bSucc = false;
    Insert(m_pRoot, val, bSucc);
    return bSucc;
}

template <typename Type> bool AvlTree<Type>::Remove(const Type& val) {
    bool bSucc = false;
    Remove(m_pRoot, val, bSucc);
    return bSucc;
}


template <typename Type> inline int AvlTree<Type>::GetHeight(NodePtr pRoot) {
    if(pRoot == nullptr) {
        return 0;
    }else {
        return std::max(GetHeight(pRoot->m_pLeft), GetHeight(pRoot->m_pRight)) + 1;
    }
}

template <typename Type> int AvlTree<Type>::GetBalanceFactor(NodePtr pRoot) {
    if(pRoot == nullptr) {
        return 0;
    }else if(pRoot->m_pLeft && !pRoot->m_pRight) {
        return pRoot->m_pLeft->m_iHeight;
    }else if(!pRoot->m_pLeft && pRoot->m_pRight) {
        return -pRoot->m_pRight->m_iHeight;
    }else {
        return pRoot->m_pLeft->m_iHeight - pRoot->m_pRight->m_iHeight;
    }
}


template <typename Type> AvlTreeNode<Type>* AvlTree<Type>::RotateRight(NodePtr pRoot){
    NodePtr pNewRoot = pRoot->m_pLeft;
    pRoot->m_pLeft = pNewRoot->m_pRight;
    pNewRoot->m_pRight = pRoot;

    pRoot->m_iHeight = std::max(GetHeight(pRoot->m_pLeft), GetHeight(pRoot->m_pRight)) + 1;
    pNewRoot->m_iHeight = std::max(GetHeight(pNewRoot->m_pLeft), GetHeight(pRoot->m_pRight)) + 1;

    return pNewRoot;
}

template <typename Type> AvlTreeNode<Type>* AvlTree<Type>::RotateLeft(NodePtr pRoot) {
    NodePtr pNewRoot = pRoot->m_pRight;
    pRoot->m_pRight = pNewRoot->m_pLeft;
    pNewRoot->m_pLeft = pRoot;

    pRoot->m_iHeight = std::max(GetHeight(pRoot->m_pLeft), GetHeight(pRoot->m_pRight)) + 1;
    pNewRoot->m_iHeight = std::max(GetHeight(pNewRoot->m_pLeft), GetHeight(pNewRoot->m_pRight)) + 1;

    return pNewRoot;
}

template <typename Type> AvlTreeNode<Type>* AvlTree<Type>::Insert(NodePtrRef pNode, const Type& Val, bool& bSucc) {
    if(pNode == nullptr) {
        pNode = new AvlTreeNode<Type>(Val);
        if(pNode == nullptr) {
            bSucc = false;
            return nullptr;
        }
        bSucc = true;
        return pNode;
    }else {
        if(pNode->m_value == Val) {
            bSucc = false;
            return nullptr;
        }else if(pNode->m_value > Val) {
            pNode->m_pLeft = Insert(pNode->m_pLeft, Val, bSucc);
            if(GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight) > 1) {
                if(pNode->m_pLeft->m_value > Val) {
                    pNode = RotateRight(pNode->m_pLeft);
                }else {
                    pNode->m_pLeft = RotateLeft(pNode->m_pLeft);
                    pNode = RotateRight(pNode->m_pLeft);
                }
            } 
        }else {
            pNode->m_pRight = Insert(pNode->m_pRight, Val, bSucc);
            if(GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight) < -1) {
                if(pNode->m_pRight->m_value < Val) {
                    pNode = RotateLeft(pNode->m_pLeft);
                }else {
                    pNode->m_pRight = RotateRight(pNode->m_pRight);
                    pNode = RotateLeft(pNode->m_pRight);
                }
            }
        }
    }

    if(bSucc) {
        pNode->m_iHeight = GetHeight(pNode);
    }
    return pNode;
}

template <typename Type> AvlTreeNode<Type>* AvlTree<Type>::Remove(NodePtrRef pNode, const Type &val, bool& bSucc) {
    if(pNode == nullptr) {
        return false;
    }else if(pNode->m_value < val){
        pNode = Remove(pNode->m_pRight, val, bSucc);
        if(GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight) > 1) { // 如果当前节点不平衡
            if(GetHeight(pNode->m_pLeft->m_pLeft) < GetHeight(pNode->m_pLeft->m_pRight)) { // LR
                pNode->m_pLeft = RotateRight(pNode->m_pLeft);
                pNode = RotateLeft(pNode->m_pLeft);
            }else { // LR
                pNode = RotateRight(pNode->m_pLeft);
            }
        }
    }else if(pNode->m_value > val) {
        pNode = Remove(pNode->m_pLeft, val, bSucc);
        if(GetHeight(pNode->m_pLeft) - GetHeight(pNode->m_pRight) < -1) {
            if(GetHeight(pNode->m_pRight->m_pLeft) > GetHeight(pNode->m_pRight->m_pRight)) { // RL
                pNode->m_pRight = RotateLeft(pNode->m_pRight);
                pNode = RotateLeft(pNode->m_pRight); 
            }else { // RR
                pNode = RotateRight(pNode->m_pRight);
            }
        }
    }else { // 删除的事当前节点
        if(pNode->m_pLeft && pNode->m_pRight) {
            if(GetHeight(pNode->m_pLeft) < GetHeight(pNode->m_pRight)) { // 取右子树的最左节点
                Type vDel = GetTreeMin(pNode->m_pRight);
                pNode->m_value = vDel;
                pNode->m_pRight = Remove(pNode->m_pRight, vDel);
            }else { // 取左子树的最右节点
                Type vDel = GetTreeMax(pNode->m_pLeft);
                pNode->m_value = vDel;
                pNode->m_pLeft = Remove(pNode->m_pLeft, vDel);
            }
        }else {
            AvlTreeNode<Type> pDel = pNode;
            pNode = pNode->m_pLeft ? pNode->m_pLeft : pNode->m_pRight;
            delete pDel;
        }
    }
    if(bSucc) {
        pNode->m_iHeight = GetHeight(pNode);
    }
    return pNode;
}

template <typename Type> const Type& AvlTree<Type>::GetTreeMax(NodePtr pNode) {
    while(pNode && pNode->m_pRight) {
        pNode = pNode->m_pRight;
    }

    return pNode->m_value;
}

template <typename Type> const Type& AvlTree<Type>::GetTreeMin(NodePtr pNode) {
    while(pNode && pNode->m_pLeft) {
        pNode = pNode->m_pLeft;
    }

    return pNode->m_value;
}