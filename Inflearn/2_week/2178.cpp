#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int dfs_answer = 0;

struct Pos
{
    int x, y;
};

unordered_set<string> visited2;

void dfs(int sum, Pos start, const Pos& goal, const vector<vector<int>> &vv)
{
    if (start.x == goal.x && start.y == goal.y)
    {
        dfs_answer = dfs_answer == 0 ? sum : min(dfs_answer, sum);
        return;
    }

    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = start.x + dx[i];
        int ny = start.y + dy[i];

        if (nx < 1 || ny < 1 || nx > vv[0].size() - 1 || ny > vv.size() - 1 || vv[ny][nx] == 0)
            continue;
        
        string tmp = to_string(nx) + "," + to_string(ny);
        if (visited2.count(tmp))
            continue;
        visited2.insert(tmp);
        dfs(sum + 1, {nx, ny}, goal, vv);
        visited2.erase(tmp);
    }
}

//dfs
int solution2(const int N, const int M, const vector<vector<int>> &vv)
{
    Pos start = {1, 1}, goal = {M, N};
    visited2.insert("1,1");
    dfs(1, start, goal, vv);
    return dfs_answer;
}

struct Node
{
    int x, y, sum;
};

//bfs
int solution(const int N, const int M, const vector<vector<int>> &vv)
{
    int answer = 0;
    queue<Node> q;
    unordered_set<string> visited;
    
    q.push({1, 1, 1});
    visited.insert("1,1");
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        // cout << "pos = " << cur.x << ',' << cur.y << '\n';

        if (cur.x == M && cur.y == N)
        {
            answer = answer == 0 ? cur.sum : min(answer, cur.sum);
            continue;
        }

        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.x;
            int ny = dy[i] + cur.y;

            if (nx < 1 || ny < 1 || nx > M || ny > N || vv[ny][nx] == 0)
                continue;

            string tmp = to_string(nx) + "," + to_string(ny);
            if (visited.count(tmp))
                continue;
            visited.insert(tmp);
            q.push({nx, ny, cur.sum + 1});
        }
    }

    return answer;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int>> vv(N + 1, vector<int>(M + 1));
    for (int y = 1; y <= N; y++)
    {
        string str;

        cin >> str;
        for (int x = 1; x <= M; x++)
        {
            vv[y][x] = str[x - 1] - '0';
        }
    }

    // for (int y = 1; y <= N; y++)
    // {
    //     for (int x = 1; x <= M; x++)
    //         cout << vv[y][x] << ' ';
    //     cout << '\n';
    // }

    // cout << solution(N, M, vv); //bfs
    cout << solution2(N, M, vv); //dfs

    return 0;
}