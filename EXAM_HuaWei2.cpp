#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int left, right;
    cin >> left >> right;
    deque<int> pools;
    // queue<int> trash;
    stack<int> temp;
    vector<bool> used(right + 1, false);
    for (int i = left; i <= right; i++)
    {
        pools.push_back(i);
    }
    int n;
    cin >> n;
    int ope, id, num, re;
    for (int idx = 0; idx < n; idx++)
    {
        cin >> ope;
        if (ope == 1)
        {
            cin >> num;
            if (num > pools.size())
            {
                continue;
            }
            while (num > 0)
            {
                re = pools.front();
                pools.pop_front();
                // trash.push(re);
                used[re] = true;
                num--;
            }
        }
        else if (ope == 3)
        {
            cin >> id;
            if (used[id] == false || id > right || id < left)
                continue;
            used[id] = false;
            pools.push_back(id);
        }
        else if (ope == 2)
        {
            cin >> id;
            if (used[id] == true || id > right || id < left)
                continue;
            while (!pools.empty() && pools.front() != id)
            {
                re = pools.front();
                pools.pop_front();
                temp.push(re);
            }
            if (!pools.empty())
            {
                re = pools.front();
                pools.pop_front();
                // trash.push(re);
                used[re] = true;
            }
            while (!temp.empty())
            {
                re = temp.top();
                temp.pop();
                pools.push_front(re);
            }
        }
    }
    re = pools.front();
    cout << re << '\n';
}

// int main()
// {
//     int left, right;
//     cin >> left >> right;
//     queue<int> pools;
//     queue<int> trash;
//     vector<bool> used(right, false);
//     for (int i = left; i <= right; i++)
//     {
//         pools.push(i);
//     }
//     int n;
//     cin >> n;
//     int ope, num, id, temp;
//     for (int idx = 0; idx < n; idx++)
//     {
//         cin >> ope;
//         if (ope == 1)
//         {
//             cin >> num;
//             int cnt = 0;
//             while (cnt < num && !pools.empty())
//             {
//                 temp = pools.front();
//                 if (used[temp] == false)
//                 {
//                     trash.push(temp);
//                     pools.pop();
//                     used[temp] = true;
//                     cnt++;
//                 }
//                 else
//                 {
//                     pools.pop();
//                 }
//             }
//             while (used[pools.front()] == true)
//             {
//                 pools.pop();
//             }
//         }
//         else if (ope == 2)
//         {
//             cin >> id;
//             if (used[id] == false)
//             {
//                 used[id] = true;
//                 trash.push(id);
//             }
//             while (used[pools.front()] == true)
//             {
//                 pools.pop();
//             }
//         }
//         else if (ope == 3)
//         {
//             cin >> num;
//             int temp;
//             while (num > 0 && !trash.empty())
//             {
//                 temp = trash.front();
//                 trash.pop();
//                 pools.push(temp);
//                 while (used[pools.front()] == true)
//                 {
//                     pools.pop();
//                 }
//                 used[temp] = false;
//                 num--;
//             }
//         }
//     }
//     while (used[pools.front()] == true)
//     {
//         pools.pop();
//     }
//     cout << pools.front() << '\n';
// }