#pragma once

#include <stack>

template <typename Type>
struct BinTreeNode {
    BinTreeNode * m_pLeft;
    BinTreeNode * m_pRight;
    Type m_value;

    BinTreeNode<Type>(Type value) : m_value(value), m_pLeft(nullptr), m_pRight(nullptr) {};
    BinTreeNode<Type>(): m_pLeft(nullptr), m_pRight(nullptr){};
    BinTreeNode<Type>(Type value, const BinTreeNode<Type>* pleft, const BinTreeNode<Type>* pright): m_value(value), m_pLeft(pleft), m_pRight(pright){};
};

template<typename Type>
class BinTree {
public:
    BinTree(BinTree<Type>* root) : m_pRoot(root){};
    BinTree() : m_pRoot(nullptr){};

    int Insert(const Type& value);
    int Remove(const Type& value);
    const BinTreeNode<Type>* GetNode() const {return m_pRoot;};
    BinTreeNode<Type>* GetLeftChild(const BinTreeNode<Type>* const pNode) {return pNode ? pNode->m_pLeft : nullptr;}
    BinTreeNode<Type>* GetRightChold(const BinTreeNode<Type>* const pNode) {return pNode ? pNode->m_pRight : nullptr;}
    void Destroy();
private:
    BinTreeNode<Type>* m_pRoot;
};


template<typename Type> int BinTree<Type>::Insert(const Type& value) {
    if(m_pRoot == nullptr) { 
        m_pRoot = new BinTreeNode<Type>(value);
        if(m_pRoot == nullptr) {
            return false;
        }
    }else {
        BinTreeNode<Type> * pParentNode = nullptr, *pCurNode = m_pRoot;
        while(pCurNode) {
            pParentNode = pCurNode;
            if(pCurNode->m_value < value) {
                pCurNode = pCurNode->m_pRight;
            }else if(pCurNode->m_value > value) {
                pCurNode = pCurNode->m_pLeft;
            }else { // 已经存在返回false
                return false;
            }
        }

        BinTreeNode<Type>* pInsertNode = new BinTreeNode<Type>(value);
        if(pInsertNode == nullptr) {
            return false;
        }
        if(pParentNode->m_value > pInsertNode->m_value) {
            pParentNode->m_pLeft = pInsertNode;
        }else {
            pParentNode->m_pRight = pInsertNode;
        }
    }

    return true;
}


// 删除的时候要考虑删除的节点是否根节点
template<typename Type> int BinTree<Type>::Remove(const Type& value) {
    BinTreeNode<Type>* pParentNode = nullptr, * pCurNode = m_pRoot;
    while(pCurNode) {
        if(pCurNode->m_value == value) {
            if(pCurNode->m_pLeft && pCurNode->m_pRight) {
                //找到右子树的最左孩子，进行交换然后删除交换过去的节点
                pParentNode = pCurNode;
                BinTreeNode<Type>* pRLeft = pCurNode->m_pRight;
                while(pRLeft->m_pLeft) {
                    pParentNode = pRLeft;
                    pRLeft = pRLeft->m_pLeft;
                }

                std::swap(pRLeft->m_value, pCurNode->m_value);
                if(pParentNode->m_pLeft == pRLeft) {
                    pParentNode->m_pLeft = pRLeft->m_pRight;
                }else {
                    pParentNode->m_pRight = pRLeft->m_pRight;
                }
                delete pRLeft;
            }else {
                if(m_pRoot == pCurNode) {
                    m_pRoot = pCurNode->m_pLeft ? pCurNode->m_pLeft : pCurNode->m_pRight;
                    delete pCurNode;
                }else {
                    if(pParentNode->m_pLeft == pCurNode) {
                        pParentNode->m_pLeft = pCurNode->m_pLeft ? pCurNode->m_pLeft : pCurNode->m_pRight;
                    }else {
                        pParentNode->m_pRight = pCurNode->m_pLeft ? pCurNode->m_pLeft : pCurNode->m_pRight;
                    }
                    delete pCurNode;
                }
            }
            return true;
        }else {
            pParentNode = pCurNode;
            if(pCurNode->m_value < value){
                pCurNode = pCurNode->m_pRight;
            }else {
                pCurNode = pCurNode->m_pLeft;
            }
        }
    }

    return false;
}


template <typename Type>void PushsTaskLeftPathUntilNull(const BinTreeNode<Type>* pNode, std::stack<const BinTreeNode<Type>*> & stack) {
    while(pNode) {
        stack.push(pNode);
        pNode = pNode->m_pLeft;
    }
}

template<typename Type> void BinTree<Type>::Destroy() {
    //使用后续遍历完成
    if(m_pRoot == nullptr) {
        return;
    } 
    std::stack<const BinTreeNode<Type>*> st;
    PushsTaskLeftPathUntilNull(m_pRoot, st);

    const BinTreeNode<Type>* pPre = nullptr;
    while(!st.empty()) {
        const BinTreeNode<Type>* pNode = st.top();
        if(pNode->m_pRight == pPre || pNode->m_pRight == nullptr) {
            st.pop();
            delete pNode;
        }else {
            PushsTaskLeftPathUntilNull(pNode->m_pRight, st);
        }
    }
}