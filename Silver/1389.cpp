#include <iostream>

int n, m; // n <= 100, m <= 5000
int relation[101][101];
bool visited[101][101];

// void dfs(int b, int dest, int &bacon, int dist)
// {
//     for (int i = 1; i <= m; i++)
//     {
//         if (!relation[b][i] || dest == i || visited[dest][i])
//             continue;

//         visited[dest][i] = true;
//         bacon += dist;
//         dfs(i, dest, bacon, dist + 1);
//     }
// }

#include <queue>

#include <algorithm>

struct zz
{
    int dest, comp, dist;
};

void set_rel()
{
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
}

int main()
{
    std::cin >> n >> m;
    set_rel();

    std::queue<zz> q;
    for (int i = 1; i <= n; i++)
        q.push({i, i, 1});

    std::vector<int> retArr(n + 1, 0);

    while (!q.empty())
    {
        int dest = q.front().dest;
        int comp = q.front().comp;
        int dist = q.front().dist;
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (relation[comp][i] && i != dest)
            {
                if (!visited[dest][i])
                {
                    visited[dest][i] = true;
                    retArr[dest] += dist;
                    q.push({dest, i, dist + 1});
                }
            }
        }
    }

    // std::sort(retArr.begin(), retArr.end());
    int ret = 1;
    for (int i = 2; i <= n; i++)
    {
        if (retArr[ret] > retArr[i])
            ret = i;
    }
    std::cout << ret;
}