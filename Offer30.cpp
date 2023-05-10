#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> st;
    stack<int> stMin;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        st.push(x);
        if (stMin.empty())
        {
            stMin.push(x);
        }
        else
        {
            if (stMin.top() > x)
                stMin.push(x);
            else
                stMin.push(stMin.top());
        }
    }

    void pop()
    {
        st.pop();
        stMin.pop();
    }

    int top()
    {
        return st.top();
    }

    int min()
    {
        return stMin.top();
    }
};