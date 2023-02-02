#include <stdio.h>
#include <stdlib.h>

int **box_set(int m)
{
    int n1, n2;
    int **box;

    box = (int **)malloc(sizeof(int *) * m);
    if (box == NULL)
        return (0);
    for (int i = 0; i < m; i++)
    {
        box[i] = (int *)malloc(sizeof(int) * 2);
        if (box[i] == NULL)
            return (0);
        scanf("%d %d", &n1, &n2);
        box[i][0] = n1;
        box[i][1] = n2;
    }
    return (box);
}

int *ret_set2(int ret, int flag, int b, int m, int **box, int *fr)
{
    int *ret_set;

    ret_set = (int *)malloc(sizeof(int) * 3);
    int success = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (box[i][0] == flag && box[i][1] == b
             || box[i][1] == flag && box[i][0] == b)
            {
                success = 1;
                ret_set[0] = ret + 1;
                ret_set[1] = success;
                ret_set[2] = 0;
                return (ret_set);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (box[i][1] == flag)
            {
                flag = box[i][0];
            }
        }
    }
    ret_set[0] = ret + 1;
    ret_set[1] = success;
    ret_set[2] = flag;
    if (fr)
        free(fr);
    return (ret_set);
}

int ret_set(int n, int a, int b, int m, int **box)
{
    int ret = 0;
    int *ret_set = NULL;
    int success = 0;
    int flag = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (box[i][0] == a && box[i][1] == b)
                return (1);
            if (box[i][1] == a && box[i][0] == b)
                return (1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (box[i][1] == a)
            {
                flag = box[i][0];
                ret = 1;
                //break;
            }
        }
    }
    if (flag == 0)
        return (-1);
    for (int i = 0; i < n; i++)
    {
        ret_set = ret_set2(ret, flag, b, m, box, ret_set);
        success = ret_set[1];
        ret = ret_set[0];
        flag = ret_set[2];
        if (success == 1)
            break ;
    }
    if (ret_set)
        free(ret_set);
    if (success == 0)
        return (-1);
    return (ret);
}

int main()
{
    int n, a, b, m;
    int **box;
    int ret;

    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    box = box_set(m);
    ret = ret_set(n, a, b, m, box);
    printf("%d\n", ret);
    // system("leaks a.out");
}

    // printf("\n");
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d %d\n", box[i][0], box[i][1]);
    // }