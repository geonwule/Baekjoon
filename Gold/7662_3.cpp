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

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        while (!maxQ.empty())
            maxQ.pop();
        while (!minQ.empty())
            minQ.pop();
        cnt.clear();
        for (int j = 0; j < n; j++)
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
                while (!maxQ.empty() && cnt[maxQ.top()] == 0)
                    maxQ.pop();
                while (!minQ.empty() && cnt[minQ.top()] == 0)
                    minQ.pop();
            }
            else // input
            {
                maxQ.push(value);
                minQ.push(value);
                cnt[value]++;
            }
        }
        while (!maxQ.empty() && cnt[maxQ.top()] == 0)
            maxQ.pop();
        while (!minQ.empty() && cnt[minQ.top()] == 0)
            minQ.pop();
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
    for (int i = 0; i < ret.size(); i++)
    {
        if (ret[i].empty)
            std::cout << "EMPTY\n";
        else
            std::cout << ret[i].max << " " << ret[i].min << "\n";
    }
}