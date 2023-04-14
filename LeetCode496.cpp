#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/* 下一个更大元素1 */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        if (nums1.size() == 0)
            return res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[i] > nums2[st.top()])
            {
                while (!st.empty() && nums2[i] > nums2[st.top()])
                {
                    if (mp.count(nums2[st.top()]) > 0)
                    {
                        res[mp[nums2[st.top()]]] = nums2[i];
                    }
                    st.pop();
                }
            }
            st.push(i);
        }
        return res;
    }
};