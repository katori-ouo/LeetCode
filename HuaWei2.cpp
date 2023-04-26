#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    unordered_map<char, char> mp;
    mp['a'] = 'A';
    mp['e'] = 'E';
    mp['i'] = 'I';
    mp['o'] = 'O';
    mp['u'] = 'U';
    mp['A'] = 'A';
    mp['E'] = 'E';
    mp['I'] = 'I';
    mp['O'] = 'O';
    mp['U'] = 'U';
    int len = s.size();
    char c;
    for (int i = 0; i < len; i++)
    {
        c = s[i];
        if (c == ' ')
            continue;
        else if (mp.count(c))
        {
            s[i] = mp[c];
        }
        else
        {
            s[i] = tolower(c);
        }
    }
    cout << s << '\n';
}