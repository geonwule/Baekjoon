#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <queue>
#include <deque>
#include <map>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[10000];
vector<string> ret;

void cmdD(std::pair<int, string> &t, queue<pair<int, string> > &q)
{
    int va = t.first;
    string cmd = t.second;

    va = va * 2 % 10000;
    cmd += 'D';
    if (va <= 9999 && !visited[va])
    {
        visited[va] = true;
        q.push(pair<int, string>(va, cmd));
    }
}

void cmdS(std::pair<int, string> &t, queue<pair<int, string> > &q)
{
    int va = t.first;
    string cmd = t.second;

    va = va - 1;
    if (va < 0)
        va = 9999;
    cmd += 'S';
    if (va <= 9999 && !visited[va])
    {
        visited[va] = true;
        q.push(pair<int, string>(va, cmd));
    }
}

void cmdL(std::pair<int, string> &t, queue<pair<int, string> > &q)
{
    int va = t.first;
    string cmd = t.second;

    va = (va % 1000) * 10 + (va / 1000);
    cmd += 'L';
    if (va <= 9999 && !visited[va])
    {
        visited[va] = true;
        q.push(pair<int, string>(va, cmd));
    }
}

void cmdR(std::pair<int, string> &t, queue<pair<int, string> > &q)
{
    int va = t.first;
    string cmd = t.second;

    va = (va % 10) * 1000 + (va / 10);
    cmd += 'R';
    if (va <= 9999 && !visited[va])
    {
        visited[va] = true;
        q.push(pair<int, string>(va, cmd));
    }
}


void    clearVisited()
{
    for (int i = 0; i < 10000; i++)
        visited[i] = false;
}

void bfs()
{
    clearVisited();
    int a, b;
    cin >> a >> b;
    queue<std::pair<int, string> > q;
    q.push(std::pair<int, string>(a, ""));
    visited[a] = true;
    while (!q.empty())
    {
        std::pair<int, string> tmp = q.front();
        q.pop();
        if (tmp.first == b) // escape
        {
            ret.push_back(tmp.second);
            return;
        }
        // if (visited[tmp.first])
        //     continue;
        // visited[tmp.first] = true;
        cmdD(tmp, q);
        cmdS(tmp, q);
        cmdL(tmp, q);
        cmdR(tmp, q);
    }
}

int main()
{
    std::ios_base ::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        bfs();
    for (int i = 0; i < t; i++)
        cout << ret[i] << "\n";
    return 0;
}
