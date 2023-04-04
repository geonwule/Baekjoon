#include <stdio.h>

int ret[9] = {0}, n, m;

void print_ret(void)
{
	for (int i = 1; i <= m; i++)
	{
		printf("%d", ret[i]);
		if (i == m)
			printf("\n");
		else
			printf(" ");
	}
}

int	no_condition(int idx)
{
	if (idx == 1)
		return (0);
	int now = idx--;
	if (ret[now] < ret[idx])
		return (1);
	return (0);
}

void	dfs(int idx)
{
	if (idx == m + 1)
	{
		print_ret();
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		ret[idx] = i;
		if (no_condition(idx))
			continue ;
		dfs(idx + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(1);
}