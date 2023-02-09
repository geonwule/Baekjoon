#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    long long   k = 1, circle;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1\n");
        return (0);
    }
    for (long long i = 1; i <= LLONG_MAX; i++)
    {
        k += i * 6;
        if (n <= k)
        {
            circle = i;
            break ;
        }
    }
    printf("%lld\n", circle + 1);
}