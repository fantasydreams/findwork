#include <string>
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