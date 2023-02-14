#include <stdio.h>

int ret_set(int n, int k)
{
    int a = 1, b = 1, c = 1;
    for (int i = 1; i <= n; i++)
        a *= i;
    for (int i = 1; i <= k; i++)
        b *= i;
    for (int i = 1; i <= n-k; i++)
        c *= i;
    return (a / (b * c));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", ret_set(n, k));
}