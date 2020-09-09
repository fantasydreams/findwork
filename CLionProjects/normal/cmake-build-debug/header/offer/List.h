//
// Created by Sharwen on 2020/2/6.
//

#ifndef C___LIST_H
#define C___LIST_H

#ifdef __DEBUG__
#include <iostream>
using namespace std;
#endif



template <class T> class ListNode{
public:
    ListNode(){m_p_next = nullptr;};
    inline T get(){
        return value;
    }

    inline void set(const T &  val){
        value = val;
    }

    inline ListNode * get_next(){
        return m_p_next;
    }

    inline void set_next(ListNode<T> * next){
        m_p_next = next;
    }

private:
    ListNode<T> * m_p_next;
    T value;
};



#endif
template <class T> class List;
template <class T> void print_list(const List<T> &list);

template<class T> class List{
public:
    List();
    ~List();

    void insert_node(T val);
    void insert_node(ListNode<T> * node);
    bool delete_node(T val);
    bool delete_node(ListNode<T> *to_be_deleted);
    ListNode<T> * get_node(T val);

#ifdef __DEBUG__
    friend void print_list<>(const List<T> &list);
#endif

private:
    ListNode<T> *_p_to_head;
    ListNode<T> * _tail;
};

template<class T> List<T>::List(){
    _p_to_head = new ListNode<T>;
    _tail = nullptr;
}

template <class T> void List<T>::insert_node(T val){
    ListNode<T> *p= new ListNode<T>;
    p->set(val);

    if(!_tail){
        _p_to_head->set_next(p);
    }else{
        _tail->set_next(p);
    }

    _tail = p;
}

template<class T> List<T>::~List(){
    ListNode<T> * p = _p_to_head;
    while(p){
        ListNode<T> * to_be_delete = p;
        p = p->get_next();
        delete to_be_delete;
    }
}

template<class T> void List<T>::insert_node(ListNode<T> * node){
    if(!_tail){
        _p_to_head->set_next(node);
    }else{
        _tail->set(node);
    }
    _tail = node;
}

template<class T> bool List<T>::delete_node(T val){
    ListNode <T> * p = _p_to_head;
    while(p->get_next()){
        if(p->get_next()->get() == val){
            ListNode<T> *to_be_deleted = p->get_next();
            p->set_next(to_be_deleted->get_next());

            if(to_be_deleted == _tail){
                _tail = p;
            }

            delete to_be_deleted;
            return true;
        }
        p = p->get_next();
    }
    return false;
}

template<class T> bool List<T>::delete_node(ListNode<T> *to_be_deleted) {
    if(!_tail){
        return false;
    }

    if(_tail != to_be_deleted) {
        ListNode<T> *_to_be_deleted = to_be_deleted->get_next();
        to_be_deleted->set(_to_be_deleted->get());
        to_be_deleted->set_next(_to_be_deleted->get_next());

        if (_to_be_deleted == _tail) {
            _tail = to_be_deleted;
        }

        return true;
    }else{
        ListNode<T> * p = _p_to_head;
        while(p->get_next()){
            if(p->get_next() == to_be_deleted){
                p->set_next(nullptr);
                delete to_be_deleted;
                _tail = p;
                return true;
            }
        }
        return false;
    }
}

template<class T> ListNode<T> * List<T>::get_node(T val) {
    ListNode<T> * p = _p_to_head->get_next();
    while(p){
        if(p->get() == val){
            return p;
        }
        p=p->get_next();
    }
    return nullptr;
}

#ifdef __DEBUG__
template<class T> void print_list(const List<T> &list){
    ListNode<T> * p = list._p_to_head->get_next();
    while(p){
        cout << p->get()<< "\t";
        p=p->get_next();
    }
}

#endif //C___LIST_H
