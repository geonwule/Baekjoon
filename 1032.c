#include <stdio.h>
#include <stdlib.h>

char    *ret_set(char **a)
{
    char    *ret;

    ret = a[0];
    for (int i = 1; a[i] != 0; i++)
    {
        for (int j = 0; a[i][j] != '\0'; j++)
        {
            if (ret[j] != a[i][j])
                ret[j] = '?';
        }
    }
    return (ret);
}

int main()
{
    int n;
    char *a[51];
    char *buf;
    int i = 0;

    scanf("%d", &n);
    while (i < n)
    {
        buf = (char *)malloc(sizeof(char) * (51));
        scanf("%s", buf);
        a[i] = buf;
        i++;
    }
    a[i] = 0;
    printf("%s\n", ret_set(a));
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
}