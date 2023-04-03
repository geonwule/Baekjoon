#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	int x;
	int y;
}	t_vars;

int n, ret[11], ret_cnt = 0;
t_vars	queen[11];

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

void	print_ret(void)
{
	for (int i = 1; i <= 10; i++)
	{
		int j = 1;
		while (queen[j].y != i)
			j++;
		printf("%d", queen[j].x);
	}
	printf("\n");
}

int sec = 1;
void	dfs(int level, int q_idx)
{
	if (level == 10)
	{
		ret_cnt += 1;
		print_ret();
		printf("-----%d----------\n", sec++);
		return ;
	}
	for (int y = 1; y <= 10; y++)
	{
		for (int x = 1; x <= 10; x++)
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
	dfs(0, 1);
	printf("%d\n", ret_cnt);
}