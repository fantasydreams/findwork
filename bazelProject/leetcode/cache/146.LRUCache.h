#include <unordered_map>
#include <list>
#include <cassert>

struct cachenode
{
    int key;
    int val;
    struct cachenode * pre;
    struct cachenode * next;

    cachenode() : key(0), val(0), pre(NULL), next(NULL){}
    cachenode(int _key, int value) : key(_key), val(value), pre(NULL), next(NULL){}
};

class LRUCache 
{
public:
    LRUCache(int capacity) : m_capacity(capacity), m_allocsize(0) 
    {
        assert(m_capacity);
        head = new cachenode();
        tail = new cachenode();
        head->next = tail;
        tail->pre = head;
    }

    ~LRUCache()
    {
        for(auto pnode = head; pnode; pnode=pnode->next) {
            delete pnode;
        }    
    }

    int get(int key);
    void put(int key, int value);

private:
    int m_capacity;
    int m_allocsize;
    cachenode * head, * tail;
    std::unordered_map<int, cachenode *> keymap;
};


class LRUCache1
{
public:
    LRUCache1(int capacity) : m_capacity(capacity) {
    }

    int get(int key) {
        auto pIter = m_hashmap.find(key);
        if(pIter == m_hashmap.end()) {
            return -1;
        }

        m_cache.splice(m_cache.begin(), m_cache, pIter->second);
        return pIter->second->second;
    }
    void put(int key, int value) {
        auto pIter = m_hashmap.find(key);
        if(pIter != m_hashmap.end()) {
            pIter->second->second = value;
            m_cache.splice(m_cache.begin(), m_cache, pIter->second);
        }else {
            m_cache.push_front({key, value});
            m_hashmap.insert({key, m_cache.begin()});
            if(m_cache.size() > m_capacity) {
                m_hashmap.erase(m_cache.back().first);
                m_cache.pop_back();
            }
        }
    }

private:
    int m_capacity;
    std::list<std::pair<int, int>> m_cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_hashmap;
};


class LRUCache2 {
public:
    LRUCache2(int capacity) : m_capacity(capacity) {
    }

    int get(int key) {
        auto pIter = m_hashmap.find(key);
        if(pIter == m_hashmap.end()) {
            return -1;
        }

        m_cache.splice(m_cache.begin(), m_cache, pIter->second);
        return pIter->second->second;
    }

    void put(int key, int value) {
        auto pIter = m_hashmap.find(key);
        if(pIter != m_hashmap.end()) {
            pIter->second->second = value;
            m_cache.splice(m_cache.begin(), m_cache, pIter->second);
        }else {
            if(m_cache.size() >= m_capacity) {
                m_hashmap.erase(m_cache.back().first);
                m_cache.pop_back();
            }

            m_cache.push_front({key, value});
            m_hashmap.insert({key, m_cache.begin()});
        }
    } 
private:
    int m_capacity;
    std::list<std::pair<int, int> > m_cache;
    std::unordered_map<int, std::list<std::pair<int, int> >::iterator> m_hashmap;
};

class LRUCache3 {
public:
    LRUCache3(int capacity) : m_capacity(capacity) {        
    }

    int get(int key) {
        auto pIter = m_hashmap.find(key);
        if(pIter != m_hashmap.end()) {
            m_cache.splice(m_cache.begin(), m_cache, pIter->second);
            return pIter->second->second;
        }else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto pIter = m_hashmap.find(key);
        if(pIter != m_hashmap.end()) {
            pIter->second->second = value;
            m_cache.splice(m_cache.begin(), m_cache, pIter->second);
        }else {
            if(m_cache.size() >= m_capacity) {
                m_hashmap.erase(m_cache.back().first);
                m_cache.pop_back();
            }

            m_cache.push_front({key, value});
            m_hashmap.insert({key, m_cache.begin()});
        }
    }

private:
    int m_capacity;
    std::list<std::pair<int, int> > m_cache;
    std::unordered_map<int, std::list<std::pair<int, int> >::iterator> m_hashmap;
};
