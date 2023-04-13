#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cloth
{
    int price; // 卖出该衣服和衬衫组合的价格
    int num;   // 该衣服的数量
    bool operator<(const cloth &rhs) const
    {
        return rhs.price > price;
    }
};

int main()
{
    int numTie, numPant, numHat, numShirt;
    int priceTS, pricePS, priceHS;
    cin >> numTie >> numPant >> numHat >> numShirt;
    cin >> priceTS >> pricePS >> priceHS;
    long long res = 0;
    cloth tie = {priceTS, numTie};
    cloth pant = {pricePS, numPant};
    cloth hat = {priceHS, numHat};
    priority_queue<cloth> que;
    que.push(tie);
    que.push(pant);
    que.push(hat);
    while (numShirt > 0 && !que.empty())
    {
        cloth node = que.top();
        que.pop();
        int num = min(node.num, numShirt);
        res += node.price * num;
        numShirt -= num;
    }
    cout << res << '\n';
}