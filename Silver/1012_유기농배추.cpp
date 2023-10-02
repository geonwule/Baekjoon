// 벡터로 푼 문제 12%에서 틀림
// #include <iostream>
// #include <vector>
// #include <cmath>

// int t;

// void    dfs(std::vector<std::pair <int, int>>& arr, int x, int y)
// {
//     for (int i = 0; i < arr.size();)
//     {
//         if ((x == arr[i].first && abs(y - arr[i].second) == 1) \
//             || (y == arr[i].second && abs(x - arr[i].first) == 1))
//         {
//             int a = arr[i].first, b = arr[i].second;
//             arr.erase(arr.begin() + i);
//             dfs(arr, a, b);
//         }
//         else
//             i++;
//     }
// }

// int main()
// {
//     std::cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         int m, n, k;
//         std::cin >> m >> n >> k;
//         std::vector<std::pair <int, int>>    arr;
//         arr.clear();
//         for (int j = 0; j < k; j++)
//         {
//             int x, y;
//             std::cin >> x >> y;
//             arr.push_back(std::make_pair(x, y));
//         }
//         int r = 0;
//         while(!arr.empty())
//         {
//             r++;
//             int a = arr[0].first, b = arr[0].second;
//             arr.erase(arr.begin());
//             dfs(arr, a, b);
//         }
//         std::cout << r << "\n";
//     }
// }

#include <iostream>
#include <vector>
#include <cmath>

int t;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int arr[50][50], bool visited[50][50], int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 50 || ny >= 50 || nx < 0 || ny < 0)
            continue;
        if (arr[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(arr, visited, nx, ny);
        }
    }
}

int main()
{
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n, k;
        std::cin >> m >> n >> k;
        int arr[50][50] = {
            0,
        };
        bool visited[50][50] = {
            false,
        };
        for (int j = 0; j < k; j++)
        {
            int x, y;
            std::cin >> x >> y;
            arr[y][x] = 1;
        }
        int r = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (arr[y][x] && !visited[y][x])
                {
                    r++;
                    visited[y][x] = true;
                    dfs(arr, visited, x, y);
                }
            }
        }
        std::cout << r << "\n";
    }
}