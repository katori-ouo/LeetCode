#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasCycle = false;
    vector<int> path;

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return graph;
    }

    void traversal(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath)
    {
        if (onPath[s])
            hasCycle = true;
        if (visited[s] || hasCycle)
            return;
        visited[s] = true;
        onPath[s] = true;
        for (int t : graph[s])
        {
            traversal(t, graph, visited, onPath);
        }
        onPath[s] = false;
        path.push_back(s);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
        {
            traversal(i, graph, visited, onPath);
        }
        if (hasCycle)
            return res;
        for (int i = 0; i < path.size(); i++)
        {
            res.push_back(path[path.size() - i - 1]);
        }
        return res;
    }
};