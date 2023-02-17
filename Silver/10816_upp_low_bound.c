#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int lower_bound(int *box, int L, int R, int key)
{
    int lower_bound = 0, left = L, right = R;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (box[mid] >= key)
        {
            lower_bound = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return (lower_bound);
}

int upper_bound(int *box, int L, int R, int key)
{
    int upper_bound = -1, left = L, right = R;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (box[mid] <= key)
        {
            upper_bound = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    if (upper_bound == -1 || (upper_bound == R && box[R] != key))
        return (0);
    upper_bound += 1;
    return (upper_bound);
}

int main()
{
    int n, m, temp, lower, upper;
    scanf("%d", &n);
    int box[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &box[i]);
    qsort(box, n, sizeof(int), compare);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        upper = upper_bound(box, 0, n - 1, temp);
        lower = lower_bound(box, 0, n - 1, temp);
        printf("%d", upper - lower);
        if (i + 1 == m) // input end
            printf("\n");
        else
            printf(" ");
    }
}
