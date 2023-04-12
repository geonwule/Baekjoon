#include <stdio.h>

// 1 <= n <= 100
int n;
long long   dp[101];

long long   stair_num(int i)
{
    long long num = 0;
    int digit[i];
    for (int j = 0; j < i; j++)
    {
        
    }
}

int main()
{
    scanf("%d", &n);
    dp[1] = 9;
    dp[2] = 17;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = stair_num(3);
    }
}