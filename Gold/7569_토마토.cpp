#include <iostream>
#include <queue>

int m, n, h;
int arr[100][100][100];
bool visited[100][100][100] = {false, };

int ret = -1;

struct tt
{
    int x, y, z, day;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void    bfs(void)
{
    std::queue<tt> q;
    tt temp;
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (arr[z][y][x] == 1)
                {
                    temp.x = x;
                    temp.y = y;
                    temp.z = z;
                    temp.day = 0;
                    q.push(temp);
                }
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int day = q.front().day;
        q.pop();
        if (visited[z][y][x])
            continue;
        visited[z][y][x] = true;
        if (day > ret || ret == -1)
            ret = day;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 \
                || nx >= m || ny >=n || nz >= h)
                continue;
            if (arr[nz][ny][nx] == 0 && !visited[nz][ny][nx])
            {
                arr[nz][ny][nx] = 1;
                temp.x = nx;
                temp.y = ny;
                temp.z = nz;
                temp.day = day + 1;
                q.push(temp);
            }
        }
    }
}

int main()
{
    std::cin >> m >> n >> h;
    bool already = true;
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                std::cin >> arr[z][y][x];
                if (arr[z][y][x] == 0)
                    already = false;
            }
        }
    }
    if (already)
    {
        std::cout <<"0";
        return (0);
    }
    bfs();
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (arr[z][y][x] == 0)
                {
                    std::cout << "-1";
                    return (0);
                }
            }
        }
    }
    std::cout << ret;
}
/* 입력 확인
std::cout <<"\n";
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                std::cout << arr[z][y][x];
                std::cout << " ";
            }
            std::cout <<"\n";
        }
        std::cout <<"\n\n";
    }
    */