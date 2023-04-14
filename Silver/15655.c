#include <stdio.h>
#include <stdlib.h>

int n, m, n_box[8], ret[8];

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;
    return (a - b);
}

void    input_set(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &n_box[i]);
    qsort(n_box, n, sizeof(int), compare);
}

int duplicate(int level, int point)
{
    if (level == 0)
        return (0);
    while (--level >= 0)
    {
        if (ret[level] == point)
            return (1);
    }
    return (0);
}

void    back_tracking(int level, int idx)
{
    if (level == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d", ret[i]);
            if (i + 1 == m)
                printf("\n");
            else
                printf(" ");
        }
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        // if (duplicate(level, n_box[i]))
        //     continue ;
        ret[level] = n_box[i];
        back_tracking(level + 1, i + 1);
    }
}

int main()
{
    input_set();
    back_tracking(0, 0);
}