#include <stdio.h>

int three_devide(int *x)
{
    if (*x % 3 == 0)
    {
        *x /= 3;
        return (1);
    }
    return (0);
}

int two_devide(int *x)
{
    if (*x % 2 == 0)
    {
        *x /= 2;
        return (1);
    }
    return (0);
}

void one_minus(int *x)
{
    *x -= 1;
}

void recul(int *n, int *cnt, int *min)
{
    int ori_n = *n, ori_cnt = *cnt;
    if (*n < 1)
        return;
    if (*n == 1)
    {
        if (*min > *cnt)
            *min = *cnt;
        return;
    }
    if (three_devide(n))
    {
        *cnt += 1;
        recul(n, cnt, min);
        *n = ori_n;
        *cnt = ori_cnt;
    }
    if (two_devide(n))
    {
        *cnt += 1;
        recul(n, cnt, min);
        *n = ori_n;
        *cnt = ori_cnt;
    }
    one_minus(n);
    *cnt += 1;
    recul(n, cnt, min);
}
int dp[1000001];

int main()
{
    int n, min;
    scanf("%d", &n); // 1 <= n <= 1000000
    if (n == 1) // 1이 들어온경우 예외처리
    {
        printf("0\n");
        return (0);
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= n; i++)
    {
        if (i % 2 != 0 && i % 3 != 0) // 둘다 안될때 무조건 마이너스
            dp[i] = dp[i - 1] + 1;
        else if (i % 2 == 0 && i % 3 ==0) // 둘다 될때
        {
            int a = dp[i / 2] + 1;
            int b = dp[i / 3] + 1;
            int c = dp[i - 1] + 1;
            if (a > b)
                a = b;
            if (a > c)
                a = c;
            dp[i] = a;
        }
        else if (i % 2 == 0) // 2만 될때
        {
            if (dp[i / 2] + 1 < dp[i - 1] + 1)
                dp[i] = dp[i / 2] + 1;
            else
                dp[i] = dp[i - 1] + 1;
        }
        else if (i % 3 == 0) // 3만 될때
        {
            if (dp[i / 3] + 1 < dp[i - 1] + 1)
                dp[i] = dp[i / 3] + 1;
            else
                dp[i] = dp[i - 1] + 1;
        }
    }
    printf("%d\n", dp[n]);
}