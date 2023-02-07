#include <stdio.h>

int main()
{
    int n, min, max, temp;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (i == 0) // max, min init
        {
            max = temp;
            min = temp;
            continue ;
        }
        if (max < temp)
            max = temp;
        if (min > temp)
            min = temp;
    }
    printf("%d %d\n", min, max);
}