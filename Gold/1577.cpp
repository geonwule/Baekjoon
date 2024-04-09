#include <iostream>

using namespace std;

int n, m, k;

struct Pos
{
    int x, y;
};

struct Road
{
    Pos start, end;
    bool operator==(const Road &r)
    {
        if (start.x == r.start.x && start.y == r.start.y\
        && end.x == r.end.x && end.y == r.end.y)
            return true;
        if (start.x == r.end.x && start.y == r.end.y\
        && end.x == r.start.x && end.y == r.start.y)
            return true;
        return (false);
    }
};

struct Info
{
    Pos pos;
    int distance;
};

Road poor[50];
// int visited[100][100];

int dx[2] = {0, 1};
int dy[2] = {1, 0};
// #include <vector>
#include <queue>
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> poor[i].start.x >> poor[i].start.y >> poor[i].end.x >> poor[i].end.y;
    }

    int shortestDistance = n + m;
    size_t res = 0;
    queue<Info> q;
    Pos ipos = {0, 0};
    q.push({ipos, 0});
    // visited[0][0] = 1;

    // int cnt = 0;
    while (!q.empty())
    {
        // cout << ++cnt << endl;
        // cout << q.size() << endl;
        Info cur = q.front();
        Pos pos = cur.pos;
        int distance = cur.distance;
        q.pop();

        if (pos.x == n && pos.y == m)
        {
            if (distance <= shortestDistance)
                res++;
            continue;
        }

        for (int i = 0; i < 2; i++)
        {
            Pos npos = {pos.x + dx[i], pos.y + dy[i]};
            if (npos.x > n || npos.y > m)
                continue;
            Road road = {pos, npos};
            bool isPoor = false;
            for (int j = 0; j < k; j++)
            {
                if (road == poor[j])
                {
                    isPoor = true;
                    break;
                }
            }
            if (isPoor)
                continue;
            q.push({npos, distance + 1});
        }
    }

    cout << res;
}