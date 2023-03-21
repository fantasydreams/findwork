#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand();
    }
    
    bool insert(int val) {
        auto pIter = m_hashtable.find(val);
        if(pIter != m_hashtable.end()) {
            return false;
        }

        m_data.push_back(val);
        m_hashtable.insert({val, m_data.size() - 1});
        return true;
    }
    
    bool remove(int val) {
        auto pIter = m_hashtable.find(val);
        if(pIter == m_hashtable.end()) {
            return false;
        }

        int key = m_data.back();
        swap(m_data[pIter->second], m_data.back());
        m_data.pop_back();
        m_hashtable[key] = pIter->second;
        m_hashtable.erase(pIter);
        return true;
    }
    
    int getRandom() {
        int size = m_data.size();
        int randomIdx = rand() %  size;
        return m_data[randomIdx];
    }
private:
    vector<int> m_data;
    unordered_map<int, int> m_hashtable;
};