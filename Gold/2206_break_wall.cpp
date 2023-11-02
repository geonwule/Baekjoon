#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Route
{
    int x, y, cnt;
    bool brick;

    Route(int _x, int _y, int _cnt, bool _brick) : x(_x), y(_y), cnt(_cnt), brick(_brick) {}
};

int res = -1, _map[1001][1001], n, m;
bool visited[1001][1001];
bool break_visited[1001][1001];
queue<Route> qroute;

void output()
{
    qroute.push(Route(1, 1, 1, false)); // init location

    while (!qroute.empty())
    {
        Route tmp = qroute.front();
        qroute.pop();

        if (tmp.y == n && tmp.x == m) // achive goal, achive location not check visited
        {
            if (res == -1 || res > tmp.cnt)
                res = tmp.cnt;
            continue;
        }

        if (!tmp.brick) // not yet break
        {
            if (visited[tmp.y][tmp.x]) // double check
                continue;
            visited[tmp.y][tmp.x] = true;
        }
        else // break wall
        {
            if (break_visited[tmp.y][tmp.x] || visited[tmp.y][tmp.x]) // double check
                continue;
            break_visited[tmp.y][tmp.x] = true;
        }

        for (int i = 0; i < 4; i++) // detect all
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];

            if (nx < 1 || ny < 1 || nx > m || ny > n || visited[ny][nx])
                continue; // impossible route

            if (_map[ny][nx] == 1) // wall
            {
                if (!tmp.brick) // not yet
                    qroute.push(Route(nx, ny, tmp.cnt + 1, true));
                else // already break wall
                    continue;
            }
            else
                qroute.push(Route(nx, ny, tmp.cnt + 1, tmp.brick));
        }
    }
}

void input()
{
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        string line;
        cin >> line;
        for (int x = 1; x <= m; x++)
        {
            _map[y][x] = line[x - 1] - '0';
        }
    }
}

int main()
{
    input();
    output();
    cout << res;
}
