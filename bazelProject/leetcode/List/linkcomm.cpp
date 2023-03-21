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

static ListNode *detectCycle(ListNode *head)
{
    if(!head) {
        return NULL;
    }

    ListNode * pFast = head, * pSlow = head;
    ListNode * pTmp = NULL;
    do
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast) {
            pFast = pFast->next;
        }

        if(pFast && (pFast == pSlow)) 
        {
            pTmp = pFast;
            break;
        }
    }while(pFast && pSlow);
    
    if(!pTmp) {
        return NULL;
    }

    ListNode * pCur = head;
    while(pCur != pTmp)
    {
        pCur = pCur->next;
        pTmp = pTmp->next;
    }

    return pCur;
}

void freeCircleLinkList(ListNode * linkList)
{
    ListNode * pCircle = detectCycle(linkList);
    if(pCircle)
    {
        while(linkList)
        {
            ListNode * pTmpNode = linkList;
            linkList = linkList->next;
            delete pTmpNode;

            if(linkList == pCircle){
                break;
            }
        }
    }else{
        freeLinkList(linkList);
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


bool ListValEqual(ListNode * pLista, ListNode * pListb) {
    while(pLista && pListb) {
        if(pLista->val != pListb->val) {
            return false;
        }
        pLista = pLista -> next;
        pListb = pListb -> next;
    }

    return (pLista == nullptr) && (pListb == nullptr);
}

void printList(ListNode * pList) {
    while(pList) {
        printf("%d ", pList->val);
        pList = pList -> next;
    }
    printf("\n");
}


size_t getLinkLen(ListNode * pList) {
    size_t len = 0;
    while(pList) {
        ++len;
        pList = pList -> next;
    }

    return len;
}


void createIntersection(const std::vector<int> & vecAHead,  const std::vector<int> & vecBHead, const std::vector<int> & vecSection, ListNode * &aHead, ListNode * &bHead) {
    ListNode oComm, * tmp = &oComm;
    for(size_t idx = 0; idx < vecSection.size(); ++idx) {
        tmp->next = new ListNode(vecSection[idx]);
        tmp = tmp -> next;
    }

    ListNode oHeadA;
    tmp = &oHeadA;
    for(size_t idx = 0; idx < vecAHead.size(); ++idx) {
        tmp->next = new ListNode(vecAHead[idx]);
        tmp = tmp -> next;
    }

    tmp -> next = oComm.next;

    ListNode oHeadB;
    tmp = &oHeadB;
    for(size_t idx = 0; idx < vecBHead.size(); ++idx) {
        tmp->next = new ListNode(vecBHead[idx]);
        tmp = tmp -> next;
    }

    tmp -> next = oComm.next;
    aHead = oHeadA.next;
    bHead = oHeadB.next;
}