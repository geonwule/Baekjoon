#include <stdio.h>
#include <stdlib.h>

int	compare(const void *x, const void *y)
{
	int a = *(int *)x;
	int b = *(int *)y;
	return (a - b);
}

int ret[9] = {0}, n, m, n_box[9], ret_i = 0;

void print_ret(void)
{
	for (int i = 0; i < m; i++)
	{
		printf("%d", ret[i]);
		if (i + 1 == m)
			printf("\n");
		else
			printf(" ");
	}
}

void	init(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &n_box[i]);
}

int	no_condition(int idx)
{
	if (idx == 0)
		return (0);
	int now = idx;
	while (--idx >= 0)
	{
		if (ret[now] < ret[idx])
			return (1);
	}
	return (0);
}

void	dfs(int idx)
{
	if (idx == m)
	{
		print_ret();
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		ret[idx] = n_box[i];
		if (no_condition(idx))
			continue ;
		dfs(idx + 1);
	}
}


int main()
{
	init();
	qsort(n_box, n, sizeof(int), compare);
	dfs(0);
}
