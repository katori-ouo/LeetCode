#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/* 每日温度 */
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
        int len = temperatures.size();
        vector<int> res(len, 0);
        if (len == 1)
            return res;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len; i++)
        {
            if (temperatures[i] > temperatures[st.top()])
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    int idx = st.top();
                    st.pop();
                    res[idx] = i - idx;
                }
            }
            st.push(i);
        }
        return res;
    }
};