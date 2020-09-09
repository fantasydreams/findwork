//
// Created by Sharwen on 2020/1/2.
//

#include <arpa/inet.h>
#include "../header/offer/INET_PTON.h"

void Inet_PtoN(int family,const char * str,void * bin){
    inet_pton(family,str,bin);
}
