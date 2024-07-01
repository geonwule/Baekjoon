#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


void print(vector<vector<int>> v)
{
	for (auto &vv : v)
	{
		for (auto &i : vv)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<vector<int>> visited;
#include <queue>
int answer = 0;

void bfs(int x, int y, const vector<vector<char>> &v)
{
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({x, y});
	while (q.size())
	{
		tie(x, y) = q.front(); q.pop();

		const static int dx[] = {1, -1, 0, 0};
		const static int dy[] = {0, 0, 1, -1};
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size() || v[ny][nx] == 'W' || visited[ny][nx])
				continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			answer = max(answer, visited[ny][nx]);
			q.push({nx, ny});
		}
	}
}

int solution(const int N, const int M, vector<vector<char>> &v)
{
	visited.resize(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (v[y][x] == 'L')
			{
				for (auto& vv : visited)
					fill(vv.begin(), vv.end(), 0);
				bfs(x, y, v);
			}
		}
	}
	return answer - 1;
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
