#include "linkcomm.h"

ListNode * createLinkList(const std::vector<int> & vec)
{
    if(vec.size() == 0) return nullptr;
    ListNode * pLinkHead = nullptr;

    for(int64_t idx = vec.size() - 1; idx >= 0; --idx)
    {
        ListNode * pTmpNode = new ListNode(vec[idx]);
        pTmpNode->next = pLinkHead;
        pLinkHead = pTmpNode;
    }

    return pLinkHead;
}

ListNode * createCircleLinkList(const std::vector<int> & vec, int pos)
{
    if(vec.size() == 0) return nullptr;
    ListNode * pLinkHead = nullptr;

    ListNode * pLastPtr = NULL, * pPosPtr = NULL;
    for(int64_t idx = vec.size() - 1; idx >= 0; --idx)
    {
        ListNode * pTmpNode = new ListNode(vec[idx]);
        pTmpNode->next = pLinkHead;
        pLinkHead = pTmpNode;

        if(idx == vec.size() - 1) {
            pLastPtr = pTmpNode;
        }
        if(idx == pos) {
            pPosPtr = pTmpNode;
        }
    }

    if(pLastPtr && pPosPtr) {
        pLastPtr->next = pPosPtr;
    }

    printf("%" PRIu64 "\n", (uint64_t)pPosPtr);

    return pLinkHead;
}



void freeLinkList(ListNode * linkList)
{
    while(linkList)
    {
        ListNode * pTmpNode = linkList;
        linkList = linkList->next;
        delete pTmpNode;
    }
}

std::vector<int> convertLink2Vector(ListNode * pList)
{
    std::vector<int> res;
    ListNode * pTmpNode = pList;
    while(pTmpNode)
    {
        res.push_back(pTmpNode->val);
        pTmpNode = pTmpNode->next;
    }
    return res;
}

ListNode * revertList(ListNode * pList)
{
    if(!pList) return nullptr;
    ListNode * pNewHead = pList;
    pList = pList->next;
    pNewHead->next = nullptr;

    while(pList)
    {
        ListNode * pTmpNode = pList;
        pList = pList->next;
        pTmpNode->next = pNewHead;
        pNewHead = pTmpNode;
    }
    
    return pNewHead;
}

ListNode * revertListNewList(ListNode * pList)
{
    if(!pList) return nullptr;
    ListNode * pNewHead = nullptr, *pCurNode = nullptr;
    ListNode * pTmpList = pList;
    while(pTmpList)
    {
        ListNode * pTmpNode = new ListNode(pTmpList->val);
        pTmpNode->next = pNewHead;
        pNewHead = pTmpNode;

        pTmpList = pTmpList->next;
    }
    
    return pNewHead;
}