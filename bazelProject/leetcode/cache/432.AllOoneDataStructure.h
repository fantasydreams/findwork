#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    Node(int _freq) :freq(_freq), next(nullptr), pre(nullptr) {};

    unordered_set<string> values;
    int freq;
    Node * next, *pre;
};


class AllOne {
public:
    AllOne():head(-1), tail(-1) {
        head.next = &tail;
        tail.pre = &head;
    }

    void inc(string key) {
        auto pIter = m_hashmap.find(key);
        if(pIter != m_hashmap.end()) {
            pIter->second->values.erase(key);
            int freq = pIter->second->freq;
            Node * tmp = pIter->second;
            if(pIter->second->next == &tail || pIter->second->next->freq != freq + 1) {
                Node * node = new Node(freq + 1);
                node->values.insert(key);
                insertPost(pIter->second, node);
                m_hashmap[key] = node;
            }else {
                pIter->second->next->values.insert(key);
                m_hashmap[key] = pIter->second->next;
            }
            if(tmp->values.empty()) {
                removeNode(tmp);
            }
        }else {
            if(head.next == &tail || head.next->freq != 1) {
                Node * node = new Node(1);
                node->values.insert(key);
                insertPost(&head, node);
                m_hashmap[key] = node;
            }else {
                head.next->values.insert(key);
                m_hashmap[key] = head.next;
            }
        }
    }

    void dec(string key) {
        auto pIter = m_hashmap.find(key);
        if(pIter == m_hashmap.end()) {
            return;
        }

        auto node = pIter->second;
        node->values.erase(key);
        if(node->freq > 1) {
            if((node->pre == &head) || (node->pre->freq != node->freq - 1)) {
                Node * newNode = new Node(node->freq - 1);
                newNode->values.insert(key);
                insertPre(node, newNode);
                m_hashmap[key] = newNode;
            }else {
                node->pre->values.insert(key);
                m_hashmap[key] = node->pre;
            }
        }else {
            m_hashmap.erase(key);
        }

        if(node->values.empty()) {
            removeNode(node);
        }
    }

    string getMaxKey() {
        if(isEmpty()) {
            return "";
        }

        return *(tail.pre->values.begin());
    }

    string getMinKey() {
        if(isEmpty()) {
            return "";
        }

        return *(head.next->values.begin());
    }
private:
    unordered_map<string, Node *> m_hashmap;
    Node head, tail; // head min tail max;

    bool isEmpty() {
        return head.next == &tail;
    }

    void removeNode(Node * node) {
        Node * tmp = node->next;
        node->pre->next = tmp;
        tmp->pre = node->pre;
        delete node;
    }

    void insertPre(Node * pos, Node * tobeIns) {
        tobeIns->pre = pos->pre;
        tobeIns->next = pos;
        pos->pre->next = tobeIns;
        pos->pre = tobeIns;
    }

    void insertPost(Node * pos, Node * tobeIns) {
        tobeIns->next = pos->next;
        pos->next->pre = tobeIns;
        tobeIns->pre = pos;
        pos->next = tobeIns;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */