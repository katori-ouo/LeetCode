#include <iostream>
#include <vector>
#include <unordered_map>
// #include <queue>
using namespace std;
long long base = 1e9 + 7;
unordered_map<int, long long> mp;
long long traversal(int x)
{
    if (mp.count(x))
    {
        return mp[x];
    }
    else
    {
        long long temp = traversal(x - 1);
        long long res = 1 + (x + 1) * temp;
        mp[x] = res;
        return res;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    mp[0] = 1;
    int x;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt += traversal(x);
    }
    long long temp = 1e9 + 7;
    cnt = cnt % temp;
    cout << cnt << '\n';
}