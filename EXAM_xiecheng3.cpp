#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, l, r;
string sWeight;
vector<int> weights;
vector<vector<int>> connections;
vector<bool> isUsed;
int cnt;

int stonum(string& path)
{
	int num = 0;
	int len = path.size();
	for (int i = len - 1; i >= 0; i--)
	{
		num += (path[i] - '0') << (len - 1 - i);
	}
	return num;
}

void dfs(int x, string& path)
{
	char c = weights[x] + '0';
	path.push_back(c);
	int num = stonum(path);
	if (path.size() > 1 && num >= l && num <= r)
		cnt++;
	isUsed[x] = true;
	for (int node : connections[x])
	{
		if (!isUsed[node])
		{
			dfs(node, path);
		}
	}
	isUsed[x] = false;
	path.pop_back();
}

int main()
{
	cnt = 0;
	cin >> n >> l >> r;
	cin >> sWeight;
	weights.resize(n + 1);
	connections.resize(n + 1, vector<int>());
	isUsed.resize(n + 1, false);
	for (int i = 0; i < sWeight.size(); i++)
	{
		weights[i + 1] = sWeight[i] - '0';
	}
	int x, y;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		connections[x].emplace_back(y);
		connections[y].emplace_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		string path = "";
		dfs(i, path);
	}
	cout << cnt << '\n';
}