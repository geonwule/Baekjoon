#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
typedef struct s_arr
{
    char    num[20];
}   t_arr;

t_arr   *arr;

void    arr_init(void)
{
    arr = (t_arr *)malloc(sizeof(t_arr) * (1000));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        //arr[i].num = (char *)malloc(sizeof(char) * 20);
        scanf("%s", arr[i].num);
    }
}

void mal_free(char **arr)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
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
            return (-1);
        else if (st1[i] < st2[i])
            return (1);
        else
            continue ;
    }
    return (0);
}


int main()
{
    arr_init();
    qsort(arr, n, sizeof(arr[0]), compare);
    if (arr[0].num[0] == '0')
    {
        printf("0\n");
        return (0);
    }
    for (int i = 0; i < n; i++)
        printf("%s", arr[i].num);
    printf("\n");
}
