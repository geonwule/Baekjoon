#include <stdio.h>
#include <stdlib.h>

void a_b_set(char *a, char *b, int *a_g, int *b_g)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'L')
            a_g[0]++;
        else if (a[i] == 'O')
            a_g[1]++;
        else if (a[i] == 'V')
            a_g[2]++;
        else if (a[i] == 'E')
            a_g[3]++;
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] == 'L')
            b_g[0]++;
        else if (b[i] == 'O')
            b_g[1]++;
        else if (b[i] == 'V')
            b_g[2]++;
        else if (b[i] == 'E')
            b_g[3]++;
    }
}

int gongsik(char *a, char *b, int *max, char *before, int i)
{
    char *love = "LOVE";
    int a_g[4] = {
        0,
    };
    int b_g[4] = {
        0,
    };
    int a_b_g[4];
    int ret = 0;
    a_b_set(a, b, a_g, b_g);
    for (int i = 0; i < 4; i++)
    {
        a_b_g[i] = a_g[i] + b_g[i];
    }
    ret = (a_b_g[0] + a_b_g[1]) * (a_b_g[0] + a_b_g[2]) * (a_b_g[0] + a_b_g[3]) * (a_b_g[1] + a_b_g[2]) * (a_b_g[1] + a_b_g[3]) * (a_b_g[2] + a_b_g[3]);
    ret %= 100;
    if (i == 0 || ret > *max)
    {
        *max = ret;
        return (1);
    }
    if (ret == *max)
    {
        int k;
        for (int i = 0; b[i] != '\0' && before[i] != '\0'; i++)
        {
            if (before[i] < b[i])
                return (0);
            if (b[i] < before[i])
            {
                *max = ret;
                return (1);
            }
            k = i + 1;
        }
        if (before[k] != '\0' && b[k] == '\0')
        {
            *max = ret;
            return (1);
        }
    }
    return (0);
}

int main()
{
    char name[30];
    int n;

    scanf("%s", name);
    scanf("%d", &n);

    char *temp;
    char *ret = NULL;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        temp = (char *)malloc(sizeof(char) * 30);
        scanf("%s", temp);
        if (gongsik(name, temp, &max, ret, i))
        {
            if (ret)
                free(ret);
            ret = temp;
        }
        else
            free(temp);
    }
    printf("%s\n", ret);
    free(ret);
}