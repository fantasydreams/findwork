#include "212.WordSearchII.h"
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class TrieNode {
public:
    TrieNode() : m_bIsVal(false) {}
    bool m_bIsVal;
    std::unordered_map<char, TrieNode> m_mapNext;
}; 

class Trie {
public:
    Trie(){}
    virtual ~Trie(){}
    void insert(const string& word) {
        TrieNode * pNextPointer = &m_root;
        for(const auto& ch : word) {
            auto& oNextNode = ((pNextPointer)->m_mapNext)[ch];
            pNextPointer = &oNextNode;
        }
        pNextPointer->m_bIsVal = true;
    }

    bool search(string word) {
        TrieNode* pNode = &m_root;
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
        TrieNode* pNode = &m_root;
        for(const auto& ch : prefix) {
            auto pIter = pNode->m_mapNext.find(ch);
            if(pIter == pNode->m_mapNext.end()) {
                return false;
            }
            pNode = &(pIter->second);
        }

        return true;
    }

    const TrieNode& GetRoot() {
        return m_root;
    }

private:
    TrieNode m_root;
};

void dfs(const vector<vector<char> >& board, const TrieNode& tNode, std::string& sTmp, int row, int col, std::unordered_set<std::string>& setAns, std::vector<std::vector<bool> >& vecVisited) {
    // if(row < 0 || row >= board.size() || col < 0 || col >= board[row].size()) {
    //     return;
    // }

    if(tNode.m_bIsVal) {
        setAns.insert(sTmp);
    }

    static std::vector<int> dir = {-1, 0, 1, 0, -1};
    for(int i = 0; i < 4; ++i) {
        int iNextRow = row + dir[i];
        int iNextCol = col + dir[i + 1];

        if(iNextRow < 0 || iNextRow >= board.size() || iNextCol < 0 || iNextCol >= board[iNextRow].size() || vecVisited[iNextRow][iNextCol]) {
            continue;
        }

        auto pIter = tNode.m_mapNext.find(board[iNextRow][iNextCol]);
        if(pIter == tNode.m_mapNext.end()) {
            continue;;
        }

        sTmp.push_back(board[iNextRow][iNextCol]);
        vecVisited[iNextRow][iNextCol] = true;
        dfs(board, pIter->second, sTmp, iNextRow, iNextCol, setAns, vecVisited);
        vecVisited[iNextRow][iNextCol] = false;
        sTmp.pop_back();
    }
};

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    std::vector<std::string> vecAns;
    std::unordered_set<std::string> set;
    if(words.empty() || board.empty() || board[0].empty()) {
        return vecAns;
    }

    Trie TrieTree;
    for(const auto& word : words) {
        TrieTree.insert(word);
    }

    std::vector<std::vector<bool> >vecVisited(board.size(), std::vector<bool>(board[0].size(), false));
    for(int row = 0; row < board.size(); ++row) {
        for(int col = 0; col < board[row].size(); ++col) {
            const auto tRoot = TrieTree.GetRoot();
            auto pIter = tRoot.m_mapNext.find(board[row][col]);
            if(pIter == tRoot.m_mapNext.end()) {
                continue;
            }

            std::string sTmp;
            sTmp.push_back(board[row][col]);
            vecVisited[row][col] = true;
            dfs(board, pIter->second, sTmp, row, col, set, vecVisited);
            vecVisited[row][col] = false;
        }
    }
    
    for_each(set.begin(), set.end(), [&](const std::string& str){vecAns.emplace_back(std::move(str));});
    return vecAns;
}


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
    
    bool search(const string& word) {
        auto pIter = &m_root;
        for(const auto & ch : word) {
            auto pIterNext = pIter->m_mapNext.find(ch);
            if(pIterNext == pIter->m_mapNext.end()) {
                return false;
            }
            pIter = &pIterNext->second;
        }

        return pIter->m_bIsVal;
    }
    
    bool startsWith(const string& prefix) {
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

    const TrieNode2& GetRoot() {
        return m_root;
    }
private:
    TrieNode2 m_root;
};


void DFS(vector<vector<char> >& board, const TrieNode2& oNode, std::string& sTmp, int row, int col, std::unordered_set<std::string>& setFinds, std::vector<std::vector<bool> >&vecVisited) {
    if(oNode.m_bIsVal) {
        setFinds.insert(sTmp);
    }

    static std::vector<int> vec = {-1, 0, 1, 0, -1};
    for(int i = 0; i < 4; ++i) {
        int nextx = row + vec[i];
        int nexty = col + vec[i + 1];
        if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[nextx].size() || vecVisited[nextx][nexty]) {
            continue;
        }

        auto pIter = oNode.m_mapNext.find(board[nextx][nexty]);
        if(pIter == oNode.m_mapNext.end()) {
            continue;
        }

        vecVisited[nextx][nexty] = true;
        sTmp.push_back(board[nextx][nexty]);
        DFS(board, pIter->second, sTmp, nextx, nexty, setFinds, vecVisited);
        sTmp.pop_back();
        vecVisited[nextx][nexty] = false;
    }
    
}

vector<string> findWords1(vector<vector<char> >& board, vector<string>& words) {
    std::vector<std::string> vecAns;
    std::unordered_set<std::string> setFinds;
    std::vector<std::vector<bool> >vecVisited(board.size(), std::vector<bool>(board[0].size(), false));
    if(board.empty() || board[0].empty() || words.empty()) {
        return vecAns;
    }

    Trie2 oTire;
    for_each(words.begin(), words.end(), [&](const std::string& sStr){oTire.insert(sStr);});
    for(int row = 0; row < board.size(); ++row) {
        for(int col = 0; col < board[row].size(); ++col) {
            auto pIter = oTire.GetRoot().m_mapNext.find(board[row][col]);
            if(pIter == oTire.GetRoot().m_mapNext.end()) {
                continue;
            }

            std::string sTmp;
            sTmp.push_back(board[row][col]);
            vecVisited[row][col] = true;
            DFS(board, pIter->second, sTmp, row, col, setFinds, vecVisited);
            vecVisited[row][col] = false;
        }
    }


    for_each(setFinds.begin(), setFinds.end(), [&](const std::string& sStr){vecAns.emplace_back(std::move(sStr));});
    return vecAns;
}