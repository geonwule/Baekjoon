#include <iostream>

int arr[1000][1000];
bool visited[1000][1000] = {
    false,
};
int m, n;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#include <queue>

int rday = 0;

struct qq
{
    int x, y, day;
};

std::queue<qq> q;

void bfs(void)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (arr[y][x] == 1 && !visited[y][x])
            {
                qq t1;
                t1.x = x;
                t1.y = y;
                t1.day = 0;
                q.push(t1);
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int day = q.front().day;
        q.pop();
        if (visited[y][x])
            continue;
        if (rday < day)
            rday = day;
        visited[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (arr[ny][nx] == 0)
            {
                arr[ny][nx] = 1;
                qq t2;
                t2.x = nx;
                t2.y = ny;
                t2.day = day + 1;
                q.push(t2);
            }
        }
    }
}

int main()
{
    std::cin >> m >> n;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            std::cin >> arr[y][x];
        }
    }
    bfs();

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (arr[y][x] == 0)
            {
                std::cout << "-1";
                return (0);
            }
        }
    }
    std::cout << rday;
    return (0);
}