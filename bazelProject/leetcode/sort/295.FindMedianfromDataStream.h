#include <functional>
#include <queue>
#include <algorithm>

class MedianFinder {
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if((count & 0x1) == 0) {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }else {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        ++count;
    }
    
    double findMedian() {
        if(count & 0x1) {
            return maxheap.top();
        }else {
            return ((double)minheap.top() + maxheap.top()) / 2;
        }
    }

private:
    std::priority_queue<int, std::vector<int>, std::less<int> > minheap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > maxheap;
    int count;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */