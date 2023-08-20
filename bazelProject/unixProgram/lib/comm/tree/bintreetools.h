#pragma once

#include "bintree.h"
#include <cstddef>
#include <string>
#include <stack>
#include <stdio.h>
#include <queue>

template <typename Type>void TraverseTreePreNoRecursion(const BinTree<Type>& BinTree, std::string& sList) {
    sList.clear();
    const BinTreeNode<Type>* pRoot = BinTree.GetNode();
    if(pRoot == nullptr) {
        return;
    }

    std::stack<const BinTreeNode<Type>*> st;
    st.push(pRoot);
    while(!st.empty()) {
        const BinTreeNode<Type>* pNode = st.top();
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


template <typename Type>void TraverseTreeMidNoRecursion(const BinTree<Type>& BinTree, std::string& sList) {
    sList.clear();
    const BinTreeNode<Type>* pRoot = BinTree.GetNode();
    if(pRoot == nullptr) {
        return;
    }

    std::stack<const BinTreeNode<Type>*> st;
    PushsTaskLeftPathUntilNull(pRoot, st);
    while(!st.empty()) {
        const BinTreeNode<Type>* pNode = st.top();
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



template <typename Type> void TraverseTreePostNoRecursion(const BinTree<Type>& BinTree, std::string& sList) {
    sList.clear();
    const BinTreeNode<Type>* pRoot = BinTree.GetNode();
    if(pRoot == nullptr) {
        return;
    } 

    std::stack<const BinTreeNode<Type>*> st;
    PushsTaskLeftPathUntilNull(pRoot, st);

    const BinTreeNode<Type>* pPre = nullptr;
    while(!st.empty()) {
        const BinTreeNode<Type>* pNode = st.top();
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

template <typename Type> void TraverseTreeLevelDebug(const BinTree<Type>& BinTree) {
    const BinTreeNode<Type>* pRoot = BinTree.GetNode();
    if(pRoot == nullptr) {
        return;
    } 

    std::queue<const BinTreeNode<Type>* > que;
    que.push(pRoot);
    while(!que.empty()) {
        int64_t size = que.size();
        while(size--) {
            const BinTreeNode<Type>* pNode = que.front();
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