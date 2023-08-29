#pragma once
#include "avltree.h"
#include <cstdlib>
#include <cstddef>
#include <string>
#include <stack>
#include <stdio.h>
#include <queue>

template <typename Type>void TraverseTreePreNoRecursion(const AvlTree<Type>& AvlTree, std::string& sList) {
    sList.clear();
    const AvlTreeNode<Type>* pRoot = AvlTree.GetTree();
    if(pRoot == nullptr) {
        return;
    }

    std::stack<const AvlTreeNode<Type>*> st;
    st.push(pRoot);
    while(!st.empty()) {
        const AvlTreeNode<Type>* pNode = st.top();
        st.pop();

        if(!sList.empty()) {
            sList += " ";
        }
        sList += std::to_string(pNode->m_value);

        if(pNode->m_pRight) {
            st.push(pNode->m_pRight);
        }
        if(pNode->m_pLeft) {
            st.push(pNode->m_pLeft);
        }
    }
}

template <typename Type>void PushsTaskLeftPathUntilNull(const AvlTreeNode<Type>* pNode, std::stack<const AvlTreeNode<Type>*> & stack) {
    while(pNode) {
        stack.push(pNode);
        pNode = pNode->m_pLeft;
    }
}

template <typename Type>void TraverseTreeMidNoRecursion(const AvlTree<Type>& AvlTree, std::string& sList) {
    sList.clear();
    const AvlTreeNode<Type>* pRoot = AvlTree.GetTree();
    if(pRoot == nullptr) {
        return;
    }

    std::stack<const AvlTreeNode<Type>*> st;
    PushsTaskLeftPathUntilNull(pRoot, st);
    while(!st.empty()) {
        const AvlTreeNode<Type>* pNode = st.top();
        st.pop();

        if(!sList.empty()) {
            sList += " ";
        }
        sList += std::to_string(pNode->m_value);

        if(pNode->m_pRight) {
            PushsTaskLeftPathUntilNull(pNode->m_pRight, st);
        }
    }
}



template <typename Type> void TraverseTreePostNoRecursion(const AvlTree<Type>& AvlTree, std::string& sList) {
    sList.clear();
    const AvlTreeNode<Type>* pRoot = AvlTree.GetTree();
    if(pRoot == nullptr) {
        return;
    } 

    std::stack<const AvlTreeNode<Type>*> st;
    PushsTaskLeftPathUntilNull(pRoot, st);

    const AvlTreeNode<Type>* pPre = nullptr;
    while(!st.empty()) {
        const AvlTreeNode<Type>* pNode = st.top();
        if(pNode->m_pRight == pPre || pNode->m_pRight == nullptr) {
            st.pop();
            pPre = pNode;
            if(!sList.empty()) {
                sList += " ";
            }
            sList += std::to_string(pNode->m_value);
        }else {
            PushsTaskLeftPathUntilNull(pNode->m_pRight, st);
        }
    }
}

template <typename Type> void TraverseTreeLevelDebug(const AvlTree<Type>& AvlTree) {
    const AvlTreeNode<Type>* pRoot = AvlTree.GetTree();
    if(pRoot == nullptr) {
        return;
    } 

    std::queue<const AvlTreeNode<Type>* > que;
    que.push(pRoot);
    while(!que.empty()) {
        int64_t size = que.size();
        while(size--) {
            const AvlTreeNode<Type>* pNode = que.front();
            que.pop();
            printf("%d, addr %p, left %p, right %p, ", pNode->m_value, pNode, pNode->m_pLeft, pNode->m_pRight);
            if(pNode->m_pLeft) {
                que.push(pNode->m_pLeft);
            }
            if(pNode->m_pRight) {
                que.push(pNode->m_pRight);
            }
        }
        printf("\n");
    }
}

template <typename Type> int TreeIsBalace(const AvlTreeNode<Type>* pRoot, bool& bBalance) {
    if(pRoot == nullptr) {
        bBalance = true;
        return 0;
    }

    int leftHeight = TreeIsBalace(pRoot->m_pLeft, bBalance);
    int rightHeight = TreeIsBalace(pRoot->m_iHeight, bBalance); 
    if(bBalance && abs(leftHeight - rightHeight) > 1) {
        bBalance = false;
    }

    return std::max(leftHeight, rightHeight) + 1;
} 

template <typename Type> bool TreeIsBalace(const AvlTreeNode<Type>& AvlTree) {
    bool bBalance = false;
    return TreeIsBalace(AvlTree.GetTree(), bBalance);
}