//
// Created by Sharwen on 2020/2/2.
//

#ifndef C___QUICKSORT_H
#define C___QUICKSORT_H

#include <vector>
#include <algorithm>
using namespace std;
template<class T> class QuickSort{
public:
    void sort(vector<T> & array);

private:
    void quick_sort(vector<T> &array, long start,long end);
    void quick_sort1(vector<T> & array,long start,long end);
};


template <class T>void QuickSort<T>::sort(vector<T> &array) {
//    quick_sort(array,0,(long)array.size()-1);
    quick_sort1(array,0,(long)array.size()-1);
}


template <class T>void QuickSort<T>::quick_sort(vector<T> &array, long start, long end) {
    if(start >= end) return;
    T key_val = array[start];
    long _start = start,_end = end;
    while(_start < _end){
        while(_start < _end && array[_end] > key_val){
            --_end;
        }
        array[_start] = array[_end];
        while(_start < _end && array[_start] < key_val){
            ++_start;
        }
        array[_end] = array[_start];
    }
    array[_start] = key_val;
    quick_sort(array,start,_start-1);
    quick_sort(array,_start+1,end);
}


template<class T> void QuickSort<T>::quick_sort1(vector<T> &array, long start, long end) { //这个代码更简洁，可读性更好
    if(start >= end) return;
    long index = start;
    long small = start;
    for(;index<end;++index){
        if(array[index] < array[end]) { //找最后一个元素的位置，如果比最后一个元素小则start从开始交换
            if (index != small) {
                swap(array[index], array[small]);
            }
            ++small;
        }
    }
    swap(array[small],array[end]);
    quick_sort1(array,start,small-1);
    quick_sort1(array,small + 1,end);


}
#endif //C___QUICKSORT_H
