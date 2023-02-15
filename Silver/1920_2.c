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

int search_go(int *box, int L, int R, int c)
{
    int left = L, right = R;
    int pivot = (left + right) / 2;
    if (box[pivot] == c)
        return (1);
    if (L+1 == R)
    {
        if (box[R] == c)
            return (1);
        else
            return (0);
    }
    if (box[pivot] < c)
    {
        return (search_go(box, pivot, right, c));
    }
    else if (box[pivot] > c)
    {
        return (search_go(box, left, pivot, c));
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
        if (search_go(box, 0, n - 1 , a))
            printf("1\n");
        else
            printf("0\n");
    }
}