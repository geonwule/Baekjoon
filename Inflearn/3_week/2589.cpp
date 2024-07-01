#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x, y;
};
vector<Pos> landlist;

struct Info
{
    Pos p1, p2;
    int dis;
};
vector<Info> ltol;
#include <algorithm>
#include <unordered_set>
unordered_set<string> visited;

vector<vector<int>> vis;
int dfs(int sum, Pos cur, const Pos& goal, const vector<vector<char>> &v)
{
	if (cur.x == goal.x && cur.y == goal.y)
		return sum;

	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};

	int dfs_answer = 100000000;
	for (int i = 0; i < 4; i++)
	{
		int nx = cur.x + dx[i];
		int ny = cur.y + dy[i];

		if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size() || v[ny][nx] == 'W' || vis[ny][nx])
			continue;
		
		vis[ny][nx] = 1;
		dfs_answer = min(dfs_answer, dfs(sum + 1, {nx, ny}, goal, v));
		vis[ny][nx] = 0;
	}
	
	if (dfs_answer == 100000000)
		return 0;
	
	return dfs_answer;
}

bool comp(const Info& a, const Info& b)
{
    return a.dis > b.dis;
}

int solution(const int N, const int M, vector<vector<char>> &v)
{
	vis.resize(N, vector<int>(M, 0));
    // 2500
    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[0].size(); x++)
        {
            if (v[y][x] == 'L')
                landlist.push_back({x, y});
        }
    }

    //2500
    for (int i = 0; i < landlist.size(); i++)
    {
        Pos &p1 = landlist[i];
        for (int j = i + 1; j < landlist.size(); j++)
        {
            Pos &p2 = landlist[j];
            ltol.push_back({p1, p2, abs(p1.x - p2.x) + abs(p1.y - p2.y)});
        }
    }

    sort(ltol.begin(), ltol.end(), comp);
    
    for (auto &info : ltol)
    {
		vis[info.p1.y][info.p1.x] = 1;
		int dis = dfs(0, info.p1, info.p2, v);
        if (dis)
            return dis;
		vis[info.p1.y][info.p1.x] = 0;
    }

    return 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M));
    for (auto &vv : v)
    {
        string line;
        cin >> line;
        for (int x = 0; x < vv.size(); x++)
            vv[x] = line[x];
    }
    cout << solution(N, M, v);
    return 0;
}
