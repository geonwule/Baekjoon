#include <stdio.h>

int main()
{
    int n, temp;
    int box[10001];

    for (int i = 0; i < 10001; i++)
        box[i] = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        box[temp] += 1;
    }
    for (int i = 1; i < 10001; i++)
    {
        if (box[i] == 0)
            continue ;
        for (int j = 0; j < box[i]; j++)
            printf("%d\n", i);
    }
}