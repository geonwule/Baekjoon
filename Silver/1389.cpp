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

struct zz
{
    int idx, dist;
};

std::vector<std::queue<zz>> vq;

void bfs(int b, int dest, int &bacon, int dist)
{

    for (int i = 1; i <= m; i++)
    {
        if (!relation[b][i] || dest == i || visited[dest][i])
            continue;

        visited[dest][i] = true;
        bacon += dist;
    }
}

int main()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    int ret = -1;
    for (int dest = 1; dest <= m; dest++)
    {
        int bacon = 0;
        bfs(dest, dest, bacon, 1);
        if (ret == -1 || bacon < ret)
            ret = bacon;
    }

    std::cout << ret;
}