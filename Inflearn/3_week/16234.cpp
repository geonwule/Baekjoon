// #include <iostream>
// #include <vector>
// #include <algorithm> //fill

// using namespace std;

// vector<vector<int>> visited;

// int N, L, R;
// vector<vector<int>> vv;
// const int dx[] = {0, 0, 1, -1};
// const int dy[] = {1, -1, 0, 0};

// #include <queue>
// #include <tuple>
// int bfs(int x, int y)
// {
//     visited[y][x] = 1;
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     int areaCnt = 0;
//     int sum = 0;
//     vector<pair<int, int>> vp;
//     while (q.size())
//     {
//         tie(x, y) = q.front();
//         q.pop();
//         areaCnt++;
//         sum += vv[y][x];
//         vp.push_back({x, y});

//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
//                 continue;
//             int a = vv[y][x];
//             int b = vv[ny][nx];
//             if (abs(b - a) >= L && abs(b - a) <= R)
//             {
//                 visited[ny][nx] = 1;
//                 q.push({nx, ny});
//             }
//         }
//     }

//     if (areaCnt == 1)
//         return 0;
    
//     for (auto& p : vp)
//     {
//         tie(x, y) = p;
//         vv[y][x] = sum / areaCnt;
//     }

//     return 1;
// }

// void print()
// {
//     cout << "go\n";
//     for (auto& v : vv)
//     {
//         for (int &i : v)
//             cout << i << ' ';
//         cout << '\n';
//     }
//     cout <<'\n';
// }

// int go()
// {
//     //print();
//     int check = 0;
//     for (int y = 0; y < N; y++)
//     {
//         for (int x = 0; x < N; x++)
//         {
//             if (!visited[y][x])
//             {
//                 check += bfs(x, y);
//             }
//         }
//     }
//     if (check)
//         return 1;
//     return 0;
// }

// int solution()
// {
//     int answer = 0;
//     visited.resize(N, vector<int>(N, 0));

//     int day;
//     do
//     {
//         for (auto& v : visited)
//             fill(v.begin(), v.end(), 0);
//         day = go();
//         answer += day;
//     } while(day);
    
//     return answer;
// }

#include <iostream>
#include <vector>
#include <algorithm> //fill

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<vector<int>> vv, visited;
vector<pair<int, int>> pv;
int N, L, R, sum;

void dfs(int x, int y)
{
    pv.push_back({x, y});
    sum += vv[y][x];

    int t1 = vv[y][x];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
            continue;
        int t2 = vv[ny][nx];
        if (abs(t2 - t1) >= L && abs(t2 - t1) <= R)
        {
            visited[ny][nx] = 1;
            dfs(nx, ny);
        }
    }
}

int solution2()
{
    visited.resize(N, vector<int>(N));
    int answer = 0;
    bool flag;

    int tt=0;
    do
    {
        // cout << ++tt;
        flag = false;
        for (auto& v : visited)
            fill(v.begin(), v.end(), 0);

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (visited[y][x])
                    continue;
                visited[y][x] = 1;
                pv.clear();
                sum = 0;
                dfs(x, y);
                if (pv.size() == 1) continue;
                for (auto& p : pv)
                {
                    int cx, cy;
                    tie(cx, cy) = p;
                    vv[cy][cx] = sum / pv.size();
                }
                flag = true;
            }
        }
        if (flag)
            answer++;
    } while (flag);
    
    return answer;
}

int main()
{
    cin >> N >> L >> R;
    vv.resize(N, vector<int>(N));
    for (auto& v : vv)
    {
        for (int &i : v)
            cin >> i;
    }

    // cout << solution();
    cout << solution2();

    return 0;

}