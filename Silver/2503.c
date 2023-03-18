#include <stdio.h>
#include <string.h>

// 브루트포스 알고리즘
// 숫자야구

// 브루트포스 이므로 전체를 경우의 수를 생각해서 답변을 해줄때마다 안되는 경우의 수를 빼보자.

int	zero(int n)
{
	for (int i = 0; i < 2; i++)
	{
		if (n % 10 == 0)
			return (1);
		n /= 10;
	}
	return (0);
}

int	duplicate(int first, int second, int third)
{
	if (first == second || second == third || third == first)
		return (1);
	return (0);
}

typedef struct s_vars
{
	char	num[4];
	int		strike;
	int		ball;
}			t_vars;
t_vars		var[101];

int	strike_count(int f, int s, int t, int i)
{
	int st_cnt = 0;

	int first = var[i].num[0] - '0',
		second = var[i].num[1] - '0', third = var[i].num[2] - '0';
	if (f == first)
		st_cnt++;
	if (s == second)
		st_cnt++;
	if (t == third)
		st_cnt++;
	return (st_cnt);
}

int	ball_count(int f, int s, int t, int i)
{
	int ball_cnt = 0;

	int first = var[i].num[0] - '0',
		second = var[i].num[1] - '0', third = var[i].num[2] - '0';
	if (f == second || f == third)
		ball_cnt++;
	if (s == first || s == third)
		ball_cnt++;
	if (t == first || t == second)
		ball_cnt++;
	return (ball_cnt);
}

int	not_enough(int f, int s, int t, int n)
{
	int	strike_cnt, ball_cnt, strike, ball;

	for (int i = 1; i <= n; i++)
	{
		strike = var[i].strike, ball = var[i].ball;
		strike_cnt = strike_count(f, s, t, i);
		ball_cnt = ball_count(f, s, t, i);
		if (strike_cnt != strike)
			return (1);
		if (ball_cnt != ball)
			return (1);
	}
	return (0);
}

int	var_init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %d %d", var[i].num, &var[i].strike, &var[i].ball);
		if (var[i].strike == 3)
		{
			printf("1\n"); // only 1
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	int n, ret = 0;
	scanf("%d", &n);
	if (!var_init(n))
		return (0);
	for (int i = 123; i <= 987; i++)
	{
		int first = i / 100;
		int second = (i % 100) / 10;
		int third = i % 10;
		if (zero(i) || duplicate(first, second, third))
			continue ;
		if (not_enough(first, second, third, n))
			continue ;
		ret++;
	}
	printf("%d\n", ret);
}