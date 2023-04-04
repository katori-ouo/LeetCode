#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            sum[0][j] = matrix[0][j] == '0' ? 0 : 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum[i][j] = matrix[i][j] == '0' ? 0 : (sum[i - 1][j] + 1);
            }
        }
        int res = 0;
        for (int idx = 0; idx < m; idx++)
        {
            vector<int> vec = sum[idx];
            vec.insert(vec.begin(), 0);
            vec.push_back(0);
            stack<int> st;
            st.push(0);
            for (int i = 1; i < n + 2; i++)
            {
                if (vec[i] > vec[st.top()])
                {
                    st.push(i);
                }
                else if (vec[i] == vec[st.top()])
                {
                    st.pop();
                    st.push(i);
                }
                else
                {
                    while (!st.empty() && vec[i] < vec[st.top()])
                    {
                        int mid = st.top();
                        st.pop();
                        if (!st.empty())
                        {
                            int left = st.top();
                            int right = i;
                            int w = right - left - 1;
                            res = max(res, w * vec[mid]);
                        }
                    }
                    st.push(i);
                }
            }
        }
        return res;
    }
};
