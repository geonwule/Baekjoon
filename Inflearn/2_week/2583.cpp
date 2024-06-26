#include <iostream>
#include <vector>

using namespace std;


void print_vv(const vector<vector<int>>& vv)
{
    for (int y = vv.size() - 1; y >= 0; y--)
    {
        for (int x = 0; x < vv[0].size(); x++)
        {
            cout << vv[y][x] << ' ';
        }
        cout << '\n';
    }
}

#include <queue>
int bfs(int x, int y, vector<vector<int>>& vv)
{
    int answer = 1;
    vv[y][x] = -1;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (q.size())
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
            if (nx < 0 || ny < 0 || nx >= vv[0].size() || ny >= vv.size() || vv[ny][nx] != 0)
                continue;
            
            vv[ny][nx] = -1;
            answer++;
            q.push({nx, ny});
        }
    }

    return answer;
}

void dfs(int x, int y, vector<vector<int>> &vv, int &dfs_cnt)
{
    dfs_cnt++;
    vv[y][x] = -1;

    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= vv[0].size() || ny >= vv.size() || vv[ny][nx] != 0)
            continue;
        
        dfs(nx, ny, vv, dfs_cnt);
    }
}

#include <algorithm>
vector<vector<int>> solution(vector<vector<int>>& vv, const int N, const int M)
{
    int ans_cnt = 0;
    vector<int> ans_v;

    for (int y = N - 1; y >= 0; y--)
    {
        for (int x = 0; x < M; x++)
        {
            if (vv[y][x] == 0)
            {
                ans_cnt++;
                // ans_v.push_back(bfs(x, y, vv));
                int dfs_cnt = 0;
                dfs(x, y, vv, dfs_cnt);
                ans_v.push_back(dfs_cnt);
            }
        }
    }

    sort(ans_v.begin(), ans_v.end());
    vector<vector<int>> answer(2);
    answer[0].push_back(ans_cnt);
    answer[1] = ans_v;
    return answer;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> vv(N, vector<int>(M, 0));
    while (K--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                vv[y][x] = 1;
            }
        }
    }

    vector<vector<int>> answer = solution(vv, N, M);
    for (const auto& v : answer)
    {
        for (const int i : v)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}