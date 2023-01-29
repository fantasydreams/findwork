#include "146.LRUCache.h"

int LRUCache::get(int key)
{
    if(keymap.count(key) == 0) {
        return -1;
    }

    cachenode * node = keymap[key];
    node->pre->next = node->next;
    node->next->pre = node->pre;

    node->next = head->next;
    head->next->pre = node;
    node->pre = head;
    head->next = node;
    return node->val;
}

void LRUCache::put(int key, int value)
{
    if(get(key) != -1) 
    {
        cachenode * node = keymap[key];
        node->val = value;
        return;
    }

    if(m_allocsize < m_capacity)
    {
        cachenode * newnode = new cachenode(key, value);
        newnode->next = head->next;
        newnode->pre = head;
        head->next->pre = newnode;
        head->next = newnode;

        keymap[key] = newnode;
        ++m_allocsize;
    }else 
    {
        cachenode * node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;

        keymap.erase(node->key);
        node->val = value;
        node->key = key;

        head->next->pre = node;
        node->next = head->next;
        node->pre  = head;
        head->next = node;
        keymap[key] = node;
    }
}