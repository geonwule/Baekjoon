#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1001][1001] = {
	0,
};
int arr2[1001][1001] = {
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
			dfs(n, i, n_max);
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
		if (arr2[s][i] == 1 && arr2[i][0] == 1)
		{
			printf("%d", i);
			*n -= 1;
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

int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
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
	}
	int nc, nc_o;
	nc = nc_o = n_count();
	dfs(&nc, s, n);
	bfs(&nc_o, s, n);
}
// int **arr_init(int m, int *min)
// {
// 	int **arr = (int **)malloc(sizeof(int *) * m);
// 	for (int i = 0; i < m; i++)
// 	{
// 		arr[i] = (int *)malloc(sizeof(int) * 2);
// 		scanf("%d %d", &arr[i][0], &arr[i][1]);
// 		if (*min > arr[i][0])
// 			*min = arr[i][0];
// 		if (*min > arr[i][1])
// 			*min = arr[i][1];
// 	}
// 	return (arr);
// }

// void print(int *fs, int n)
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%d", fs[i]);
// 		if (i != n - 1)
// 			printf(" ");
// 		else
// 			printf("\n");
// 	}
// }

// int no_double(int *fs, int max, int key)
// {
// 	for (int i = 0; i < max; i++)
// 	{
// 		if (key == fs[i])
// 			return (0);
// 	}
// 	return (1);
// }

// void dfs_go(int **arr, int *dfs, int max, int m, int v, int i)
// {
// 	int new_v = 1001;

// 	if (i == max)
// 		return;
// 	for (int j = 0; j < m; j++)
// 	{
// 		if (arr[j][0] == v && new_v > arr[j][1] && no_double(dfs, i, arr[j][1]))
// 		{
// 			new_v = arr[j][1];
// 		}
// 		else if (arr[j][1] == v && new_v > arr[j][0] && no_double(dfs, i, arr[j][0]))
// 		{
// 			new_v = arr[j][0];
// 		}
// 	}
// 	dfs[i++] = new_v;
// 	dfs_go(arr, dfs, max, m, new_v, i);
// }

// void old_v_init(int *old_v, int max)
// {
// 	for (int i = 0; old_v[i] != 0 && i < max; i++)
// 		old_v[i] = 0;
// }

// int o_i = 0;

// void bfs_go(int **arr, int *bfs, int max, int m, int v, int i)
// {
// 	int new_v, old_v[max] = {0,};
// 	// old_v_init(old_v);
// 	// old_v_push(old_v, v);
// 	old_v[o_i++] = v;
// 	while (i < max)
// 	{
// 		new_v = 1004;
// 		for (int k = 0; k < o_i; k++)
// 		{
// 			for (int j = 0; j < m; j++)
// 			{
// 				if (arr[j][0] == old_v[k] && new_v > arr[j][1] && no_double(bfs, i, arr[j][1]))
// 				{
// 					new_v = arr[j][1];
// 				}
// 				else if (arr[j][1] == old_v[k] && new_v > arr[j][0] && no_double(bfs, i, arr[j][0]))
// 				{
// 					new_v = arr[j][0];
// 				}
// 			}
// 		}
// 		if (new_v == 1004)

// 		else
// 		{
// 			bfs[i++] = new_v;
// 		}
// 	}
// }

// int main()
// {
// 	int n, m, v;
// 	scanf("%d %d %d", &n, &m, &v);
// 	int **arr, dfs[n], bfs[n], min = 1004;
// 	arr = arr_init(m, &min);
// 	dfs[0] = v;
// 	bfs[0] = v;
// 	dfs_go(arr, dfs, n - min + 1, m, v, 1);
// 	bfs_go(arr, bfs, n - min + 1, m, v, 1);
// 	print(dfs, n - min + 1);
// 	print(bfs, n - min + 1);
// }