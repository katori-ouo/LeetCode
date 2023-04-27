#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s2 >> s1;
    int len1 = s1.size(), len2 = s2.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < len1; i++)
    {
        mp[s1[i]]++;
    }
    for (int i = 0; i < len2; i++)
    {
        if (mp[s2[i]] == 0)
        {
            cout << s2[i] << '\n';
            return 0;
        }
        mp[s2[i]]--;
    }
    return 0;
}