#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1001][1002] = {
	0,
};
int arr2[1001][1002] = {
	0,
};

void dfs(int *n, int s, int n_max)
{
	if (*n == 0 || arr[s][0] == 0)
		return;
	if (arr[s][0] == 1)
	{
		printf("%d", s);
		arr[s][0] = 0;
		arr[s][1001] -= 1;
		*n -= 1;
		if (*n == 0)
		{
			printf("\n");
			return;
		}
		else
			printf(" ");
	}
	for (int i = 1; i <= n_max; i++)
	{
		if (*n == 0)
			return;
		if (arr[s][i] == 1)
		{
			dfs(n, i, n_max);
			arr[s][1001] -= 1;
		}
	}
}

void bfs(int *n, int s, int n_max)
{
	// if (*n == 0 || arr[s][0] == 0)
	// 	return ;
	if (arr2[s][0] == 1)
	{
		printf("%d", s);
		arr2[s][0] = 0;
		arr[s][1001] -= 1;
		*n -= 1;
		if (*n == 0)
		{
			printf("\n");
			return;
		}
		else
			printf(" ");
	}
	for (int i = 1; i <= n_max; i++)
	{
		if (arr2[s][1001] <= 0)
			break ;
		if (arr2[s][i] == 1 && arr2[i][0] == 1)
		{
			printf("%d", i);
			*n -= 1;
			arr[s][1001] -= 1;
			if (*n == 0)
			{
				printf("\n");
				return;
			}
			else
				printf(" ");
			arr2[i][0] = 0;
		}
	}
	for (int i = 1; i <= n_max; i++)
	{
		if (*n == 0)
			return;
		if (arr2[s][i] == 1)
			bfs(n, i, n_max);
	}
}

int n_count(void)
{
	int cnt = 0;

	for (int i = 1; i <= 1000; i++)
	{
		if (arr[i][0] == 1)
			cnt++;
	}
	return (cnt);
}

void	input(int m)
{
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][0] = 1;
		arr[a][b] = 1;
		arr[b][0] = 1;
		arr[b][a] = 1;
		arr2[a][0] = 1;
		arr2[a][b] = 1;
		arr2[b][0] = 1;
		arr2[b][a] = 1;
		arr[a][1001] += 1;
		arr[b][1001] += 1;
		arr2[a][1001] += 1;
		arr2[b][1001] += 1;
	}
}

int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	input(m);
	int nc, nc_o;
	nc = nc_o = n_count();
	dfs(&nc, s, n);
	bfs(&nc_o, s, n);
}
