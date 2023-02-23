#include "932.BeautifulArray.h"

vector<int> beautifulArray(int n)
{
    vector<int> ways = {1};
    while(ways.size() < n) {
        vector<int> tmp;
        for(auto & num : ways) {
            if(num * 2 - 1  <= n) {
                tmp.push_back(num * 2 - 1);
            }
        }

        for(auto & num : ways) {
            if(num * 2 <= n) {
                tmp.push_back(num * 2);
            }
        }
        swap(ways, tmp);
    }

    return ways;
}