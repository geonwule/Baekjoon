#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int x;
    int y;
} t_list;

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    else if (*(int *)a < *(int *)b)
        return (-1);
    return (0);
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    t_list box[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &box[i].y, &box[i].x);
    qsort(box, n, sizeof(t_list), compare);
    for (int i = 0; i < n; i++)
    {
        temp = box[i].y;
        box[i].y = box[i].x;
        box[i].x = temp;
    }
    qsort(box, n, sizeof(t_list), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", box[i].x, box[i].y);
    }
}