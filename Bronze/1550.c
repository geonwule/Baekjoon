#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to(int n, int h)
{
    int ret = h;

    if (n == 0)
        return (ret);
    for (int i = 0; i < n; i++)
    {
        ret *= 16;
    }
    return (ret);
}

int hex_to_ten(char *n)
{
    int ret = 0;
    char    *hex = "0123456789ABCDEF";
    char    ten[100000] = {0, };
    int n_len = (int)strlen(n);
    int k = 0;

    for (int i = n_len - 1; i >= 0; i--)
    {
        for (int j = 0; j < 16; j++)
        {
            if (hex[j] == n[i])
            {
                ret += hex_to(k, j);
                break ;
            }
        }
        k++;
    }
    return (ret);
}

int main()
{
    char n[100000];

    scanf("%s", n);
    printf("%d\n", hex_to_ten(n));
}