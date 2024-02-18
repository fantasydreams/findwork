#include "207.CourseSchedule.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
    std::vector<int> vecDegress(numCourses);
    std::unordered_map<int, std::unordered_set<int> > mapPreToNext;
    for(const auto & oPair : prerequisites) {
        ++vecDegress[oPair[0]];
        mapPreToNext[oPair[1]].insert(oPair[0]);
    }

    std::queue<int> que;
    for(int i = 0; i < vecDegress.size(); ++i) {
        if(vecDegress[i] == 0) {
            que.push(i);
        }
    } 

    int iStudyCourseNum = 0;
    while(!que.empty()) {
        int iCousrseNum = que.front(); que.pop();
        ++iStudyCourseNum;
        auto pIter = mapPreToNext.find(iCousrseNum);
        if(pIter != mapPreToNext.end()) {
            std::vector<int> erase;
            for(const auto iNum : pIter->second) {
                if(vecDegress[iNum] > 0) {
                    --vecDegress[iNum];
                    if(vecDegress[iNum] == 0) {
                        que.push(iNum);
                        erase.push_back(iNum);
                    }
                }
            }

            for(const auto & iNum : erase) {
                pIter->second.erase(iNum);
            }
        }
    }

    return iStudyCourseNum == numCourses;
}


bool canFinish1(int numCourses, vector<vector<int> >& prerequisites) {
    std::vector<int> vecDegree(numCourses, 0);
    std::unordered_map<int, std::unordered_set<int> > setAfterCourses;
    for(int i = 0; i < prerequisites.size(); ++i) {
        ++vecDegree[prerequisites[i][0]];
        setAfterCourses[prerequisites[i][1]].insert(prerequisites[i][0]);
    }

    int iStudyCourseNum = 0;
    std::queue<int> que;
    for(int i = 0; i < vecDegree.size(); ++i) {
        if(vecDegree[i] == 0) {
            que.push(i);
        }
    }

    while(!que.empty()) {
        int iCousrseNum = que.front(); que.pop();
        ++iStudyCourseNum;
        for(const auto iAfter : setAfterCourses[iCousrseNum]) {
            if(vecDegree[iAfter] > 0 && --vecDegree[iAfter] == 0) {
                que.push(iAfter);
            }
        }
    }

    return iStudyCourseNum == numCourses;;
}