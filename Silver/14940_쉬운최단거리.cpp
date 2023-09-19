#include <iostream>
#include <queue>
#include <vector>

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int arr[1001][1001], ret[1001][1001] = {
                         0,
};
bool visited[1001][1001] = {
    false,
};

void bfs(int x, int y)
{
    // std::queue<std::pair<int, int> > q;
    // q.push(std::make_pair(x, y));
    std::vector<std::pair<int, int> > v;
    v.push_back(std::make_pair(x, y));

    visited[y][x] = true;
    ret[y][x] = 0;

    while (!v.empty())
    {

        x = v.front().first;
        y = v.front().second;
        v.erase(v.begin());

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n)
            {
                if (!visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    if (arr[ny][nx] == 0)
                        ret[ny][nx] = 0;
                    else
                    {
                        ret[ny][nx] = ret[y][x] + 1;
                        v.push_back(std::make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main()
{
    std::cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                x = j;
                y = i;
            }
        }
    }
    bfs(x, y);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                ret[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << ret[i][j];
            if (j + 1 != m)
                std::cout << " ";
            else
                std::cout << "\n";
        }
    }
}