#include <stdio.h>

int main()
{
    int a, j, max = 0;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &a);
        if (max < a)
        {
            max = a;
            j = i + 1;
        }
    }
    printf("%d\n%d\n", max, j);
}