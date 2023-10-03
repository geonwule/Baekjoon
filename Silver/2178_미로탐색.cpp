#include <iostream>

int n, m, arr[101][101];
bool visited[101][101] = {false, };

int ret = -1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#include <queue>

struct tt
{
	int x, y, mo;
};

void	bfs(void)
{
	std::queue<tt>	q;
	tt	temp;
	temp.mo = 1;
	temp.x = 1;
	temp.y = 1;
	q.push(temp);
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int mo = q.front().mo;
		q.pop();
		if (visited[y][x])
			continue;
		if (x == m && y == n)
		{
			ret = mo;
			return ;
		}
		visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > m || ny > n)
				continue;
			if (arr[ny][nx] == 1 && !visited[ny][nx])
			{
				temp.mo = mo + 1;
				temp.x = nx;
				temp.y = ny;
				q.push(temp);
			}
		}
	}
}

int main()
{
	std::cin >> n >> m;
	std::cin.ignore();
	for (int y = 0; y < n; y++){
		std::string t;
		std::getline(std::cin, t);
		for (int x = 0; x < m; x++){
			arr[y+1][x+1] = t[x] - '0';
	}
}
	// dfs(1, 1, 1);
	bfs();
	std::cout << ret;
}

// void	dfs(int x, int y, int move)
// {
// 	// std::cout << "here : " << ++q << std::endl;
// 	visited[y][x] = true;
// 	if (x == m && y == n && (ret == -1 || ret > move)){
// 		ret = move;
// 		return ;
// 	}
// 	for (int i = 0; i < 4; i++){
// 		int nx = x + dx[i];
// 		int ny = y + dy[i];
// 		if (nx < 0 || ny < 0 || nx > m || ny > n)
// 			continue ;
// 		if (arr[ny][nx] == 1 && !visited[ny][nx]){
// 			dfs(nx, ny, move + 1);
// 			visited[ny][nx] = false;
// 		}
// 	}	
// }