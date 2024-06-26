#include <iostream>
#include <vector>

using namespace std;

int min_height = 101, max_height = 0;
vector<vector<int>> visited;

#include <queue>
void bfs(const vector<vector<int>> &vv, int x, int y, const int height)
{
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});

    while(q.size())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        static int dx[] = {1, -1, 0, 0};
        static int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || ny < 0 || nx >= vv.size() || ny >= vv.size() || vv[ny][nx] <= height || visited[ny][nx])
                continue;
            visited[ny][nx] = 1;
            q.push({nx, ny});
        }
    }
}


void print_vv(const vector<vector<int>>& vv)
{
    for (const auto &v : vv)
    {
        for (const int i : v)
            cout << i << ' ';
        cout << '\n';
    }
}

void dfs(const vector<vector<int>> &vv, int x, int y, const int height)
{
    visited[y][x] = 1;

    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= vv.size() || ny >= vv.size() || vv[ny][nx] <= height || visited[ny][nx] == 1)
            continue;
        
        dfs(vv, nx, ny, height);
    }
}

int solution(const int N, const vector<vector<int>> &vv)
{
    int answer = 1;

    visited.resize(N, vector<int>(N, 0));
    for (int height = min_height; height < max_height; height++)
    {
        int cnt = 0;
        for (int y = 0; y < N; y++)
            fill(visited[y].begin(), visited[y].end(), 0);

        // cout << "before\n"; //test
        // print_vv(visited); //test

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (vv[y][x] > height && visited[y][x] == 0)
                {
                    dfs(vv, x, y, height);
                    // bfs(vv, x, y, height);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
        // cout << "after\n"; //test
        // print_vv(visited); //test
    }
    return answer;
}

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> vv(N, vector<int>(N));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> vv[y][x];
            min_height = min(min_height, vv[y][x]);
            max_height = max(max_height, vv[y][x]);
            /* 복붙때문에 실수했던 부분 
                max_height = max(min_height, vv[y][x]);
            */
        }
    }
    cout << solution(N, vv);

    return 0;
}