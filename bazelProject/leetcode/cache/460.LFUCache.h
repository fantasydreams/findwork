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