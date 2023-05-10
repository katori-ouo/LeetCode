#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    class myQueue
    {
    public:
        deque<int> que;
        void pop(int val)
        {
            if (!que.empty() && val == que.front())
            {
                que.pop_front();
            }
        }
        void push(int val)
        {
            while (!que.empty() && val > que.back())
            {
                que.pop_back();
            }
            que.push_back(val);
        }
        int front()
        {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        myQueue que;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            ans.push_back(que.front());
        }
        return ans;
    }
};