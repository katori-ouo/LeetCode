#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<vector<char>> graph(n, vector<char>(m, '0'));
    char c;
    int x, y;
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == 'S')
            {
                x = i;
                y = j;
            }
            graph[i][j] = c;
        }
    }
    string route;
    cin >> route;
    int len = route.size();
    for (int i = 0; i < len; i++)
    {
        char way = route[i];
        if (way == 'W')
        {
            if (x >= 1 && graph[x - 1][y] != '#')
            {
                x--;
                if (graph[x][y] == 'O')
                {
                    score += p;
                    graph[x][y] = '+';
                }
                else if (graph[x][y] == 'X')
                {
                    score -= q;
                    graph[x][y] = '+';
                }
            }
        }
        else if (way == 'A')
        {
            if (y >= 1 && graph[x][y - 1] != '#')
            {
                y--;
                if (graph[x][y] == 'O')
                {
                    score += p;
                    graph[x][y] = '+';
                }
                else if (graph[x][y] == 'X')
                {
                    score -= q;
                    graph[x][y] = '+';
                }
            }
        }
        else if (way == 'S')
        {
            if (x <= n - 2 && graph[x + 1][y] != '#')
            {
                x++;
                if (graph[x][y] == 'O')
                {
                    score += p;
                    graph[x][y] = '+';
                }
                else if (graph[x][y] == 'X')
                {
                    score -= q;
                    graph[x][y] = '+';
                }
            }
        }
        else if (way == 'D')
        {
            if (y <= m - 2 && graph[x][y + 1] != '#')
            {
                y++;
                if (graph[x][y] == 'O')
                {
                    score += p;
                    graph[x][y] = '+';
                }
                else if (graph[x][y] == 'X')
                {
                    score -= q;
                    graph[x][y] = '+';
                }
            }
        }
    }
    cout << score << '\n';
}