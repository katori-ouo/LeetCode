#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> stars(n);
    vector<int> coords(2, 0);
    vector<int> minX(2001, 2000), maxX(2001, 0);
    vector<int> minY(2001, 2000), maxY(2001, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coords[0];
        coords[0] += 1000;
        cin >> coords[1];
        coords[1] += 1000;
        minY[coords[0]] = min(coords[1], minY[coords[0]]);
        maxY[coords[0]] = max(coords[1], maxY[coords[0]]);
        minX[coords[1]] = min(coords[0], minX[coords[1]]);
        maxX[coords[1]] = max(coords[0], maxX[coords[1]]);
        stars[i] = coords;
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = stars[i][0], y = stars[i][1];
        if (x > minX[y] && x < maxX[y] && y > minY[x] && y < maxY[x])
            cnt++;
    }
    cout << cnt << endl;
}