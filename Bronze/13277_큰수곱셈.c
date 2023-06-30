#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void    minuse_one(char *b, int b_len)
{
    b_len--;
    while (1)
    {
        if (b[b_len] > '0')
        {
            b[b_len] -= 1;
            return ;
        }
        if (b[b_len] == '0' && b_len > 0)
        {
            b[b_len] += 9;
            b_len--;
            continue ;
        }
    }
}

void    ret_pluse_a(char *r, char *a, int r_len, int a_len)
{
    char    *tmp = malloc(a_len + r_len);
    memset(tmp, '0', a_len + r_len);
    int i = 0;

    a_len--;
    r_len--;
    while(1)
    {
        if (a_len < 0 && r_len < 0)
            break ;
        if (a_len >= 0)
            tmp[i] += a[a_len--] - '0';
        if (r_len >= 0)
            tmp[i] += r[r_len--] - '0';
        if (tmp[i] > '9')
        {
            tmp[i] -= 10;
            tmp[i + 1] += 1;
        }
        i++;
    }
    memset(r, 0, 600002);
    if (tmp[i] == '0' || tmp[i] == 0)
        i--;
    for (int j = 0; i >= 0; j++)
    {
        r[j] = tmp[i];
        i--;
    }
    free(tmp);
}

int main()
{
    char *a = calloc(300001, sizeof(char));
    char *b = calloc(300001, sizeof(char));
    char *ret = calloc(600002, sizeof(char));

    char *o_b = b;
    scanf("%s %s", a, b);
    while (strcmp(b, "0") != 0)
    {
        ret_pluse_a(ret, a, strlen(ret), strlen(a));
        minuse_one(b, strlen(b));
        if (b[0] == '0' && strlen(b) > 1)
            b = &b[1];
    }
    printf("%s", ret);
    free(a);
    free(o_b);
    free(ret);
    return (0);
}