#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// int box[4294967298] = {0 , };

//unsign max = 4294967295
//int max = 2147483647
int main()
{
    static int box[4294967298];
    int n, m, temp;
    unsigned int temp2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp < 0)
        {
            temp2 = temp * -1;
            temp2 += 2147483647;
            box[temp2] = 1;
        }
        else
            box[temp] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        if (temp < 0)
        {
            temp2 = temp * -1;
            temp2 += 2147483647;
            if (box[temp2] != 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else
        {
            if (box[temp] != 0)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}