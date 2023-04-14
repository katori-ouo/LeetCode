#include <iostream>
#include <vector>
using namespace std;
/* 0-1背包问题 */
/**
 * @brief 打印二维数组
 *
 * @param nums 输入的二维数组
 */
void printVector(vector<vector<int>> &nums)
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

void BagProblem_2D()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // NOTE:二维dp数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    // NOTE:初始化第一列(可省去)
    for (int i = 0; i < weight.size(); i++)
    {
        dp[i][0] = 0;
    }
    // NOTE:初始化第一行
    for (int i = weight[0]; i < bagWeight + 1; i++)
    {
        dp[0][i] = value[0];
    }
    printVector(dp);
    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = 0; j < bagWeight + 1; j++)
        {
            // NOTE:放不下weight[i]
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
            {
                // NOTE:放或不放
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    printVector(dp);
}

void BagProblem_1D()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // NOTE:一维dp数组初始化
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++)
    {
        // NOTE:倒序遍历,防止覆盖
        for (int j = bagWeight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    for (int i = 0; i < bagWeight + 1; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main()
{
    // BagProblem_2D();
    BagProblem_1D();
}