#include <stdio.h>
#include <stdlib.h>

int int_len(int *str)
{
    int i = 0;
    int len = 0;

    while (str[i] != 0)
    {
        len += str[i];
        i++;
    }
    return (len);
}

int int_n(int *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}

int str_last(int *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
        i++;
    i--;
    return (i);
}

int algori_str(int x, int *str)
{
    int ret;
    int i;
    int temp;

    while (int_len(str) > x)
    {
        i = str_last(str);
        temp = str[i] / 2;
        str[i] = temp;
        if (int_len(str) < x)
            str[i + 1] = temp;
    }
    ret = int_n(str);
    return (ret);
}

void str_set(int *str)
{
    int i = 0;

    while (i < 64)
    {
        str[i] = 0;
        i++;
    }
    str[0] = 64;
}

int main()
{
    int x;
    int str[65];

    str_set(str);
    scanf("%d", &x);
    printf("%d\n", algori_str(x, str));
}