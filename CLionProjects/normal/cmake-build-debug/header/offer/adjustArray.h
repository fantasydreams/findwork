//
// Created by Sharwen on 2020/2/22.
//

#ifndef C___ADJUSTARRAY_H
#define C___ADJUSTARRAY_H
#include <iostream>

void ajust_array(int *pData,size_t len, bool (*func)(int val));
bool isEvent(int val);

#endif //C___ADJUSTARRAY_H


