#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> preFix(1001, 0);
        for (int i = 0; i < trips.size(); i++)
        {
            preFix[trips[i][1]] += trips[i][0];
            preFix[trips[i][2]] -= trips[i][0];
        }
        vector<int> stations(1002, 0);
        for (int i = 0; i < preFix.size(); i++)
        {
            stations[i + 1] = stations[i] + preFix[i];
            if (stations[i + 1] > capacity)
                return false;
        }
        return true;
    }
};