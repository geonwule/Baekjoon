#include <iostream>
#include <queue>

int n, m, arr[500][500];
bool visited[500][500] = {
    false,
};
int ret = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct tt
{
    int x, y, sum, cnt;
};

void bfs(void)
{
    std::queue<tt> q;
    tt temp;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            temp.x = x;
            temp.y = y;
            temp.cnt = 1;
            temp.sum = arr[y][x];
            q.push(temp);
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int sum = q.front().sum;
        q.pop();
        // if (visited[y][x])
        //     continue;
        // visited[y][x] = true;
        if (cnt == 4)
        {
            if (sum > ret)
                ret = sum;
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) // || visited[ny][nx])
                continue;
            temp.x = nx;
            temp.y = ny;
            temp.cnt = cnt + 1;
            temp.sum = sum + arr[ny][nx];
            q.push(temp);
        }
    }
}

void dfs(int x, int y, int cnt, int sum)
{
    if (cnt == 4)
    {
        if (sum > ret)
            ret = sum;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        if (cnt == 3 && visited[ny][nx])
        {
            for (int j = 0; j < 4; j++)
            {
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                if (nnx < 0 || nny < 0 || nnx >= m || nny >= n)
                    continue;
                if (visited[nny][nnx] || arr[nny][nnx] == 0)
                    continue;
                dfs(nnx, nny, cnt + 1, sum + arr[nny][nnx]);
                visited[nny][nnx] = false;
            }
        }
        if (visited[ny][nx] || arr[ny][nx] == 0)
            continue;
        dfs(nx, ny, cnt + 1, sum + arr[ny][nx]);
        visited[ny][nx] = false;
    }
}

int main()
{
    std::cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            std::cin >> arr[y][x];
        }
    }

    // bfs();
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            dfs(x, y, 1, arr[y][x]);
            visited[y][x] = false;
        }
    }

    std::cout << ret;
}