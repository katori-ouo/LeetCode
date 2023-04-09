#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double probability(vector<double> &prob, int target)
    {
        int n = prob.size();
        int ans = 0;
        if (target > n)
            return ans;
        if (target == 0)
        {
            ans = 1 - prob[0];
            for (int i = 1; i < n; i++)
            {
                ans *= 1 - prob[i];
            }
            return ans;
        }
        vector<vector<double>> dp(n, vector<double>(target + 1, 0));
        dp[0][0] = 1 - prob[0];
        dp[0][1] = prob[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < target + 1 && j <= i + 1; j++)
            {
                dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
            }
        }
        return dp[n - 1][target];
    }
};
int main()
{
    vector<double> prob = {0.4, 0.4};
    Solution solve;
    double ans = solve.probability(prob, 1);
    return 0;
}