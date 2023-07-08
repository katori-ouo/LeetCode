class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if ((long long)mid * mid == num)
                return true;
            else if ((long long)mid * mid < num)
            {
                left = mid + 1;
            }
            else if ((long long)mid * mid > num)
            {
                right = mid - 1;
            }
        }
        return false;
    }
};