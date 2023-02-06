#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    int max = n * 2 - 1;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= n && j >= (2 * n - i - 1))
                break ;
            else if (j <= i)
                printf("*");
            else
                break ;
        }
        printf("\n");
    }
}