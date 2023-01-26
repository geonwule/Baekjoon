#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main()
{
    int n, i, j;

    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (j >= n - i - 1)
                printf("*");
            else
                printf(" ");
            j++;
        }
        printf("\n");
        i++;
    }
}
*/

char    *star_insert(int idx, int len)
{
    char    *ret;
    int     point = len - idx;

    ret = (char *)malloc(sizeof(char) * (len + 1));
    if (ret == NULL)
        return (0);
    ret[len] = '\0';
    len--;
    while (len >= 0)
    {
        if (len >= point)
            ret[len] = '*';
        else
            ret[len] = ' ';
        len--;
    }
	return (ret);
}

void    print_star(char **ret)
{
    int i = 0;

    while (ret[i] != NULL)
    {
        printf("%s\n", ret[i]);
        i++;
    }
}

void    malloc_free(char **ret)
{
    int i = 0;

    while (ret[i] != NULL)
    {
        free(ret[i]);
        i++;
    }
    free(ret);
}

int main()
{
    int n;
    char    **ret;
    int     ret_len;

    scanf("%d", &n);
    ret_len = n;
    ret = (char **)malloc(sizeof(char *) * (ret_len + 1));
    if (ret == NULL)
        return (0);
    ret[ret_len] = NULL;
    for (int i = 0; i < ret_len; i++)
    {
        ret[i] = star_insert(i + 1, ret_len);
    }
    print_star(ret);
    malloc_free(ret);
    system("leaks a.out");
    return (0);
}
