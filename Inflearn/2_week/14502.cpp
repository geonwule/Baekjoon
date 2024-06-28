#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<vector<int>> visited;

void print(const vector<vector<int>>& v)
{
    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[0].size(); x++)
        {
            cout << v[y][x] << ' ';
        }
        cout << '\n';
    }
}

int dfs_cnt = 0;
void dfs(int x, int y, vector<vector<int>>& vmap, vector<vector<int>>& vis, int& cnt_safe)
{
    dfs_cnt++; //test
    vis[y][x] = 1;

    if (vmap[y][x] == 0)
        cnt_safe--;

    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx < 0 || ny < 0 || nx >= vmap[0].size() || ny >= vmap.size() || vmap[ny][nx] == 1 || vis[ny][nx] == 1)
            continue;
        
        dfs(nx, ny, vmap, vis, cnt_safe);
    }
}

int virus(int cnt_safe)
{
    vector<vector<int>> vmap(visited);
    vector<vector<int>> vis(vmap.size(), vector<int>(vmap[0].size(), 0));

    for (int y = 0; y < vmap.size(); y++)
    {
        for (int x = 0; x < vmap[0].size(); x++)
        {
            if(vmap[y][x] == 2 && vis[y][x] == 0)
            {
                dfs(x, y, vmap, vis, cnt_safe);
            }
        }
    }

    return cnt_safe;
}

int backTracking_cnt = 0;
void backTracking(int depth, int sum, const vector<vector<int>> &v)
{
    // cout << "backTracking_cnt = " << ++backTracking_cnt << '\n'; //test
    // cout << "backTracking_cnt * dfs_cnt = " << ++backTracking_cnt << '\n'; //test
    if (depth == 3)
    {
        dfs_cnt = 0;
        answer = max(answer, virus(sum));
        backTracking_cnt += dfs_cnt;

        // print(); //test
        // cout << '\n'; //test
        return;
    }

    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[0].size(); x++)
        {
            if (visited[y][x] == 0)
            {
                visited[y][x] = 1;
                backTracking(depth + 1, sum - 1, v);
                visited[y][x] = 0;
            }
        }
    }
}

int solution(const vector<vector<int>> &v, const int N, const int M)
{
    visited = v;
    int cnt_zero = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (v[y][x] == 0)
                cnt_zero++;
        }
    }
    backTracking(0, cnt_zero, v);
    // cout << "cnt = " << backTracking_cnt << '\n'; //test
    return answer;
}

struct Pos
{
    int x, y;
};

vector<vector<int>> visited2;

void    dfs2(vector<vector<int>>& v, int x, int y)
{
    v[y][x] = 2; //virus

    const static int dx[] = {1, -1, 0, 0};
    const static int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size() || visited2[ny][nx] || v[ny][nx] == 1)
            continue;
        
        visited2[ny][nx] = 1;
        dfs2(v, nx, ny);
    }
}

#include <algorithm>
int solve(vector<vector<int>> v, vector<Pos>& virus_v)
{
    for (auto &vv : visited2)
        fill(vv.begin(), vv.end(), 0);
    
    for (const Pos& pos : virus_v)
    {
        if (visited2[pos.y][pos.x] == 0)
        {
            visited2[pos.y][pos.x] = 1;
            dfs2(v, pos.x, pos.y);
        }
    }

    int solve_ret = 0;
    for (const auto& vv : v)
    {
        for (const int &i : vv)
            if(i == 0) solve_ret++;
    }


    // cout << "ret = " << solve_ret << '\n';
    // print(v);
    return solve_ret;
}

int solution2(vector<vector<int>> &v, const int N, const int M)
{
    visited2.resize(N, vector<int>(M));
    vector<Pos> empty_v;
    vector<Pos> virus_v;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (v[y][x] == 2)
                virus_v.push_back({x, y});
            else if (v[y][x] == 0)
                empty_v.push_back({x, y});
        }
    }

    int ret = 0;
    for (int i = 0; i < empty_v.size(); i++)
    {
        for (int j = i + 1; j < empty_v.size(); j++)
        {
            for (int k = j + 1; k < empty_v.size(); k++)
            {
                v[empty_v[i].y][empty_v[i].x] = 1;
                v[empty_v[j].y][empty_v[j].x] = 1;
                v[empty_v[k].y][empty_v[k].x] = 1;
                ret = max(ret, solve(v, virus_v));
                v[empty_v[i].y][empty_v[i].x] = 0;
                v[empty_v[j].y][empty_v[j].x] = 0;
                v[empty_v[k].y][empty_v[k].x] = 0;
            }
        }
    }

    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> v[y][x];
        }
    }

    // cout << solution(v, N, M);
    cout << solution2(v, N, M);

    return 0;
}


/* 경우의 수 계산
64개의 최대 맵

최최소 1은 0
최최소  2는 2

최최대 0의 갯갯수수는 62개

순순서에 상상관관없없이이

62C3 3개를 뽀는 경우의수

62!
-----
3! x (62 - 3)!


62!
-------
3! x 59!

62 x 61 x 60
--------
3 x 2 x1


62 x 61 x 10 = 약 36000  은 1000만 이하의 경우의수 ㅇㅋ */