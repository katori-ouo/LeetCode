#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/* 接雨水 */
/*
双指针优化的暴力解法
按列求解
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        if (len <= 2)
            return 0;
        vector<int> leftMax(len, 0);
        vector<int> rightMax(len, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < len; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int sum = 0;
        for (int i = 1; i < len - 1; i++)
        {
            int cnt = min(leftMax[i], rightMax[i]) - height[i];
            if (cnt > 0)
                sum += cnt;
        }
        return sum;
    }
};
*/
/*
单调栈法
按行求解
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        if (len <= 2)
            return 0;
        int sum = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len; i++)
        {
            if (height[i] < height[st.top()])
                st.push(i);
            else if (height[i] == height[st.top()])
            {
                st.pop();
                st.push(i);
            }
            else
            {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};