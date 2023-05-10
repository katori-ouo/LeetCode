#include <stack>
using namespace std;

class CQueue
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        st1.push(value);
    }

    int deleteHead()
    {
        int val = -1;
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (!st2.empty())
        {
            val = st2.top();
            st2.pop();
        }
        return val;
    }
};