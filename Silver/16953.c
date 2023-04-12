#include <stdio.h>
#include <limits.h>

long long real_ret = LLONG_MAX;

void bfs(long long ret, long long a, long long b)
{
    if (a > b)
        return;
    if (a == b && real_ret > ret)
    {
        real_ret = ret;
        return;
    }
    bfs(ret + 1, a * 10 + 1, b);
    bfs(ret + 1, a * 2, b);
}

int main()
{
    long long x, y;
    scanf ("%lld %lld", &x, &y);
    bfs(0, x, y);
    if (real_ret == LLONG_MAX)
    {
        printf("-1\n");
        return (0);
    }
    printf("%lld\n", real_ret + 1);
}

// b를 a로 맞추는 작업
// int main()
// {
//     long long a, b;
//     scanf ("%lld %lld", &a, &b);
//     int ret = 1;
//     while (a != b)
//     {
//         if (b % 10 == 1 && b > a)
//             b /= 10;
//         else if (b % 2 == 0 && b > a)
//             b /= 2;
//         else
//         {
//             ret = -1;
//             break ;
//         }
//         ret++;
//     }
//     printf("%d\n", ret);
// }