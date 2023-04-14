#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/* 判断6位数是否各位均不相同 */
bool isValid(int num)
{
    unordered_map<int, int> cnt;
    bool res1 = true, res2 = false;
    vector<int> idx(6, 0);
    int num1 = 0, num2 = 0, num3 = 0;
    int temp;
    for (int i = 0; i < 6; i++)
    {
        temp = num % 10;
        idx[5 - i] = temp;
        cnt[temp]++;
        if (cnt[temp] > 1)
            res1 = false;
        num /= 10;
    }
    num1 = idx[0] * 10 + idx[1];
    num2 = idx[2] * 10 + idx[3];
    num3 = idx[4] * 10 + idx[5];
    if (num1 + num2 == num3)
        res2 = true;
    return res1 && res2;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    for (int i = m; i <= n; i++)
    {
        if (isValid(i))
            cnt++;
    }
    cout << cnt << '\n';
}