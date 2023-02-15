#include <stdio.h>
#include <stdlib.h>

int box[2000002] = {0, };

int main()
{
    int n, t;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t < 0)
        {
            t *= -1;
            t += 1000000;
        }
        box[t] = 1;
    }
    for (int i = 2000000; i >= 1000001; i--)
    {
        if (box[i] != 0)
        {
            printf("%d\n", ((i - 1000000) * (-1)));
        }
    }
    for (int i = 0; i <= 1000000; i++)
    {
        if (box[i] != 0)
            printf("%d\n", i);
    }
}