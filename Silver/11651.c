#include <stdio.h>
#include <stdlib.h>

typedef struct s_box
{
    int x, y;
}   t_box;

t_box box[100000];

int compare_x(const void *a, const void *b)
{
    int x = ((t_box *)a)->x;
    int y = ((t_box *)b)->x;

    return (x - y);
}

int compare_y(const void *a, const void *b)
{
    int x = ((t_box *)a)->y;
    int y = ((t_box *)b)->y;

    return (x - y);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &box[i].x, &box[i].y);
    }
    qsort(box, n, sizeof(t_box), compare_x);
    qsort(box, n, sizeof(t_box), compare_y);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", box[i].x, box[i].y);
}