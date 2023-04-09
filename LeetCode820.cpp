#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Trie
{
private:
    vector<Trie *> children;
    int cnt;

public:
    Trie() : children(26), cnt(0) {}

    void addWord(string &word)
    {
        Trie *node = this;
        int idx = 0;
        int len = word.size();
        for (int i = len - 1; i >= 0; i--)
        {
            idx = word[i] - 'a';
            if (node->children[idx] == nullptr)
            {
                node->children[idx] = new Trie;
                node->cnt++;
            }
            node = node->children[idx];
        }
    }

    bool check(string &word)
    {
        Trie *node = this;
        int idx = 0, len = word.size();
        for (int i = len - 1; i >= 0; i--)
        {
            idx = word[i] - 'a';
            node = node->children[idx];
        }
        return node->cnt == 0;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie tree;
        int ans = 0;
        unordered_map<string, int> cnt;
        for (string word : words)
        {
            // reverse(word.begin(), word.end());
            tree.addWord(word);
        }
        for (string word : words)
        {
            if (tree.check(word))
                cnt[word] = word.size() + 1;
            else
                cnt[word] = 0;
        }
        for (auto kv : cnt)
            ans += kv.second;
        return ans;
    }
};