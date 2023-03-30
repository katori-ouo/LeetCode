#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<vector<int>> nums)
{
    int m = nums.size();
    int n = nums[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

void Bag_Test2()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 二维dp数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    // 初始化第一列
    for (int i = 0; i < weight.size(); i++)
    {
        dp[i][0] = 0;
    }
    // 初始化第一行
    for (int i = 0; i < bagWeight + 1; i++)
    {
        if (i >= weight[0])
            dp[0][i] = value[0];
    }
    printVector(dp);

    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = 0; j < bagWeight + 1; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    printVector(dp);
}

void Bag_Test1()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    {
        for (j = bagWeight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}

int main()
{
    Bag_Test2();
}