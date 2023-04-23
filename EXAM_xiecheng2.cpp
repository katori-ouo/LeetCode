#include <iostream>
#include <vector>
using namespace std;

int lcm(int a, int b)
{
    int temp;
    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

vector<int> process(int n)
{
    int maxlcm = INT32_MIN;
    int templcm = 0;
    vector<int> res(2, 0);
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i;
        if (j / i == 0)
            templcm = j;
        else
            templcm = j / lcm(j, i) * i;
        if (templcm > maxlcm)
        {
            res[0] = i;
            res[1] = j;
            maxlcm = templcm;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    int n;
    vector<vector<int>> res;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        res.push_back(process(n));
    }
    for (int i = 0; i < t; i++)
    {
        cout << res[i][0] << " " << res[i][1] << '\n';
    }
}