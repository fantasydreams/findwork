//
// Created by Sharwen on 2020/2/12.
//

#ifndef C___TOOLS_H
#define C___TOOLS_H

#include <iostream>


template<class T>
void print_through_pointer(const T * const pData,size_t len){
    for(auto i=0;i<len;++i){
        std::cout << pData[i] << " ";
    }
}

template<class T>
void print_through_pointer(const T * const pData){
    const T * p = pData;
    while(p){
        std::cout << p->_val << " ";
        p=p->_next;
    }
}



void test_ref(int & a);

template<class T>
void print_vector(const std::vector<T> &array){
    for(auto i = 0; i < array.size();++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


template <class _InputIterator>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
void print_through_iterator(_InputIterator __first, _InputIterator __last){
    for (; __first != __last; ++__first)
        std::cout << (*__first) <<" ";

}

template <class _InputIterator>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
void print_map_or_pair(_InputIterator __begin,_InputIterator __end){
    for(;__begin != __end; ++__begin){
        std::cout << __begin->first << ":" << __begin->second << std::endl;
    }
}


#endif //C___TOOLS_H
