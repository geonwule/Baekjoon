#include <stdio.h>

int dp[30][30];

//key point
//dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + ... dp[i - 1][j - 1]
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 1; i < 30; i++)
    {
        for (int j = i; j < 30; j++)
        {
            if (i == 1)
                dp[i][j] = j;
            else if (i == j)
                dp[i][j] = 1;
            else
            {
                for (int k = i - 1; k < j; k++) // key point
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }   
    for (int i = 0; i < test; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}

// int combination(int a, int b)
// {
//     int ret = 1;
//     for (int i = 1; i <= b; i++)
//     {
//         ret *= a - i + 1;
//         ret /= i;
//     }
//     return (ret);
// }

// int dp[31][31];

// int main()
// {
//     int test;
//     scanf("%d", &test);
//     for (int i = 0; i < test; i++)
//     {
//         int a, b, dp[30];
//         scanf("%d %d", &a, &b);
//         printf("%d\n", combination(b, a));
//         // dp[a] = 1;
//         // for (int i = a + 1; i <= b; i++)
//         // {
//         //     dp[i] = dp[i - 1] + i - 1;
//         // }
//         // printf("%d\n", dp[b]);
//     }
// }