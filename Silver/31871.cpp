#include <iostream>

using namespace std;

#define MAX 10000

#include <vector>
struct Info
{
    int cur, cnt_ride, sum_time;
    vector<bool> visit;
};

#include <queue>

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        if (arr[a][b] < dis)
            arr[a][b] = dis;
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         if (arr[i][j])
    //         {
    //             cout << "arr[" << i << "][" << j << "] = "<< arr[i][j] << '\n';
    //         }
    //     }
    // }

    // return 0;

    queue<Info> q;

    Info tmp = {0, 0, 0};
    tmp.visit.resize(n + 1);
    tmp.visit[0] = true;

    q.push(tmp);
    int res = -1;
    while(!q.empty())
    {
        Info &info = q.front();
        q.pop();

        if (info.cur == 0 && info.cnt_ride == n)
        {
            if (info.sum_time > res)
                res = info.sum_time;
            continue;
        }

        for (int i = 0; i <= n; i++)
        {
            if (arr[info.cur][i])
            {
                if (i == 0 && info.cnt_ride == n)
                {
                    Info nInfo = {i, info.cnt_ride, info.sum_time + arr[info.cur][i]};
                    nInfo.visit.resize(n + 1);
                    nInfo.visit = info.visit;
                    q.push(nInfo);
                }
                else if (info.visit[i] == false)
                {
                    Info nInfo = {i, info.cnt_ride + 1, info.sum_time + arr[info.cur][i]};
                    nInfo.visit.resize(n + 1);
                    nInfo.visit = info.visit;
                    nInfo.visit[i] = true;
                    q.push(nInfo);
                }
                else
                    continue;
            }
        }

    }

    cout << res;
}