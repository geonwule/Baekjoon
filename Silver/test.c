#include <stdio.h>
#include <stdlib.h>

long long	hash(char *s)
{
	long long	a = 0;
	for (int i = 0; s[i] != '\0'; i++)
		a += (i + 1) * (s[i]);
	return (a);
}

int	prime_go(int n)
{
	int root, prime;

	if (n == 1 || n == 2 || n == 3)
		return n;
	for (int i = 2; i < n; i++)
	{
		if (i * i == n)
		{
			root = i;
			break ;
		}
		if (i * i > n)
		{
			root = i + 1;
			break ;
		}
	}
	for (int i = 2; i <= root; i++)
	{
		if (n % i == 0)
			continue ;
	}
}

int main()
{
	int n, sosu;
	scanf("%d", &n);
	sosu = prime_go(n);
}
