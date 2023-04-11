#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

static bool cmp(const double &a, const double &b)
{
    return a > b;
}

int main()
{
    int n, k, kind;
    double price;
    double sumB = 0, minB;
    double ans = 0;
    vector<double> A;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> price;
        cin >> kind;
        ans += price;
        if (kind == 1)
        {
            A.push_back(price);
        }
        else if (kind == 2)
        {
            if (sumB == 0)
                minB = price;
            else
                minB = min(minB, price);
            sumB += price;
        }
    }
    sort(A.begin(), A.end(), cmp);
    int numA = A.size();
    if (k <= numA)
    {
        for (int i = 0; i < k - 1; i++)
        {
            ans -= A[i] / 2;
        }
        ans -= (min(A[numA - 1], minB)) / 2;
    }
    else
    {
        for (int i = 0; i < numA; i++)
        {
            ans -= A[i] / 2;
        }
    }
    string s = to_string(ans);
    int idx = 0;
    for (; idx < s.size(); idx++)
    {
        if (s[idx] == '.')
            break;
    }
    s.resize(idx + 3);
    cout << s << endl;
}