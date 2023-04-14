#include <stdio.h>

int n, m, ret[8];

void    input_set(void)
{
    scanf("%d %d", &n, &m);
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
    for (int i = 1; i <= n; i++)
    {
        // if (duplicate(level, i))
        //     continue ;
        ret[level] = i;
        back_tracking(level + 1, i + 1);
    }
}

int main()
{
    input_set();
    back_tracking(0, 1);
}