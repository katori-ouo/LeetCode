#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> cnt;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                cnt.push(')');
            else if (s[i] == '[')
                cnt.push(']');
            else if (s[i] == '{')
                cnt.push('}');
            else if (cnt.empty() || s[i] != cnt.top())
                return false;
            else
                cnt.pop();
        }
        return cnt.empty();
    }
};