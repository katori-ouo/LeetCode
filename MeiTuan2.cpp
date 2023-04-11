#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a, b, m, x;
	cin >> a >> b >> m >> x;
	//vector<int> nums;
	x = (a * x + b) % m;
	//nums.push_back(x);
	int begin = x;
	int ans = 1;
	while (true)
	{
		x = (a * x + b) % m;
		//nums.push_back(x);
		if (x == begin)
		{
			//ans = nums.size() - 1;
			break;
		}
		else ans++;
	}
	cout << ans << endl;
}