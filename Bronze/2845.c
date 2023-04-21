#include <stdio.h>

int main()
{
    int people, area;
    scanf("%d %d", &people, &area);
    int real = people * area;
    for (int i = 0; i < 5; i++)
    {
        int t;
        scanf("%d", &t);
        printf("%d", t - real);
        if (i + 1 == 5)
            printf("\n");
        else
            printf(" ");
    }
}