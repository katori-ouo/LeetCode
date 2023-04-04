#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
暴力搜索,时间复杂度O(n^2),超时
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        for (int i = 0; i < temperatures.size(); i++)
        {
            int res = 0;
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    res = j - i;
                    break;
                }
            }
            temperatures[i] = res;
        }
        return temperatures;
    }
};
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};