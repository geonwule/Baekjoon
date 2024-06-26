#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#include <queue>
void bfs(vector<vector<int>> &vv, int x, int y)
{
    vv[y][x] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (q.size())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || ny < 0 || nx >= vv[0].size() || ny >= vv.size() || vv[ny][nx] == 0)
                continue;

            vv[ny][nx] = 0;
            q.push({nx, ny});
        }
    }
}

void dfs(vector<vector<int>> &vv, int x, int y)
{
    vv[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || ny < 0 || nx >= vv[0].size() || ny >= vv.size() || vv[ny][nx] == 0)
            continue;
        dfs(vv, nx, ny);
    }
}

int solution(vector<vector<int>> &vv, const vector<pair<int, int>> &orders)
{
    int answer = 0;

    for (const auto &p : orders)
    {
        int x = p.first;
        int y = p.second;
        if (vv[y][x])
        {
            dfs(vv, x, y);
            // bfs(vv, x, y);
            answer++;
        }
    }
    return answer;
}

int main()
{
    vector<int> answer;
    size_t T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> vv(N, vector<int>(M, 0));
        vector<pair<int, int>> orders;
        while (K--)
        {
            int x, y;
            cin >> x >> y;
            vv[y][x] = 1;
            orders.push_back({x, y});
        }

        answer.push_back(solution(vv, orders));
    }
    for (const int i : answer)
        cout << i << '\n';
    return 0;
}

void print(int N, int M, const vector<vector<int>>& vv)
{
    // test
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
            cout << vv[y][x] << ' ';
        cout << '\n';
    }
}