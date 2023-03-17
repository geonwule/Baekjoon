#include <stdio.h>

int	Min(int a, int b){return (a < b ? a : b);}

int	dynamic(int n)
{
	int r, g, b;
	int rgb[4] = {0, 0, 0, 0}, dp[4];

	for (int i = 0; i < n; i++)
	{ 
		scanf("%d %d %d", &r, &g, &b);
		dp[1] = rgb[1];
		dp[2] = rgb[2];
		dp[3] = rgb[3];
		rgb[1] = Min(dp[2], dp[3]) + r;
		rgb[2] = Min(dp[1], dp[3]) + g;
		rgb[3] = Min(dp[1], dp[2]) + b;
	}
	if (Min(rgb[1], rgb[2]) == rgb[1] && Min(rgb[1], rgb[3]) == rgb[1])
		return (rgb[1]);
	else if (Min(rgb[2], rgb[3]) == rgb[2])
		return (rgb[2]);
	return (rgb[3]);
}

int main()
{
	int n;
	scanf ("%d", &n);
	printf("%d\n", dynamic(n));
}