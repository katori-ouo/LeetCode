#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                ten++;
                if (five >= 1)
                    five--;
                else
                    return false;
            }
            else if (bills[i] == 20)
            {
                if (five >= 1)
                    five--;
                else
                    return false;
                if (ten >= 1)
                    ten--;
                else if (five >= 2)
                    five -= 2;
                else
                    return false;
            }
        }
        return true;
    }
};