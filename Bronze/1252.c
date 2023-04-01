#include <stdio.h>

int		a[80], b[80], ret[81] = {0, }, a_i = 0, b_i = 0, ret_i = 0;
#define A 1
#define B 2

void	input_init(void)
{
	char	t;
	int		a_or_b = A;

	while (1)
	{
		scanf("%c", &t);
		if (t == '\n')
			break ;
		if (t == ' ')
		{
			a_or_b = B;
			continue ;
		}
		if (a_or_b == A)
			a[a_i++] = t - '0';
		else
			b[b_i++] = t - '0';
	}
}

int	onlyzero(void)
{
	for (int i = 0; i < a_i; i++)
	{
		if (a[i] > 0)
			return (0);
	}
	for (int i = 0; i < b_i; i++)
	{
		if (b[i] > 0)
			return (0);
	}
	return (1);
}

void	a_plus_b(void)
{
	while (1)
	{
		if (a_i == 0 || b_i == 0)
			break ;
		ret[ret_i] += a[--a_i] + b[--b_i];
		if (ret[ret_i] >= 2)
		{
			ret[ret_i] -= 2;
			ret[ret_i + 1] += 1;
		}
		ret_i++;
	}
}

void	remain_plus(int *t, int t_i)
{
	while (t_i > 0)
	{
		ret[ret_i] += t[--t_i];
		if (ret[ret_i] >= 2)
		{
			ret[ret_i] -= 2;
			ret[ret_i + 1] += 1;
		}
		ret_i++;
	}
}

int	main(void)
{
	input_init();
	if (onlyzero())
	{
		printf("0\n");
		return 0;
	}
	a_plus_b();
	if (a_i > 0)
		remain_plus(a, a_i);
	if (b_i > 0)
		remain_plus(b, b_i);
	while (ret[ret_i] == 0)	// front zero delete
		ret_i--;
	while (ret_i >= 0)	// ret_print
		printf("%d", ret[ret_i--]);
}
