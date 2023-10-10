#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <queue>
#include <deque>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int arr[100][100];
bool visited[100][100] = {
    false,
};

int n, m;


int main()
{
    cin >> n >> m;
    deque<pair<int, int> > q, qq, air;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> arr[y][x];
        }
    }
    air.push_back(make_pair(0, 0));

    // print arr
    /*
    for(int y=0;y<n;y++)
    {
        for(int x=0;x<m;x++)
        {
            cout<<arr[y][x]<<" ";
        }
        cout<<"\n";
    }*/
    // return 0;

    int ret = -2, r = 0;
    while (!(q.empty() && qq.empty() && air.empty()))
    {
        ret++; // 시간 up
        if (q.empty()) // 맨 처음 || 한바퀴 돌았을 때만
        {
            if (!qq.empty())
            {
                q = qq;
                qq.clear();
            }

            while (!air.empty())
            {
                int x = air.front().first;
                int y = air.front().second;
                air.pop_front();
                if (visited[y][x]) // already outer check
                    continue;
                visited[y][x] = true;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (arr[ny][nx]) // cheese
                        q.push_back(make_pair(nx, ny));
                    else // outAir
                        air.push_back(make_pair(nx, ny));
                }
            }
        }

        while (!q.empty()) // 가장자리 cheese 녹이기
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (visited[ny][nx]) // outter air
                    cnt++;
            }
            if (cnt >= 2)
                air.push_back(make_pair(x, y));
            else
                qq.push_back(make_pair(x, y));
        }
    }
    cout << ret;
}
