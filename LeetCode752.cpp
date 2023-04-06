#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string plusOne(string s, int idx)
    {
        if (s[idx] == '9')
            s[idx] = '0';
        else
            s[idx]++;
        return s;
    }

    string minusOne(string s, int idx)
    {
        if (s[idx] == '0')
            s[idx] = '9';
        else
            s[idx]--;
        return s;
    }

    int openLock(vector<string> &deadends, string target)
    {
        unordered_map<string, int> deads;
        for (string d : deadends)
            deads[d] = 1;
        unordered_map<string, int> visited;
        queue<string> que;
        int step = -1;
        que.push("0000");
        visited["0000"] = 1;
        while (!que.empty())
        {
            step++;
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                string cur = que.front();
                que.pop();
                if (cur == target)
                    return step;
                if (deads.count(cur))
                    continue;
                for (int j = 0; j < 4; j++)
                {
                    string up = plusOne(cur, j);
                    if (!visited.count(up))
                    {
                        que.push(up);
                        visited[up] = 1;
                    }
                    string down = minusOne(cur, j);
                    if (!visited.count(down))
                    {
                        que.push(down);
                        visited[down] = 1;
                    }
                }
            }
        }
        return -1;
    }
};