#include <stdio.h>
#include <stdlib.h>

int	queen[15], ret_cnt = 0, n;

int	no_queen_check(int idx)
{
	if (idx == 0)
		return (0);
	int now_idx = idx;
	while (--idx >= 0)
	{
		if (queen[now_idx] == queen[idx] 
		|| abs(now_idx - idx) == abs(queen[now_idx] - queen[idx]))
			return (1);
	}
	return (0);
}

void	print_queen(void)
{
	for (int i = 0; i < n; i++)
		printf("%d", queen[i]);
	printf("\n");
}

void	dfs(int idx)
{
	if (idx == n)
	{
		//print_queen();
		ret_cnt++;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		queen[idx] = i;
		if (no_queen_check(idx))
			continue ;
		dfs(idx + 1);
	}
}

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("ret_cnt = %d\n", ret_cnt);
}