#include "71.SimplifyPath.h"
#include <vector>

string simplifyPath(string path) {
    size_t dirStart = 0;
    size_t iPos;
    std::vector<std::string> vecDir;
    while(dirStart < path.size()) {
        iPos = path.find('/', dirStart);
        std::string sDir;
        if(iPos == std::string::npos) {
            sDir = path.substr(dirStart, path.size() - dirStart);
            dirStart = path.size();
        }else {
            sDir = path.substr(dirStart, iPos - dirStart);;
            dirStart = iPos + 1;
        }

        if(!sDir.empty()) {
            if(sDir == ".") {
            }else if(sDir == "..") {
                if(!vecDir.empty()) {
                    vecDir.pop_back();
                }
            }else {
                vecDir.emplace_back(sDir);
            }
        }
    }

    std::string ans = "/";
    for(int i = 0; i < vecDir.size(); ++i) {
        ans += vecDir[i];
        if(i != vecDir.size() - 1) {
            ans += "/";
        }
    }

    return ans;
}


string simplifyPath1(string path) {
        std::vector<std::string> vecDirPath;
        std::string tmpDir;
        for(int i = 0; i <= path.size(); ++i) {
            if(path[i] == '/' || i == path.size()) {
                if(tmpDir == ".") {
                }else if(tmpDir == "..") {
                    if(!vecDirPath.empty()) {
                        vecDirPath.pop_back();
                    }
                }else if(!tmpDir.empty()){
                    vecDirPath.push_back(tmpDir);
                }
                tmpDir.clear();
            }else {
                tmpDir += path[i];
            }
        }

        std::string ans = "/";
        for(int i = 0; i < vecDirPath.size(); ++i) {
            ans += vecDirPath[i];
            if(i != vecDirPath.size() - 1) {
                ans += "/";
            }
        }

        return ans;
    }