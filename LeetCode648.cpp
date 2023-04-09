#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;
    Trie *searchPrefix(string prefix, int len)
    {
        Trie *node = this;
        int idx = 0;
        for (int i = 0; i < len; i++)
        {
            idx = prefix[i] - 'a';
            if (node->children[idx] == nullptr)
                return nullptr;
            node = node->children[idx];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void addWord(string word)
    {
        Trie *node = this;
        int idx = 0;
        for (char c : word)
        {
            idx = c - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new Trie;
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word, int len)
    {
        Trie *node = this->searchPrefix(word, len);
        return node != nullptr && node->isEnd;
    }

    bool startWith(string word, int len)
    {
        Trie *node = this->searchPrefix(word, len);
        return node != nullptr;
    }
};

class Solution
{
public:
    vector<string> splitWords(string &sentence)
    {
        vector<string> words;
        int left = 0, right = 0;
        int len = sentence.size();
        string temp = "";
        for (; right < len; right++)
        {
            if (sentence[right] == ' ')
            {
                temp = sentence.substr(left, right - left);
                words.push_back(temp);
                left = right + 1;
            }
        }
        temp = sentence.substr(left, right - left + 1);
        words.push_back(temp);
        return words;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie tree;
        for (string root : dictionary)
        {
            tree.addWord(root);
        }
        vector<string> words = splitWords(sentence);
        int wordNum = words.size();
        for (int i = 0; i < wordNum; i++)
        {
            string word = words[i];
            int len = word.size();
            for (int j = 0; j < len; j++)
            {
                if (tree.startWith(word, j + 1))
                {
                    if (tree.search(word, j + 1))
                    {
                        words[i] = word.substr(0, j + 1);
                        break;
                    }
                }
                else
                    break;
            }
        }
        string ans = "";
        for (int i = 0; i < wordNum - 1; i++)
        {
            ans += words[i];
            ans += " ";
        }
        ans += words[wordNum - 1];
        return ans;
    }
};

int main()
{
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution solve;
    string ans = solve.replaceWords(dictionary, sentence);
    return 0;
}