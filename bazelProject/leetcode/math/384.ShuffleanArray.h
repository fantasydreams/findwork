#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    Solution(vector<int>& nums);
    
    vector<int> reset();
    
    vector<int> shuffle();

private:
    std::vector<int> origin;
    std::vector<int> shuffled;
};