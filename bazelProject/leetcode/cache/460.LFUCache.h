#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) : m_capacity(capacity), m_allocsize(0), m_freq(0){
    }
    
    int get(int key);
    void put(int key, int value);
    void insert(int key, int value, int freq);

private: 
    int m_capacity;
    int m_allocsize;
    int m_minfreq;

    std::unordered_map<int, std::list<std::pair<int, int>>> m_freq; // frequency  map to [key, value]
    std::unordered_map<int, std::pair<int, std::list<std::pair<int, int>>::iterator>> m_cache; // [key, [freq, iter]]
};


class LFUCache1{
public:
    LFUCache1(int capacity): m_capacity(capacity), m_cursize(0), m_minfreq(0) {}

    int get(int key) {
        auto pIter = m_cache.find(key);
        if(pIter == m_cache.end()) {
            return -1;
        }

        int freq = pIter->second.first;
        auto pIterListNode = pIter->second.second;
        auto & newList = m_freqList[freq + 1];
        newList.splice(newList.begin(), m_freqList[freq], pIterListNode);
        // list.splice(list.pos_iter, other, other_pos1_iter);
        pIter->second.first += 1;
        if(m_freqList[freq].empty()) {
            m_freqList.erase(freq);
            if(m_minfreq == freq) {
                m_minfreq = freq + 1;
            }
        }
        return pIterListNode->second;
    }

    void put(int key, int value) {
        if(m_capacity <= 0){
            return;
        }
        auto pIter = m_cache.find(key);
        if(pIter != m_cache.end()) {
            pIter->second.second->second = value;
            get(key);
            return;
        }

        if(m_cursize >= m_capacity) {
            m_cache.erase(m_freqList[m_minfreq].back().first);
            m_freqList[m_minfreq].pop_back();
            if(m_minfreq != 1 && m_freqList[m_minfreq].empty()) {
                m_freqList.erase(m_minfreq);
            }
            --m_cursize;
        }

        ++m_cursize;
        m_minfreq = 1;
        m_freqList[m_minfreq].push_front({key, value});
        m_cache.insert({key, {m_minfreq, m_freqList[m_minfreq].begin()}});
    }
private:
    int m_capacity;
    int m_cursize;
    int m_minfreq; 

    std::unordered_map<int, std::list<std::pair<int, int> > > m_freqList; // freq map to [key value]
    std::unordered_map<int, std::pair<int, std::list<std::pair<int, int> >::iterator> > m_cache; // key to [freq, iter]
};