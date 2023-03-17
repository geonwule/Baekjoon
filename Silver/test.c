#include <stdio.h>

int arr[3];
int dp[3];
int dp2[3];
int Min(int a, int b)
{
	return a < b ? a : b;
}
void distance_RGB(int N)
{
	int i;
	dp[0] = dp[1] = dp[2] = 0;
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		dp2[0] = dp[0];
		dp2[1] = dp[1];
		dp2[2] = dp[2];
		dp[0] = Min(dp2[1], dp2[2]) + arr[0];
		dp[1] = Min(dp2[0], dp2[2]) + arr[1];
		dp[2] = Min(dp2[0], dp2[1]) + arr[2];
	}
	int min = Min(Min(dp[0], dp[1]), dp[2]);
	printf("%d", min);
}
int main()
{
	int i;
	int N;
	scanf("%d", &N);
	distance_RGB(N);
}