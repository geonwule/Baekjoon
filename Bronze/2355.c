#include <stdio.h>
#include <stdlib.h>

long long sigma(long long a)
{
	long long ret, flag = 1;
	if (a == 0)
		return (0);
	if (a < 0)
	{
		flag *= -1;
		a *= -1;
	}
	ret = a * (a + 1) / 2 * flag;
	return (ret);
}

int	main(void)
{
	long long a, b, sum = 0;
	scanf("%lld %lld", &a, &b);
	if (a == b)
	{
		printf("%lld\n", a);
		return (0);
	}
	if (a >= 0 && b >= 0 || a <= 0 && b <= 0)
	{
		if (llabs(a) > llabs(b))
			sum = sigma(a) - sigma(b) + b;
		else
			sum = sigma(b) - sigma(a) + a;
	}
	else if (a > 0 && b < 0 || a < 0 && b > 0)
		sum = sigma(a) + sigma(b);
	printf("%lld\n", sum);
}

/*

int	ft_abs(long long a, long long b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	return (0);
}

if (a == 0 && b == 0)
		sum = 0;
	else if (a == 0)
	{
		if (b < 0)
			sum = (b * (b - 1)) / 2 * (-1);
		else
			sum = (b * (b + 1)) / 2;
	}
	else if (b == 0)
	{
		if (a < 0)
			sum = (a * (a - 1)) / 2 * (-1);
		else
			sum = (a * (a + 1)) / 2;
	}
	else if (a > 0 && b > 0)
	{
		if (flag == -1)
			sum = a;
		else if (flag == 1)
		{
			b--;
			sum = (a * (a + 1)) / 2 - (b * (b + 1)) / 2;
		}
		else
		{
			a--;
			sum = (b * (b + 1)) / 2 - (a * (a + 1)) / 2;
		}
	}
	else if (a < 0 && b < 0)
	{
		if (flag == -1)
			sum = a;
		else if (flag == 1)
		{
			b++;
			sum = (a * (a - 1)) / 2 - (b * (b - 1)) / 2;
		}
		else
		{
			a++;
			sum = (b * (b - 1)) / 2 - (a * (a - 1)) / 2;
		}
		sum *= -1;
	}
	else if (a > 0 && b < 0 || a < 0 && b > 0)
	{
		if (flag == -1)
			sum = 0;
		else
			sum = (b * (b + 1)) / 2 + (a * (a + 1)) / 2;
		if (flag == 1 && a < 0 || flag == 0 && b < 0)
			sum *= -1;
	}
*/