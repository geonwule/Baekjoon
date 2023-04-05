#include <stdio.h>

int dp[1001];

// 1 <= n <= 1000
int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    for (int i = 5; i <= n; i++)
    {
        dp[i] = dp[i - 1] + i;
    }
    printf("%d\n", dp[n]);
}