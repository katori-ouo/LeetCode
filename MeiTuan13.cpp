#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    /*记录每本书所在的地方,0表示借走,1-N表示书架上,-1表示不在任何地方*/
    vector<int> pos(m + 1, -1);
    vector<bool> locked(n + 1, false); // 书架的某一行是否上锁
    vector<int> res;                   // 操作4对应的结果
    int op, x, y;
    for (int idx = 0; idx < q; idx++)
    {
        cin >> op;
        // 操作1
        if (op == 1)
        {
            cin >> x >> y;
            if (x < 1 || x > m)
                continue;
            if (pos[x] == 0)
                continue;
            if (pos[x] >= 1 && pos[x] <= n && locked[pos[x]])
                continue;
            if (y < 1 || y > n)
                continue;
            if (locked[y])
                continue;
            pos[x] = y;
        }
        // 操作2
        else if (op == 2)
        {
            cin >> y;
            if (y < 1 || y > n)
                continue;
            locked[y] = true;
        }
        // 操作3
        else if (op == 3)
        {
            cin >> y;
            if (y < 1 || y > n)
                continue;
            locked[y] = false;
        }
        // 操作4
        else if (op == 4)
        {
            cin >> x;
            if (x < 1 || x > m)
                res.emplace_back(-1);
            else
            {
                y = pos[x];
                if (y == -1 || y == 0 || locked[y])
                    res.emplace_back(-1);
                else
                    res.emplace_back(y);
            }
        }
        // 操作5
        else if (op == 5)
        {
            cin >> x;
            if (x < 1 || x > m)
                continue;
            if (pos[x] != 0)
                continue;
            else
                pos[x] = -1;
        }
    }
    int len = res.size();
    for (int i = 0; i < len; i++)
    {
        cout << res[i] << '\n';
    }
}