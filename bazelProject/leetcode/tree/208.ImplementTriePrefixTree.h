#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode():m_isVal(false), m_List(26, 0) {
    }
    ~TrieNode() {
        for(int i = 0; i < 26; ++i) {
            if(m_List[i] != nullptr) {
                delete m_List[i];
                m_List[i] = nullptr;
            }
        }
    }

    std::vector<TrieNode *> m_List;
    bool m_isVal;
};

// 这一版问题很大，内存泄漏！！
class Trie {
public:
    Trie() {
        m_root = new TrieNode();
    }
    ~Trie() {
        delete m_root;
        m_root = nullptr;
    }
    
    void insert(string word) {
        TrieNode * tmp = m_root;
        for(int i = 0; i < word.size(); ++i) {
            if(tmp->m_List[word[i] - 'a'] == nullptr) {
                tmp->m_List[word[i] - 'a'] = new TrieNode();
            }
            tmp = tmp->m_List[word[i] - 'a'];
        }
        tmp->m_isVal = true;
    }
    
    bool search(string word) {
        TrieNode * tmp = m_root;
        for(int i = 0; i < word.size(); ++i) {
            if(tmp->m_List[word[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->m_List[word[i] - 'a'];
        }
        return tmp->m_isVal;
    }
    
    bool startsWith(string prefix) {
        TrieNode * tmp = m_root;
        for(int i = 0; i < prefix.size(); ++i) {
            if(tmp->m_List[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->m_List[prefix[i] - 'a'];
        }

        return true;
    }

private:
    TrieNode * m_root;
};


class TrieNode1 {
public:
    TrieNode1() : m_bIsVal(false) {}
    bool m_bIsVal;
    std::unordered_map<char, TrieNode1> m_mapNext;
}; 

class Trie1 {
public:
    Trie1(){}
    virtual ~Trie1(){}
    void insert(const string& word) {
        TrieNode1 * pNextPointer = &m_root;
        for(const auto& ch : word) {
            auto& oNextNode = ((pNextPointer)->m_mapNext)[ch];
            pNextPointer = &oNextNode;
        }
        pNextPointer->m_bIsVal = true;
    }

    bool search(string word) {
        TrieNode1* pNode = &m_root;
        for(const auto& ch : word) {
            auto pIter = pNode->m_mapNext.find(ch);
            if(pIter != pNode->m_mapNext.end()) {
                pNode = &(pIter->second);
            }else {
                return false;
            }
        }

        return pNode->m_bIsVal;
    }

    bool startsWith(string prefix) {
        TrieNode1* pNode = &m_root;
        for(const auto& ch : prefix) {
            auto pIter = pNode->m_mapNext.find(ch);
            if(pIter == pNode->m_mapNext.end()) {
                return false;
            }
            pNode = &(pIter->second);
        }

        return true;
    }

private:
    TrieNode1 m_root;
};