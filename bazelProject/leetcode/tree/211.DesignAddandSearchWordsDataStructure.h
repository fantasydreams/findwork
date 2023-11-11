#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode() : m_bIsVal(false) {}
    bool m_bIsVal;
    std::unordered_map<char, TrieNode> m_mapNext;
}; 

class Trie1 {
public:
    Trie1(){}
    virtual ~Trie1(){}
    void insert(const string& word) {
        TrieNode * pNextPointer = &m_root;
        for(const auto& ch : word) {
            auto& oNextNode = ((pNextPointer)->m_mapNext)[ch];
            pNextPointer = &oNextNode;
        }
        pNextPointer->m_bIsVal = true;
    }

    bool search(const TrieNode & oNode, std::string& word, int pos) {
        const TrieNode* pNode = &oNode;
        for(int i = pos; i < word.size(); ++i) {
            if(word[i] == '.') {
                if(i == word.size()) {
                    for(auto pIter = pNode->m_mapNext.begin(); pIter != pNode->m_mapNext.end(); ++pIter) {
                        if(pIter->second.m_bIsVal == true) {
                            return true;
                        }
                    }
                    return false;
                }
                bool bRes = false;
                for(auto pIter = pNode->m_mapNext.begin(); pIter != pNode->m_mapNext.end() && !bRes; ++pIter) {
                    bRes = search(pIter->second, word, i + 1);
                }
                return bRes;
            }else {
                auto pIter = pNode->m_mapNext.find(word[i]);
                if(pIter != pNode->m_mapNext.end()) {
                    pNode = &(pIter->second);
                }else {
                    return false;
                }
            }
        }
        return pNode->m_bIsVal;
    }

    bool search(string word) {
        return search(m_root, word, 0);
    }

private:
    TrieNode m_root;
};

class WordDictionary {
public:
    WordDictionary() {
    }
    
    void addWord(const string& word) {
        m_trie.insert(word);
    }
    
    bool search(const string& word) {
        if(word.empty()) {
            return false;
        }

        return m_trie.search(word);
    }
private:
    Trie1 m_trie;
};