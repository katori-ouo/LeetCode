#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct valNode
{
    int x;
    int h;
};

static bool cmp(const valNode &a, const valNode &b)
{
    if (a.x == b.x)
        return a.h < b.h;
    return a.x < b.x;
}

/* 最长递增子序列 */
int maxLength(vector<int> &nums, int n)
{
    if (n <= 1)
        return n;
    vector<int> temp(n);
    temp[0] = nums[0];
    int end = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp[end])
        {
            end++;
            temp[end] = nums[i];
        }
        else
        {
            int left = 0, right = end;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (temp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            temp[left] = nums[i];
        }
    }
    end++;
    return end;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vals(n, vector<int>(2, 0));
    vector<valNode> nodes;
    int x, h;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> h;
        nodes.push_back({x, h});
    }
    sort(nodes.begin(), nodes.end(), cmp);
    vector<int> hs(n, 0);
    for (int i = 0; i < n; i++)
    {
        hs[i] = nodes[i].h;
    }
    // vector<int> dp(n, 1);
    // int res = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (hs[j] < hs[i])
    //             dp[i] = max(dp[j] + 1, dp[i]);
    //     }
    //     res = max(res, dp[i]);
    // }
    cout << maxLength(hs, n) << '\n';
}