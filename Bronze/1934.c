#include <stdio.h>

int minimum_multiple(int a, int b)
{
    int min;

    if (a == 1 || b == 1)
    {
        if (a == 1)
            return (b);
        else if (b == 1)
            return (a);
    }
    return (min);
}

int main()
{
    int n, a, b;
    int ret[1000] = {0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        ret[i] = minimum_multiple(a, b);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", ret[i]);
}