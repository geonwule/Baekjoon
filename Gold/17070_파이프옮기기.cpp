#include <iostream>

enum	e_flag
{
	GARO = 0,
	SERO,
	DEGAK,
};

int n, arr[17][17], ret = 0;
bool visited[17][17] = {false, };

void set_input(void)
{
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

int dx[3] = {1, 0, 1}; // 가로, 세로, 대각
int dy[3] = {0, 1, 1};

void	dfs(int x, int y, int dir)
{
	if (y == n && x == n)
	{
		ret++;
		return ;
	}

	for (int i = 0; i < 3; i++)
	{
		if (dir == GARO && i == SERO) // impossible
			continue ;
		if (dir == SERO && i == GARO) // impossible
			continue ;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > n || ny > n) // impossible
			continue ;
		if (i == GARO || i == SERO)
		{
			if (arr[ny][nx] == 0)
				dfs(nx, ny, i);
		}
		else if (i == DEGAK)
		{
			if (arr[ny][nx] == 0 && arr[ny - 1][nx] == 0 && arr[ny][nx - 1] == 0)
				dfs(nx, ny, i);
		}
	}
}

int main()
{
	set_input();

	// recur(2, 1, GARO);
	dfs(2, 1, 0);
	std::cout << ret;
}

/* dfs
void dfs(int x, int y, int dir) {
    //dir => 0: 가로 1: 세로 2: 대각선
    if(x == n - 1 && y == n - 1) {
        ret++;
        return;
    }

    visited[x][y] = true;

    for(int i = 0 ; i < 3 ; i++) { // 가로, 세로, 대각 이동 체크
        if(dir == 0 && i == 1) continue; // 파이프 가로 && 세로 방향으로 이동 // 불가능한경우
        else if(dir == 1 && i == 0) continue; // 파이프 세로 && 가로 방향으로 이동 // 불가능한경우
        else {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if(nx >= n || ny >= n) continue; // 벗어나는 경우
            
            if(i < 2) { // 가로, 세로로 이동
				// 빈곳 이면서 && 방문한적이 없는곳
                if(!arr[nx][ny] && !visited[nx][ny]) {
                    dfs(nx, ny, i); // 안에서는 visted = true로 바뀜
                    visited[nx][ny] = false; // 밖에서는 다시 false로 바꿔주기?
                }
            }
            else { //대각선
                if(!arr[nx][ny] && !arr[nx - 1][ny] && !arr[nx][ny - 1] && !visited[nx][ny]) {
                    dfs(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
        }
    }
}

*/
/* my recur
void	recur(int x, int y, int flag)
{
	int nx, ny;

	visited[y][x] = true;
	if (x > n || y > n)
		return ;
	if (x == n && y == n && visited[y][x] == false)
	{
		ret += 1;
		return ;
	}
	if (flag == GARO && x + 1 <= n && arr[y][x + 1] == 0)
	{
		nx = x + dx[0];
		ny = y + dy[0];
		recur(nx, ny, GARO);
		if (y + 1 <= n && arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0)
		{
			nx = x + dx[2];
			ny = y + dy[2];
			recur(nx, ny, DEGAK);
		}
	}
	else if (flag == SERO && y + 1 <= n && arr[y + 1][x] == 0)
	{
		nx = x + dx[1];
		ny = y + dy[1];
		recur(nx, ny, SERO);
		if (x + 1 <= n && arr[y][x + 1] == 0 && arr[y + 1][x + 1] == 0)
		{
			nx = x + dx[2];
			ny = y + dy[2];
			recur(nx, ny, DEGAK);
		}
	}
	else if (flag == DEGAK)
	{
		if (x + 1 <= n && arr[y][x + 1] == 0)
		{
			nx = x + dx[0];
			ny = y + dy[0];
			recur(nx, ny, GARO);
		}
		if (y + 1 <= n && arr[y + 1][x] == 0)
		{
			nx = x + dx[1];
			ny = y + dy[1];
			recur(nx, ny, SERO);
		}
		if (x + 1 <= n && y + 1 <= n && arr[y + 1][x + 1] == 0 \
			&& arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0)
		{
			nx = x + dx[2];
			ny = y + dy[2];
			recur(nx, ny, DEGAK);
		}
	}
}
*/