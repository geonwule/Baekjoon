#include <stdio.h>

int main()
{
    int n, m, arr[100001], acc[100001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        acc[i] = acc[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", acc[b] - acc[a - 1]);
    }
}