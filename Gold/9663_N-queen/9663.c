#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	int x;
	int y;
}	t_vars;

int n, arr[15][15], ret = 0;
t_vars	queen[15];

void	map_init(void)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			arr[i][j] = 0;
	}
}

int	no_queen(int idx)
{
	int now = idx;

	if (idx == 1)
		return (0);
	while (--idx > 0)
	{
		if (queen[now].x == queen[idx].x || queen[now].y == queen[idx].y // 상, 하, 좌, 우
		|| abs(queen[now].x - queen[idx].x) == abs(queen[now].y - queen[idx].y)) // 대각선
			return (1);
	}
	return (0);
}

void	dfs(int level, int q_idx)
{
	if (level == n)
	{
		ret += 1;
		return ;
	}
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			queen[q_idx].x = x;
			queen[q_idx].y = y;
			if (no_queen(q_idx))
				continue ;
			dfs(level + 1, q_idx + 1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	//map_init();
	dfs(0, 1);
	printf("%d\n", ret);
}