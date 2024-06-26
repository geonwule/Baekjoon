#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#include <queue>
void bfs(vector<vector<int>> &vv, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    while (q.size())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        vv[curY][curX] = 0;
        // cout << "clear " << curX << "," << curY << '\n'; //test

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || ny < 0 || nx >= vv[0].size() || ny >= vv.size() || vv[ny][nx] == 0)
                continue;

            q.push({nx, ny});
        }
    }
}

void print(int N, int M, const vector<vector<int>>& vv);

int solution(vector<vector<int>> &vv, const vector<pair<int, int>> &orders)
{
    int answer = 0;

    // cout << "first\n";// test
    // print(vv.size(), vv[0].size(), vv); //test

    for (const auto &p : orders)
    {
        int x = p.first;
        int y = p.second;
        if (vv[y][x])
        {
            // dfs();
            bfs(vv, x, y);
            answer++;
            // cout << '\n'; //test
            // cout << x << "," << y << '\n'; //test
            // print(vv.size(), vv[0].size(), vv); //test
        }
    }
    return answer;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
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