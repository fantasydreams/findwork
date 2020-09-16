//
// Created by sharwenluo on 2020/9/14.
//

#include "../type.h"
#ifndef NORMAL_NOWCODER_H
#define NORMAL_NOWCODER_H

class My_LRU{
public:
    My_LRU(size_t size):_max_size(size),_size(0){
        _head = new DoubleLinkNode();
        _tail = new DoubleLinkNode();
        _head->next = _tail;
        _tail->pre = _head;

    };
    ~My_LRU(){
        delete _head,_tail,_head = nullptr,_tail=nullptr;
        for(auto it : _hash_map){
            delete it.second;
        }
    };

    bool set(string key,int value){
        auto it = _hash_map.find(key);
        if(it != _hash_map.end()){
            DoubleLinkNode * node = it->second;
            if(node->pre == _head){
                node->_value = value;
                return true; //已经是第一个节点不用调整
            }
            node->pre->next = node->next;
            node->next->pre = node->pre;

            node->next = _head->next;
            _head->next->pre = node;
            _head->next = node;
            node->pre = _head;
            node->_value = value;
            return true;
        }else{
            if(_size >= _max_size){
                --_size;
                string key = _tail->pre->_key;
                DoubleLinkNode * node = _tail->pre;
                node->pre->next = _tail;
                _tail->pre = node->pre;
                delete node;
                _hash_map.erase(key);
            }
            DoubleLinkNode * node = new DoubleLinkNode(key,value);
            _hash_map[key] = node;
            node->next = _head->next;
            node->pre = _head;
            _head->next->pre=node;
            _head->next = node;

            ++_size;
            return true;
        }
    }

    bool get(string key,int &value){
        auto it = _hash_map.find(key);
        if(it!=_hash_map.end()){
            value = it->second->_value;
            DoubleLinkNode * node = it->second;
            if(node != _head->next){
                node->pre->next = node->next;
                node->next->pre = node->pre;

                node->next = _head->next;
                _head->next->pre = node;
                _head->next = node;
                node->pre = _head;
            }
            return true;
        }
        return false;
    }

private:
    DoubleLinkNode * _head, *_tail;
    unordered_map<string, DoubleLinkNode *> _hash_map;
    size_t _max_size;
    size_t _size;
};


class SolutionLRU {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */


    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> cache_res;
        My_LRU lru_client(k);
        for(size_t idx = 0;idx < operators.size();++idx){
            if(operators[idx][0] == 1){
                string key = to_string(operators[idx][1]);
                int value = operators[idx][2];
                lru_client.set(key,value);
            }else{
                string key = to_string(operators[idx][1]);
                int value = 0;
                bool res = lru_client.get(key,value);
                if(res == false) cache_res.push_back(-1);
                else cache_res.push_back(value);
            }
        }

        return cache_res;

    }
};

#endif //NORMAL_NOWCODER_H
