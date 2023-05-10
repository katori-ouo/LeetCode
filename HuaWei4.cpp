#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void myPush(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
    }
    // n1 = n2
    else if (val == st.top())
    {
        st.pop();
        myPush(st, 2 * val);
    }
    else if (val < st.top())
    {
        st.push(val);
    }
    else
    {
        int sum = val;
        stack<int> temp;
        while (!st.empty() && sum > 0)
        {
            sum -= st.top();
            temp.push(st.top());
            st.pop();
        }
        if (sum == 0)
        {
            myPush(st, 2 * val);
        }
        else
        {
            while (!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
            st.push(val);
        }
    }
}

int main()
{
    stack<int> st;
    int val;
    vector<int> res;
    while (cin >> val)
    {
        myPush(st, val);
    }
    while (!st.empty())
    {
        val = st.top();
        st.pop();
        res.emplace_back(val);
    }
    int len = res.size();
    for (int i = 0; i < len - 1; i++)
    {
        cout << res[i] << ' ';
    }
    cout << res[len - 1] << endl;
    return 0;
}