#include <unordered_map>

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