#include <stdio.h>

int main()
{
    int n, x, j;
    char order[6];
    scanf("%d", &n);
    int box[n];
    j = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", order);
        if (order[0] == 'p')
        {
            if (order[1] == 'u')
            {
                scanf("%d", &x);
                box[j] = x;
                j++;
            }
            else if (order[1] == 'o')
            {
                if (j == 0)
                    printf("-1\n");
                else if (j != 0)
                {
                    j--;
                    printf("%d\n", box[j]);
                    box[j] = 0;
                }
            }
        }
        else if (order[0] == 's')
        {
            printf("%d\n", j);
        }
        else if(order[0] == 'e')
        {
            if (j != 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else if(order[0] == 't')
        {
            if (j == 0)
                printf("-1\n");
            else
                printf("%d\n", box[j-1]);
        }
    }
}