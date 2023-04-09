#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class State
{
public:
    int id;
    int disFromStart;
    State(int id, int dis) : id(id), disFromStart(dis) {}
    bool operator<(const State &rhs) const
    {
        return rhs.disFromStart < disFromStart;
    }
};

class Solution
{
public:
    vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph)
    {
        vector<int> disTo(graph.size(), INT32_MAX);
        disTo[start] = 0;
        priority_queue<State> que;
        que.push(State(start, disTo[start]));
        while (!que.empty())
        {
            State curState = que.top();
            que.pop();
            int curNodeID = curState.id;
            int curDisFromStart = curState.disFromStart;
            if (curDisFromStart > disTo[curNodeID])
                continue;
            for (auto neighbour : graph[curNodeID])
            {
                int nextNodeID = neighbour.first;
                int disToNextNode = neighbour.second + disTo[curNodeID];
                if (disTo[nextNodeID] > disToNextNode)
                {
                    disTo[nextNodeID] = disToNextNode;
                    que.push(State(nextNodeID, disToNextNode));
                }
            }
        }
        return disTo;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        int len = times.size();
        for (vector<int> time : times)
        {
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> disTo = dijkstra(k, graph);
        int ans = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (disTo[i] == INT32_MAX)
                return -1;
            ans = max(ans, disTo[i]);
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> times = {{2, 1, 1},
                                 {2, 3, 1},
                                 {3, 4, 1}};
    Solution solve;
    int res = solve.networkDelayTime(times, 4, 2);
    return 0;
}