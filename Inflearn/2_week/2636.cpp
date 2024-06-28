#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> visited;
vector<pair<int, int>> vanish;
void    dfs_check_side(int x, int y, vector<vector<int>>& v)
{
    if (v[y][x] == 1)
    {
        v[y][x] = 2;
        vanish.push_back({x, y});
        return;
    }

    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size() || visited[ny][nx])
            continue;
        
        visited[ny][nx] = 1;
        dfs_check_side(nx, ny, v);
    }
}

void print(const vector<vector<int>>& v)
{
    for (const auto & vv : v)
    {
        for (const int & i : vv)
            cout << i << ' ';
        cout << '\n';
    }
}

vector<int> solution(int N, int M, vector<vector<int>>& v)
{
    visited.resize(N + 2, vector<int>(M + 2, 0));
    vanish.clear();
    for (int y = 0; y <= N + 1; y++)
    {
        for (int x = 0; x <= M + 1; x++)
        {
            //가장자리
            if (!(y == 0 || y == N + 1 || x == 0 || x == M + 1) || visited[y][x])
                continue;
            visited[y][x] = 1; // 방문 체크
            dfs_check_side(x, y, v);
        }
    }

    int time_cnt = 0;
    int prev_cheese_cnt = 0;
    int test = 0; //test
    while(1)
    {
        if (vanish.empty())
            break;

        prev_cheese_cnt = vanish.size();
        time_cnt++;
        
        vector<pair<int, int>> tmp(vanish);
        vanish.clear();
        visited.resize(N + 2, vector<int>(M + 2, 0)); // 방문 초기화
        for (auto& vp : tmp)
        {
            int x = vp.first;
            int y = vp.second;

            v[y][x] = 0; //vanished
            visited[y][x] = 1; // 방문 체크
            dfs_check_side(x, y, v);
        }
        // cout << "test = " << ++test << '\n'; //test
        // print(v); //test
    }

    return {time_cnt, prev_cheese_cnt};
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N + 2, vector<int>(M + 2, -1));
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
            cin >> v[y][x];
    }

    vector<int> answer = solution(N, M, v);
    cout << answer[0] << '\n' << answer[1] << '\n';

    return 0;
}