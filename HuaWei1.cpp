#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int len = s.size();
	int numWord = 1, numIdx = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
			numWord++;
	}
	numIdx = len - numWord + 1;
	double res = (double)numIdx / (double)numWord;
	printf("%.2f\n", res);
}