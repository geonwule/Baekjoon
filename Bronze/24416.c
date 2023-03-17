#include <stdio.h>
int main()
{
	int n, dp[41] = {0, 1, 1};
	scanf ("%d", &n);
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i-2] + dp[i - 1];
	printf("%d %d\n", dp[n], n - 2);
}