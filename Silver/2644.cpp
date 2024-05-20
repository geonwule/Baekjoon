// 촌수계산

#include <iostream>

using namespace std;

#define Max 101


#include <queue>

struct Chon
{
    int cur, cnt;
};

int arr[Max][Max] = {0, };
bool visit[Max] = {false, };

int main()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    queue<Chon> q;
    q.push({a, 0});
    Chon res = {0, 0};

    visit[a] = true;
    while (!q.empty())
    {
        Chon &cur = q.front();
        q.pop();

        if (cur.cur == b)
        {
            res.cur = b;
            res.cnt = cur.cnt;
            break ;
        }

        for (int i = 1; i <= n; i++)
        {
            if (cur.cur != i && arr[cur.cur][i] && !visit[i])
            {
                visit[i] = true;
                q.push({i, cur.cnt + 1});
            }
        }
    }

    if (res.cur == 0)
        cout << -1;
    else
        cout << res.cnt;
    return 0;
}