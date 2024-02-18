#include <vector>

using namespace std;

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int> >& prerequisites);
std::vector<int> findOrderBfs(int numCourses, std::vector<std::vector<int> >& prerequisites);
vector<int> findOrderBfs1(int numCourses, vector<vector<int>>& prerequisites);
vector<int> findOrderBfs2(int numCourses, vector<vector<int> >& prerequisites);
vector<int> findOrderBfs3(int numCourses, vector<vector<int> >& prerequisites);