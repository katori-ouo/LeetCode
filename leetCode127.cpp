#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string &word)
    {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum;
            nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        addWord(word);
        int id1 = wordId[word];
        for (char &t : word)
        {
            char temp = t;
            t = '#';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            t = temp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (string &word : wordList)
        {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord))
            return 0;
        vector<int> dis(nodeNum, INT32_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;
        queue<int> que;
        que.push(beginId);
        while (!que.empty())
        {
            int id = que.front();
            que.pop();
            if (id == endId)
                return dis[endId] / 2 + 1;
            for (int &t : edge[id])
            {
                if (dis[t] == INT32_MAX)
                {
                    dis[t] = dis[id] + 1;
                    que.push(t);
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot"};
    string beginWord = "hit", endWord = "dot";
    Solution sol;
    sol.ladderLength(beginWord, endWord, wordList);
    return 0;
}