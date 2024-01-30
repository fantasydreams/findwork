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


int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    int mayIdx = -1;
    int tmpSum = 0;
    for(int i = 0;i < gas.size(); ++i) {
        int diff = gas[i] - cost[i];
        sum += diff;
        if(tmpSum < 0 || tmpSum + diff < 0) {
            mayIdx = -1;
            tmpSum = 0;
            continue;
        }

        if(mayIdx == -1) {
            mayIdx = i;
        }
        tmpSum += diff;        
    }

    if(sum < 0) {
        return -1;
    }

    return mayIdx;
}


int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int iMayIdx = -1, sum = 0, tmpSum = 0;
    for(int i = 0; i < gas.size(); ++i) {
        int iDiff = gas[i] - cost[i];
        sum += iDiff;

        if(tmpSum < 0 || tmpSum + iDiff < 0)  {
            iMayIdx = -1;
            tmpSum = 0;
            continue;
        }

        if(iMayIdx == -1) {
            iMayIdx = i;
        }
        tmpSum += iDiff;
    }

    if(sum < 0) {
        return -1;
    }
    return iMayIdx;
}