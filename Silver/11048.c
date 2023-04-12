#include <stdio.h>

// 1<= n, m <= 1000
int n, m, miro[1001][1001], candy[1001][1001];

int com(int a, int b)
{
    return ((a > b) ? a : b);
}
int dp[1001];

void    input_init(void)
{
    scanf("%d %d", &n, &m);
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            scanf("%d", &miro[y][x]);
            if (x > 1)
                dp[x] = miro[y][x] + com(dp[x - 1], dp[x]);
            else
                dp[x] += miro[y][x];
            
        }
    }

}

void    candy_set(void)
{
    candy[1][1] = miro[1][1];
    for (int x = 2; x <= m; x++)    // first x set
        candy[1][x] = candy[1][x - 1] + miro[1][x];
    for (int y = 2; y <= n; y++)    // first y set
        candy[y][1] = candy[y - 1][1] + miro[y][1];
    for (int y = 2; y <= n; y++)
    {
        for (int x = 2; x <= m; x++)
        {
            int max = candy[y][x - 1];
            if (max < candy[y - 1][x])
                max = candy[y - 1][x];
            if (max < candy[y - 1][x - 1])
                max = candy[y - 1][x - 1];
            candy[y][x] = miro[y][x] + max;
        }
    }
}

int main()
{
    input_init();
//    candy_set();
    printf("%d\n", dp[m]);
//    printf("%d\n", candy[n][m]);
}