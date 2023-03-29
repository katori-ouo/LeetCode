#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findLast(string s)
    {
        vector<int> hash(27, 0);
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        return hash;
    }

    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        vector<int> idx;
        idx.push_back(-1);
        int curEnd = 0;
        vector<int> hash = findLast(s);
        for (int i = 0; i < s.size(); i++)
        {
            curEnd = max(curEnd, hash[s[i] - 'a']);
            if (curEnd == s.size() - 1)
            {
                idx.push_back(curEnd);
                break;
            }
            if (i == curEnd)
                idx.push_back(curEnd);
        }
        for (int i = 1; i < idx.size(); i++)
        {
            res.push_back(idx[i] - idx[i - 1]);
        }
        return res;
    }
};