//
// Created by Sharwen on 2020/2/2.
//

#ifndef C___ROTATE_ARRAY_H
#define C___ROTATE_ARRAY_H
#include<vector>
using namespace std;

template <class T> T min_interval(const vector<T> &array,int start,int end){
    if(start > end){
        throw new exception;
    }
    T _min = array[start];
    for(int index = start + 1;index <= end;++index){
        if(_min > array[index]){
            _min = array[index];
        }
    }

    return _min;
}

template<class T> T rotate_min(const vector<T> &array){
    if(array.size() == 0){
        throw new exception;
    }
    int start = 0,end = array.size()-1,mid;
    if(array[start] < array[end]) return array[start];
    while(start + 1 < end){
        if(array[start] == array[end]){
            return min_interval(array,start,end);
        }
        mid = (start + end)/2;
        if(array[start] <= array[mid]){
            start = mid;
        }
        if(array[end] >= array[mid]){
            end = mid;
        }
    }

    return array[end];
}

#endif //C___ROTATE_ARRAY_H
