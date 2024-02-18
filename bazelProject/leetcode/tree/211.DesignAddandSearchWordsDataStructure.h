#include "treecomm.h"
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

class TrieNode2 {
public:
    TrieNode2() : m_bIsVal(false) {}
    bool m_bIsVal;
    std::unordered_map<char, TrieNode2> m_mapNext;
}; 

class Trie2 {
public:
    Trie2() {

    }
    
    void insert(const string& word) {
        auto pIter = &m_root;
        for(const auto& ch : word) {
            pIter = &pIter->m_mapNext[ch];
        }
        pIter->m_bIsVal = true;
    }
    
    
    bool search(TrieNode2* pIter, const std::string & sWord, int iLoc) {
        for(int i = iLoc; i < sWord.size(); ++i) {
            if(sWord[i] == '.') {
                bool bAns = false;
                for(auto pIterNew = pIter->m_mapNext.begin(); pIterNew != pIter->m_mapNext.end() && !bAns; ++pIterNew) {
                    bAns = search(&pIterNew->second, sWord, i + 1);
                }
                return bAns;
            }else {
                auto pIterNext = pIter->m_mapNext.find(sWord[i]);
                if(pIterNext == pIter->m_mapNext.end()) {
                    return false;
                }
                pIter = &pIterNext->second;
            }
        }

        return pIter->m_bIsVal;
    }

    bool search(const string& word) {
        return search(&m_root, word, 0);
    }

    bool startsWith(string prefix) {
        auto pIter = &m_root;
        for(const auto & ch : prefix) {
            auto pIterNext = pIter->m_mapNext.find(ch);
            if(pIterNext == pIter->m_mapNext.end()) {
                return false;
            }
            pIter = &pIterNext->second;
        }
        return true;
    }
private:
    TrieNode2 m_root;
};


class WordDictionary1 {
public:
    WordDictionary1() {

    }
    
    void addWord(string word) {
        m_trie.insert(word);
    }
    
    bool search(string word) {
        if(word.empty()) {
            return false;
        }

        return m_trie.search(word);
    }

private:
    Trie2 m_trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */