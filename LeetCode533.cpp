#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findBlackPixel(vector<vector<char>> &picture, int N)
    {
        int m = picture.size();
        int n = picture[0].size();
        int cnt = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (picture[i][j] == 'B')
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (picture[i][j] == 'B' && row[i] == N && col[j] == N)
                {
                    bool valid = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (picture[k][j] == 'B' && picture[k] != picture[i])
                            valid = false;
                    }
                    if (valid)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> picture = {{'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'W', 'B', 'W', 'B', 'W'}};
    int N = 3;
    Solution solve;
    int res = solve.findBlackPixel(picture, N);
    return 0;
}