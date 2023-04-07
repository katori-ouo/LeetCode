#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnts(26, 0);
        for (char c : tasks)
        {
            cnts[c - 'A']++;
        }
        int maxNum = 0, tot = 0;
        for (int i = 0; i < 26; i++)
            maxNum = max(maxNum, cnts[i]);
        for (int i = 0; i < 26; i++)
        {
            if (cnts[i] == maxNum)
                tot++;
        }
        int res = (maxNum - 1) * (n + 1) + tot;
        int len = tasks.size();
        return max(res, len);
    }
};