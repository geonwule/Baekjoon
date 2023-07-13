#include <stdio.h>
#include <string.h>

typedef unsigned long long  ms;

ms  dp[100001];
char    ret[10001] = {0 , };
int i = 0;

int main()
{
    ms  n;
    scanf("%llu", &n);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    while (i >= 0)
    {
        printf("%c",ret[i]);
        i--;
    }
}