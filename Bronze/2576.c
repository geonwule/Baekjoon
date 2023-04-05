#include <stdio.h>

int main()
{
    int a, sum = 0, min = 101;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &a);
        if (a % 2 != 0)
        {
            sum += a;
            if (min > a)
                min = a;
        }
    }
    if (sum == 0)
        printf("-1\n");
    else
    {
        printf("%d\n%d\n", sum, min);
    }
}