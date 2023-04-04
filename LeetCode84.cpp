#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
双指针优化的暴力法
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int len = heights.size();
        vector<int> leftMin(len, 0);
        vector<int> rightMin(len, 0);
        leftMin[0] = -1;
        for (int i = 1; i < len; i++)
        {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i])
                t = leftMin[t];
            leftMin[i] = t;
        }
        rightMin[len - 1] = len;
        for (int i = len - 2; i >= 0; i--)
        {
            int t = i + 1;
            while (t < len && heights[t] >= heights[i])
                t = rightMin[t];
            rightMin[i] = t;
        }
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            int sum = heights[i] * (rightMin[i] - leftMin[i] - 1);
            res = max(sum, res);
        }
        return res;
    }
};
*/
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] > heights[st.top()])
            {
                st.push(i);
            }
            else if (heights[i] == heights[st.top()])
            {
                st.pop();
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        res = max(res, w * heights[mid]);
                    }
                }
                st.push(i);
            }
        }
        return res;
    }
};