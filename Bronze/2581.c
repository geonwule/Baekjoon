#include <stdio.h>

int n, m;

int is_prime(int i)
{
    if (i == 1)
        return (0);
    if (i == 2 || i == 3 || i == 5)
        return (1);
    int root;
    for (root = 1; root * root <= i; root++);
    root++;
    for (int j = 2; j <= root; j++)
    {
        if (i % j == 0)
            return (0);
    }
    return (1);
}

int main()
{
    int sum = 0, min = 20000;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        if (is_prime(i))
        {
            sum += i;
            if (min > i)
                min = i;
        }
    }
    if (min == 20000)
    {
        printf("-1\n");
    }
    else
        printf("%d\n%d\n", sum, min);
}