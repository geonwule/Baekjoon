#include <stdio.h>

long long	fibo_simiral(int n)
{
	long long	dp[117] = {0, 1, 1, 1};
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i-1] + dp[i-3];
	return (dp[n]);
}

int main()
{
	int n;
	scanf ("%d", &n);
	printf("%lld\n", fibo_simiral(n));
}