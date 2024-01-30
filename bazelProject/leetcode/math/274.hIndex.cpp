#include "274.hIndex.h"

int hIndex(vector<int>& citations) {
    std::sort(citations.begin(), citations.end(), std::greater<int>());
    int iAns = 0;
    for(int i = 0; i < citations.size(); ++i) {
        if(i + 1 <= citations[i]) {
            ++iAns;
        }else {
            break;
        }
    }

    return iAns;
}


int hIndexBucketSort(vector<int>& citations) {
    std::vector<int> vecBucket(citations.size() + 1, 0);
    for(int i = 0; i < citations.size(); ++i) {
        int n = citations[i] > citations.size() ? citations.size() : citations[i];
        ++vecBucket[n];
    }

    int iAns = 0;
    for(int i = citations.size(); i > 0; --i) {
        iAns += vecBucket[i];
        if(iAns >= i) {
            return i;
        }
    }

    return 0;
}