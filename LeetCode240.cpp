#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int x = m, y = 0;
        while (x >= 0 && y <= n)
        {
            if (matrix[x][y] > target)
                x--;
            else if (matrix[x][y] < target)
                y++;
            else
                return true;
        }
        return false;
    }
};