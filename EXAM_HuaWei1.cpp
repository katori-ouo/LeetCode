// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<unordered_map<int, int>> edges(n + 1);
//     vector<int> relies(n + 1, 0);
//     vector<bool> used(n + 1, false);
//     vector<int> rec;
//     int m, x;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> m;
//         for (int j = 0; j < m; j++)
//         {
//             cin >> x;
//             edges[i + 1][x]++;
//             relies[i + 1]++;
//         }
//     }
//     int cnt = 0, res = 0;
//     while (cnt < n)
//     {
//         int temp = cnt;
//         rec.clear();
//         for (int i = 1; i <= n; i++)
//         {
//             if (relies[i] == 0 && used[i] == false)
//             {
//                 rec.emplace_back(i);
//                 cnt++;
//                 used[i] = true;
//             }
//         }
//         if (temp == cnt)
//         {
//             cout << -1 << '\n';
//             return 0;
//         }
//         res++;
//         for (int i = 0; i < rec.size(); i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (edges[j].count(rec[i]))
//                 {
//                     edges[j][i]--;
//                     relies[j]--;
//                 }
//             }
//         }
//     }
//     cout << res << '\n';
//     return 0;
// }