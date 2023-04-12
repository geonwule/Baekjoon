#include <stdio.h>
#include <limits.h>

double	power_recul(double x, int n)
{
	if (n == 0)
		return (1.0);
	double half = power_recul(x, n / 2);
	if (n % 2 == 0)
		return (half * half);
	else if (n > 0)
		return (half * half * x);
	else
		return (half * half / x);
}

double	power(double x, int n)
{
	double result = 1.0;
	while (n)
	{
		if (n % 2 == 1)
			result *= x;
		x *= x;
		n /= 2;
	}
	return (result);
}

int main()
{
	double	x =  2.0;
	int n = 10;
	double result = power(x, n);
	printf("%f to the power of %d is %f\n", x, n, result);
}