#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                return nullptr;
            node = node->children[idx];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false)
    {
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this->searchPrefix(prefix);
        return node != nullptr;
    }
};