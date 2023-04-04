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
	if (ret[now] == ret[idx])
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
	for (int i = 1; i <= n; i++)//ret_i + 1; i <= n; i++)
	{
		ret[idx] = n_box[i];
		if (no_condition(idx))
			continue ;
		//ret_i = i;
		dfs(idx + 1);
	}
}

void	init(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &n_box[i]);
}

int main()
{
	init();
	qsort(n_box, n + 1, sizeof(int), compare);
	// for (int i = 0; i <= n; i++)
	// 	printf("%d", n_box[i]);
	// return (0);
	dfs(1);
}