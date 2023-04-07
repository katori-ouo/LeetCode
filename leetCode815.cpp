#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int routeNum = routes.size();
        vector<bool> canUse(routeNum, true);
        unordered_map<int, int> visited;
        unordered_map<int, vector<int>> mp; // 每个站台对应的公交线路
        int numBuses = 0;
        for (int i = 0; i < routeNum; i++)
        {
            int len = routes[i].size();
            for (int j = 0; j < len; j++)
            {
                mp[routes[i][j]].push_back(i);
            }
        }
        queue<int> que;
        que.push(source);
        visited[source] = 1;
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                int station = que.front();
                que.pop();
                if (station == target)
                    return numBuses;
                for (int routeId : mp[station])
                {
                    if (canUse[routeId])
                    {
                        vector<int> route = routes[routeId];
                        for (int j = 0; j < route.size(); j++)
                        {
                            if (!visited.count(route[j]))
                            {
                                que.push(route[j]);
                                visited[route[j]] = 1;
                            }
                        }
                        canUse[routeId] = false;
                    }
                }
            }
            numBuses++;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> routes = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    int source = 15, target = 12;
    Solution res;
    int ans = res.numBusesToDestination(routes, source, target);
    return 0;
}