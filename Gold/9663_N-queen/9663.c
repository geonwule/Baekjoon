#include <stdio.h>
#include <stdlib.h>

int n, ret = 0, queen[15];

int	no_queen(int idx)
{
	if (idx == 1)
		return (0);
	int now = idx;
	while (--idx > 0)
	{
		if (queen[now] == queen[idx] // 상, 하, 좌, 우
		|| abs(now - idx) == abs(queen[now] - queen[idx])) // 대각선
			return (1);
	}
	return (0);
}

void	dfs(int q_idx)
{
	if (q_idx > n)
	{
		ret += 1;
		return ;
	}
	for (int y = 1; y <= n; y++)
	{
		queen[q_idx] = y;
		if (no_queen(q_idx))
			continue ;
		dfs(q_idx + 1);
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", ret);
}