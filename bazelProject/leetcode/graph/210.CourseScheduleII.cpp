#include "210.CourseScheduleII.h"
#include <map>
#include <queue>

//这是一版粗略的bfs
std::vector<int> findOrder(int numCourses, std::vector<std::vector<int> >& prerequisites)
{
    std::vector<int> res;
    if(numCourses <= 0) {
        return res;
    }
    
    if(numCourses == 1)
    {
        res.push_back(0);
        return res;
    }

    std::map<int , std::vector<int> > c2Pre;
    std::vector<bool> pass(numCourses, false);
    std::vector<int> indegree(numCourses, 0);
    for(const auto & pair : prerequisites) 
    {
        c2Pre[pair[1]].push_back(pair[0]);
        indegree[pair[0]]++;
    }

    for(int j = 0; j < numCourses; ++j)
    {
        bool unpass = false;
        for(int i = 0; i < indegree.size(); ++i)
        {
            if(indegree[i] == 0 && pass[i] == false)
            {
                unpass = true;
                res.push_back(i);
                pass[i] = true;
                auto & next = c2Pre[i];
                for(auto & course : next) {
                    indegree[course]--;
                }
            }
        }

        if(unpass  == false){
            break;
        }
    }

    for(int i =0 ;i < numCourses; ++i)
    {
        if(pass[i] == false){
            return std::vector<int>();
        }
    }
    
    return res;
}


//优雅的bfs
std::vector<int> findOrderBfs(int numCourses, std::vector<std::vector<int> >& prerequisites)
{
    std::vector<std::vector<int> > adj(numCourses);
    std::vector<int> indegree(numCourses, 0);
    for(auto & pair : prerequisites)
    {
        adj[pair[1]].push_back(pair[0]);
        indegree[pair[0]]++;
    }

    std::queue<int> que;
    for(int i = 0; i < numCourses; ++i)
    {
        if(indegree[i] == 0){
            que.push(i);
        }
    }

    std::vector<int> res;
    while(que.size())
    {
        res.push_back(que.front());
        for(auto & course : adj[que.front()])
        {
            if(--indegree[course] == 0){
                que.push(course);
            }
        }
        que.pop();
    }

    return res.size() == numCourses ? res : std::vector<int>();
}