#include <stdio.h>
#define N_MAX 100
#define K_MAX 10000

int dp[N_MAX + 1] = {0, };
int	dynamic(int n, int k)
{
	int ret = 0, temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		
	}
	return (ret);
}

int main()
{
	int n, k;
	scanf ("%d %d", &n, &k);
	printf("%d\n", dynamic(n, k));
}