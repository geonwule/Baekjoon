#include <iostream>
#include <map>

#define NO_WAY 0

int numPoint, numRoute, startPoint;
int map[20001][20001];


bool visited[20001];

void dfs(int curPoint, int value, int destPoint, int &shortRoute)
{
    if (curPoint == destPoint)
    {
        if (shortRoute == NO_WAY || shortRoute > value)
            shortRoute = value;
        return ;
    }

    visited[curPoint] = true;
    for (int i = 1; i <= numPoint; i++)
    {
        if (visited[i] == false && map[curPoint][i] != NO_WAY)
        {
            dfs(i, value + map[curPoint][i], destPoint, shortRoute);
            visited[i] = false;
        }
    }
}
struct Route
{
    int start, end, value;
    bool operator<(const Route &other)
    {
        return (this->value < other.value);
    }
};
#include <queue>
std::priority_queue<Route> pqRoute;

void output()
{
    for (int i = 1; i <= numPoint; i++)
    {
        if (startPoint == i)
        {
            std::cout << "0\n";
            continue;
        }
        int shortRoute = NO_WAY;
        dfs(startPoint, 0, i, shortRoute);
        // std::cout << shortRoute << '\n';
        visited[startPoint] = false;
        if (shortRoute == NO_WAY) // no way
        {
            std::cout << "INF\n";
            continue;
        }
        std::cout << shortRoute << '\n';
    }
}

void input()
{
    std::cin >> numPoint >> numRoute >> startPoint;
    for (int i = 0; i < numRoute; i++)
    {
        Route tmp;
        std::cin >> tmp.start >> tmp.end >> tmp.value;
        pqRoute.push(tmp);
        // if (map[start][end] == NO_WAY || map[start][end] > value) // init or more short way
        //     map[start][end] = value;
    }
}

int main()
{
    input();
    output();
}