#include <stdio.h>

int prime_check(int t)
{
    int root = 0;

    if (t == 1)
        return (0);
    if (t == 2 || t == 3 || t == 5 || t == 7)
        return (1);
    for (root = 0; root * root <= t; root++);
    root--;
    for (int i = 2; i <= root; i++)
    {
        if (t % i == 0)
            return (0);
    }
    return (1);
}

int main()
{
    int n, ret = 0, temp;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (prime_check(temp))
            ret++;
    }
    printf("%d\n", ret);
}