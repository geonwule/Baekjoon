#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    int max = n*2 -1;
    int start = max / 2 + 1 - 1;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (j > start + (n - i - 1))
                break ;
            if (i == 0 || j == start || j >= start - (n - i - 1))
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}