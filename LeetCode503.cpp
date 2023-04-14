#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/* 下一个更大元素2 */
/*
复制一遍数组
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        vector<int> res(nums.size(), -1);
        if (nums.size() == 0)
            return res;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++)
        {
            while (!st.empty() && nums[i] > nums[st.top()])
            {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        res.resize(nums.size() / 2);
        return res;
    }
};
*/
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> res(len, -1);
        if (len == 1)
            return res;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len * 2; i++)
        {
            if (nums[i % len] > nums[st.top()])
            {
                while (!st.empty() && nums[i % len] > nums[st.top()])
                {
                    int idx = st.top();
                    st.pop();
                    res[idx] = nums[i % len];
                }
            }
            st.push(i % len);
        }
        return res;
    }
};
