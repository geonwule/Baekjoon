#include <stdio.h>

int main()
{
    int a, b;
    int arr[100][100];
    scanf("%d %d", &a, &b);
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                int t;
                scanf("%d", &t);
                arr[i][j] += t;
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d", arr[i][j]);
            if (j + 1 == b)
                printf("\n");
            else
                printf(" ");
        }
    }
}