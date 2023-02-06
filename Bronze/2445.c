#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    int max = n * 2 - 1;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (i >= n && (j >= (n * 2 - i - 1) && j <= i))
                printf(" ");
            else if (j <= i || j >= n * 2 - i - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}