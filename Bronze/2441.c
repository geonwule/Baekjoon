#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                printf("*");
            else if (j <= i - 1)
            {
                printf(" ");
            }
            else
                printf("*");
        }
        printf("\n");
    }
    
}