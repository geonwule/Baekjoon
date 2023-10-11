#include<iostream>
#include <queue>
#include <cmath>

struct comp
{
    bool    operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::priority_queue< int, std::vector<int>, comp> pq;

    while (n--)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 0)
        {
            if (pq.empty())
                std::cout << "0\n";
            else
            {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(cmd);
    }
}