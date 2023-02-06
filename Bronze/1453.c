#include <stdio.h>
#include <stdlib.h>

int double_check(int *box, int t, int max)
{
    for (int i = 0; i < max; i++)
    {
        if (box[i] == t)
            return (1);
    }
    return (0);
}

int main()
{
    int n;
    scanf("%d", &n);
    int temp;
    int *box;
    int ret = 0;

    box = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) // init
        box[i] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        box[i] = temp;
        ret += double_check(box, temp, i);
    }
    printf("%d\n", ret);
    free(box);
}