#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void updateZero(string &seats, int &firstZero, int n)
{
    int i = 0;
    for (i = firstZero + 1; i < n; i++)
    {
        if (seats[i] == '0')
        {
            firstZero = i;
            break;
        }
    }
    if (i == n)
        firstZero = -1;
}

void updateOne(string &seats, int &firstOne, int n)
{
    int i = 0;
    for (i = firstOne + 1; i < n; i++)
    {
        if (seats[i] == '1')
        {
            firstOne = i;
            break;
        }
    }
    if (i == n)
        firstOne = -1;
}

vector<int> process(int n, string &seats, int m, string &sexs)
{
    vector<int> choices(m, 0);
    priority_queue<int, vector<int>, greater<int>> oneIdx, zeroIdx;
    for (int i = 0; i < n; i++)
    {
        if (seats[i] == '0')
            zeroIdx.push(i);
        else if (seats[i] == '1')
            oneIdx.push(i);
    }
    int idx = 0;
    char sex;
    for (int i = 0; i < m; i++)
    {
        sex = sexs[i];
        if (sex == 'M')
        {
            if (oneIdx.empty())
            {
                idx = zeroIdx.top();
                zeroIdx.pop();
                // seats[idx]++;
                oneIdx.push(idx);
                choices[i] = idx + 1;
            }
            else
            {
                idx = oneIdx.top();
                oneIdx.pop();
                // seats[idx]++;
                choices[i] = idx + 1;
            }
        }
        else if (sex == 'F')
        {
            if (zeroIdx.empty())
            {
                idx = oneIdx.top();
                oneIdx.pop();
                choices[i] = idx + 1;
            }
            else
            {
                idx = zeroIdx.top();
                zeroIdx.pop();
                oneIdx.push(idx);
                choices[i] = idx + 1;
            }
        }
    }
    return choices;
}

int main()
{
    int t, n, m;
    string seats, sexs;
    cin >> t;
    vector<vector<int>> ans(t);
    vector<int> choices;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> seats >> m >> sexs;
        choices = process(n, seats, m, sexs);
        ans[i] = choices;
    }
    for (int i = 0; i < t; i++)
    {
        int len = ans[i].size();
        for (int j = 0; j < len; j++)
        {
            cout << ans[i][j] << '\n';
        }
    }
}