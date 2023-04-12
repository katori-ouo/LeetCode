#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long a, b, m, x, i;
	cin >> a >> b >> m >> x;
	vector<int> flags(100010, 0);
	for (i = 1; i < 1e8; i++)
	{
		x = (a * x + b) % m;
		if (flags[x])
			break;
		else
			flags[x] = i;
	}
	cout << i - flags[x] << '\n';
}