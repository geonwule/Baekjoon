#include <stdio.h>

int min_gongbae(int a, int b)
{
    int i = 2, j = 2, or_a = a, or_b = b;

    while (a != b)
    {
        if (a < b)
        {
            a = or_a * i;
            i++;
        }
        else
        {
            b = or_b * j;
            j++;
        }
    }
    return (a);
}

int max_gongyak(int a, int b)
{
    int max = 1, or_a = a, or_b = b;

    for (int i = 2; i <= or_a && i <= or_b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
            max *= i;
            i = 1;
        }
    }
    return (max);
}

int main()
{
    int a, b, min, max;
    scanf("%d %d", &a, &b);

    if (a == b)
    {
        printf("%d\n%d\n", a, a);
        return (0);
    }
    max = max_gongyak(a, b);
    min = min_gongbae(a, b);
    printf("%d\n%d\n", max, min);
}