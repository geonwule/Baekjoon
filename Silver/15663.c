#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
	int a = *(int *)x;
	int b = *(int *)y;
	return (a - b);
}

int	n, m, n_box[9], ret[9], ret_idx = -1;

typedef struct s_vars
{
	int box[9];
} t_vars;

t_vars before[10001];
int before_idx = 0;

int no_condition(void)
{
	if (before_idx == 0)
		return (0);
	int b_idx = before_idx;
	while (b_idx >= 0)
	{
		int duplication = 1;
		for (int i = 0; i < m; i++)
		{
			if (ret[i] != before[b_idx].box[i])
				duplication = 0;
		}
		if (duplication == 1)
			return (1);
		b_idx--;
	}
	return (0);
}

void input_init(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &n_box[i]);
	}
}

void	print_ret(void)
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

void before_cpy(void)
{
	for (int i = 0; i < m; i++)
		before[before_idx].box[i] = ret[i];
	before_idx++;
}

void	dfs(int idx)
{
	if (idx == m)
	{
		if (no_condition())
			return ;
		print_ret();
		before_cpy();
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (ret_idx != -1 && ret_idx == i)
			continue ;
		ret[idx] = n_box[i];
		ret_idx = i;
		dfs(idx + 1);
	}
}

int main()
{
	input_init();
	qsort(n_box, n, sizeof(int), compare);
	dfs(0);
}




// #include <stdio.h>
// #include <stdlib.h>

// int compare(const void *x, const void *y)
// {
// 	int a = *(int *)x;
// 	int b = *(int *)y;
// 	return (a - b);
// }

// int ret[9] = {0}, n, m, n_box[9], ret_i = 0, double_box[10001] = {
// 												 0,
// };

// typedef struct s_vars
// {
// 	int box[9];
// } t_vars;

// t_vars before[10001];
// int before_idx = 0;

// void print_ret(void)
// {
// 	for (int i = 0; i < m; i++)
// 	{
// 		printf("%d", ret[i]);
// 		if (i + 1 == m)
// 			printf("\n");
// 		else
// 			printf(" ");
// 	}
// }

// void init(void)
// {
// 	scanf("%d %d", &n, &m);
// 	for (int i = 0; i < n; i++)
// 	{
// 		scanf("%d", &n_box[i]);
// 		double_box[n_box[i]] += 1;
// 	}
// }

// typedef struct s_vars
// {
// 	int box[9];
// } t_vars;

// t_vars before[10001];
// int before_idx = 0;

// int no_condition(int idx)
// {
// 	if (before_idx == 0)
// 		return (0);
// 	int b_idx = before_idx;
// 	while (b_idx >= 0)
// 	{
// 		int duplication = 1;
// 		for (int i = 0; i < m; i++)
// 		{
// 			if (ret[i] != before[b_idx].box[i])
// 				duplication = 0;
// 		}
// 		if (duplication == 1)
// 			return (1);
// 		b_idx--;
// 	}
// 	return (0);
// }
// 		before_cpy();
// void before_cpy(void)
// {
// 	for (int i = 0; i < m; i++)
// 		before[before_idx].box[i] = ret[i];
// 	before_idx++;
// }

// void dfs(int idx)
// {
// 	if (idx == m)
// 	{
// 		if (no_condition(idx))
// 			return;
// 		print_ret();
// 		before_cpy();
// 		return;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		int double_check = double_box[n_box[i]];
// 		int idx_c = idx, conti = 0;
// 		while (idx_c-- > 0)
// 		{
// 			if (ret[idx_c - 1] == n_box[i])
// 			{
// 				if (double_check < 2)
// 				{
// 					conti = 1;
// 					break;
// 				}
// 				else
// 					double_check--;
// 			}
// 		}
// 		if (conti == 1)
// 			continue;
// 		ret[idx] = n_box[i];
// 		dfs(idx + 1);
// 	}
// }

// int main()
// {
// 	init();
// 	qsort(n_box, n, sizeof(int), compare);
// 	dfs(0);
// }
