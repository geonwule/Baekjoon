#include <stdio.h>
#include <math.h>

int dp[50001];

int main()
{
	int n;
	scanf ("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 4;
		for (int j = 1; j * j <= i; j++) // j <= sqrt(i); j++)
		{
			if (dp[i - j*j] + 1 < dp[i])
				dp[i] = dp[i - j * j] + 1;
		}
	}
	printf("%d\n", dp[n]);
}