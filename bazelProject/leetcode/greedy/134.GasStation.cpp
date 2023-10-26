#include "134.GasStation.h"

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    std::vector<int> diff(gas.size(), 0);
    for(int i = 0;i < gas.size(); ++i) {
        diff[i] = gas[i] - cost[i];
        sum += diff[i];
    }

    if(sum < 0) {
        return -1;
    }

    int mayIdx = -1;
    int tmpSum = 0;
    for(int i = 0; i < diff.size(); ++i) {
        if(tmpSum < 0 || tmpSum + diff[i] < 0) {
            tmpSum = 0;
            mayIdx = -1;
            continue;
        }

        if(mayIdx == -1) {
            mayIdx = i;
        }
        tmpSum += diff[i];
    }
    return mayIdx;
}