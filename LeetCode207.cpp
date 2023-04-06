#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// class Solution
// {
// public:
//     bool hasCycle = false;

//     vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         vector<vector<int>> graph(numCourses, vector<int>());
//         for (int i = 0; i < prerequisites.size(); i++)
//         {
//             graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }
//         return graph;
//     }

//     void traversal(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath)
//     {
//         if (onPath[s])
//             hasCycle = true;
//         if (visited[s] || hasCycle)
//             return;
//         visited[s] = true;
//         onPath[s] = true;
//         for (int t : graph[s])
//         {
//             traversal(t, graph, visited, onPath);
//         }
//         onPath[s] = false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         vector<bool> visited(numCourses, false);
//         vector<bool> onPath(numCourses, false);
//         vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
//         for (int i = 0; i < numCourses; i++)
//         {
//             traversal(i, graph, visited, onPath);
//         }
//         return !hasCycle;
//     }
// };

class Solution
{
public:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return graph;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                que.push(i);
        }
        int count = 0;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            count++;
            for (int next : graph[cur])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                    que.push(next);
            }
        }
        return count == numCourses;
    }
};