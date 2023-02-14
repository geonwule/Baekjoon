#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int search_go(int *box, int box_len, int c)
{
    int n = box_len / 2;
    if (box_len == 1)
    {
        if (box[0] == c)
            return (1);
        else
            return (0);
    }
    if (box[n] == c)
        return (1);
    while (box[n] > c && n >= 0)
    {
        n--;
        if (box[n] == c)
            return (1);
        else if (box[n] < c)
            return (0);
    }
    while (box[n] < c && n < box_len)
    {
        n++;
        if (box[n] == c)
            return (1);
        else if (box[n] > c)
            return (0);
    }
    return (0);
}

int main()
{
    int n, m, a;
    scanf("%d", &n);
    int box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        box[i] = a;
    }
    qsort(box, n, sizeof(int), compare);
    scanf("%d", &m);
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &a);
        if (search_go(box, n, a))
            printf("1\n");
        else
            printf("0\n");
    }
}