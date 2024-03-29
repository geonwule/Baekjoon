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

void	dfs(int idx)
{
	if (idx == m + 1)
	{
		print_ret();
		return ;
	}
	for (int i = ret[idx - 1] + 1; i <= n; i++)
	{
		ret[idx] = i;
		dfs(idx + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(1);
}