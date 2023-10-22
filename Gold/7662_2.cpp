#include <iostream>
#include <queue>
#include <vector>
#include <map>

std::priority_queue<int, std::vector<int>, std::less<int>> maxQ;
std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;
std::map<int, int> cnt;
struct zz
{
    int max, min;
    bool empty;
};

std::vector<zz> ret;

void    clearQ(void)
{
    while (!maxQ.empty())
        maxQ.pop();
    while (!minQ.empty())
        minQ.pop();
}

void    checkQ(void)
{
    while(!maxQ.empty() && cnt[maxQ.top()] == 0)
        maxQ.pop();
    while(!minQ.empty() && cnt[minQ.top()] == 0)
        minQ.pop();
}

void    oneScene(void)
{
    int n;
    std::cin >> n;
    clearQ();
    cnt.clear();
    for (int i = 0; i < n; i++)
    {
        char cmd;
        int value;
        std::cin >> cmd >> value;
        if (cmd == 'D') // delete
        {
            if (maxQ.empty() || minQ.empty())
                continue;
            if (value == 1) // max delete
            {
                cnt[maxQ.top()]--;
                maxQ.pop();
            }
            else // min delete
            {
                cnt[minQ.top()]--;
                minQ.pop();
            }
            checkQ();
        }
        else // input
        {
            maxQ.push(value);
            minQ.push(value);
            cnt[value]++;
        }
    }
    checkQ();
    zz tmp = {0, 0, false};
    if (maxQ.empty() || minQ.empty())
        tmp.empty = true;
    else
    {
        tmp.max = maxQ.top();
        tmp.min = minQ.top();
    }
    ret.push_back(tmp);
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
        oneScene();
    for (int i = 0; i < ret.size(); i++)
    {
        if (ret[i].empty)
            std::cout << "EMPTY\n";
        else
            std::cout << ret[i].max << " " << ret[i].min << "\n";
    }
}