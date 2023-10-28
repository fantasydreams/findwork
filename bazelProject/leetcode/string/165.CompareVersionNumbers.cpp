#include "165.CompareVersionNumbers.h"
#include <string>

void convertToVec(const std::string& str, std::vector<int>& nums) {
    if(str.empty()) {
        return;
    }

    size_t iPos = 0;
    while(iPos < str.size()) {
        size_t iNext = str.find(".", iPos);
        if(iNext != std::string::npos) {
            nums.push_back(stoi(str.substr(iPos, iNext - iPos)));
            iPos = iNext + 1;
        }else {
            nums.push_back(stoi(str.substr(iPos, str.size() - iPos)));
            iPos = str.size();
        }
    }
}

int compareVersion(string version1, string version2) {
    std::vector<int> num1, num2;
    convertToVec(version1, num1);
    convertToVec(version2, num2);
    int i = 0;
    while(i < num1.size() && i < num2.size()) {
        if(num1[i] == num2[i]) {
        }else if(num1[i] < num2[i]){
            return -1;
        }else {
            return 1;
        }
        ++i;
    }

    while(i < num1.size()) {
        if(num1[i]) {
            return 1;
        }
        ++i;
    }
    
    while(i < num2.size()) {
        if(num2[i]) {
            return -1;
        }
        ++i;
    }

    return 0;
}


int compareVersion1(string version1, string version2) {
    int iPos1 = 0, iPos2 = 0;
    while(iPos1 < version1.size() && iPos2 < version2.size()) {
        int iNext1 = version1.find(".", iPos1);
        int iNext2 = version2.find(".", iPos2);

        int num1 = 0;
        if(iNext1 == std::string::npos) {
            num1 = stoi(version1.substr(iPos1, version1.size() - iPos1));
            iPos1 = version1.size();
        }else {
            num1 = stoi(version1.substr(iPos1, iNext1 - iPos1));
            iPos1 = iNext1 + 1;
        }

        int num2 = 0;
        if(iNext2 == std::string::npos) {
            num2 = stoi(version2.substr(iPos2, version2.size() - iPos2));
            iPos2 = version2.size();
        }else {
            num2 = stoi(version2.substr(iPos2, iNext2 - iPos2));
            iPos2 = iNext2 + 1;
        }
         
        if(num1 < num2) {
            return -1;
        }else if(num1 > num2) {
            return 1;
        }
    }

    // if(iPos1 == version1.size() && iPos2 == version2.size()) {
    //     return 0;
    // }

    while(iPos1 < version1.size()) {
        int iNext1 = version1.find(".", iPos1);
        int num1 = 0;
        if(iNext1 == std::string::npos) {
            num1 = stoi(version1.substr(iPos1, version1.size() - iPos1));
            iPos1 = version1.size();
        }else {
            num1 = stoi(version1.substr(iPos1, iNext1 - iPos1));
            iPos1 = iNext1 + 1;
        }

        if(num1) {
            return 1;
        }
    }


    while(iPos2 < version2.size()) {
        int iNext2 = version2.find(".", iPos2);
        int num2 = 0;
        if(iNext2 == std::string::npos) {
            num2 = stoi(version2.substr(iPos2, version2.size() - iPos2));
            iPos2 = version2.size();
        }else {
            num2 = stoi(version2.substr(iPos2, iNext2 - iPos2));
            iPos2 = iNext2 + 1;
        }

        if(num2) {
            return -1;
        }
    }


    return 0;
}