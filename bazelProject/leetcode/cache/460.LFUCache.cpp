#include "460.LFUCache.h"

void LFUCache::insert(int key, int value, int freq)
{
    m_freq[freq].push_back({key, value});
    m_cache[key] = {freq, --m_freq[freq].end()};
}


int LFUCache::get(int key)
{
    auto iter = m_cache.find(key);
    if(iter == m_cache.end()) {
        return -1;
    }

    auto node = iter -> second.second;
    int freq = iter -> second.first;
    int value = node->second;
    m_freq[freq].erase(node);
    if(freq == m_minfreq && m_freq[freq].size() == 0) {
        ++m_minfreq;
    }
    
    insert(key, value, freq + 1);
    return value;
}

void LFUCache::put(int key, int value)
{
    if(m_capacity == 0) {
        return;
    }
    if(m_cache.count(key) != 0) 
    {
        auto iter = m_cache.find(key);
        (iter -> second.second->second) = value;
        get(key);
        return;
    }

    if(m_allocsize == m_capacity)
    {
        auto iter = m_freq[m_minfreq].begin();
        m_cache.erase(iter->first);
        m_freq[m_minfreq].erase(iter);
    }else {
        ++m_allocsize;
    }
    m_minfreq = 1;
    insert(key, value, m_minfreq);
}