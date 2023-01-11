#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cinttypes>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode * createLinkList(const std::vector<int> & vec);
ListNode * createCircleLinkList(const std::vector<int> & vec, int pos);
void freeLinkList(ListNode * linkList);
void freeCircleLinkList(ListNode * linkList);
std::vector<int> convertLink2Vector(ListNode * pList);
ListNode * revertList(ListNode * pList);
ListNode * revertListNewList(ListNode * pList);