#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
typedef struct s_arr
{
    char    num[20];
}   t_arr;

t_arr   arr[1000];

void    arr_init(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i].num);
}


int compare(const void *x, const void *y)
{
    char *a = (char *)x, *b = (char *)y;
    char st1[50];
    char st2[50];

    strncpy(st1, a, strlen(a));
    strncpy(st1 + strlen(a), b, strlen(b));
    strncpy(st2, b, strlen(b));
    strncpy(st2 + strlen(b), a, strlen(a));
    int len = strlen(st1);
    for (int i = 0; i < len; i++)
    {
        if (st1[i] > st2[i])
            return (1);
        else if (st1[i] < st2[i])
            return (0);
        else
            continue ;
    }
    return (0);
}

int visited[1000] = {0, };

void    ft_jeongrol(void)
{
    int big_idx;
    int com_idx;
    int first = 0;

    while (1)
    {
        big_idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == -1)
                continue ;
            if (big_idx == -1)
            {
                big_idx = j;
                continue ;
            }
            else
            {
                com_idx = j;
                if (!compare(arr[big_idx].num, arr[com_idx].num))
                    big_idx = com_idx;
            }
        }
        if (big_idx == -1)
            break ;
        if (first == 0 && arr[big_idx].num[0] == '0')
        {
            printf("0\n");
            return ;
        }
        else
            first = 1;
        printf("%s", arr[big_idx].num);
        visited[big_idx] = -1;
    }
    printf("\n");
}

int main()
{
    arr_init();
    ft_jeongrol();
}
