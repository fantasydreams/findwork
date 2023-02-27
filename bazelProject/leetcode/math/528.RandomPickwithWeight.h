#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        vecPartialSum.resize(w.size());
        std::partial_sum(w.begin(), w.end(), vecPartialSum.begin());
        srand(time(NULL));
    }
    
    int pickIndex() {
        int iRand = rand() % (vecPartialSum.back() + 1); // 这里是按照权重来的，所以0一定不能包含在内，不然概率就不对了
        auto iter = lower_bound(vecPartialSum.begin(), vecPartialSum.end(), iRand);
        return std::distance(vecPartialSum.begin(), iter);
    }
private:
    std::vector<int> vecPartialSum;
};