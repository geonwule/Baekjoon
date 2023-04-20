#include <stdio.h>

int *temp_set(void)
{
    int *temp;

    temp = (int *)malloc(sizeof(int) * 2002);
    for (int i = 0; i < 2002; i++)
    {
        temp[i] = 0;
    }
    return (temp);
}

int *a_multip_b(int *a, int *b, int a_len, int b_len)
{
    int *c = temp_set();
    int *ret = temp_set(), ret_i = 0;
    int max;

    for (int i = 0; i < a_len; i++)
    {
        for (int j = 0; j < b_len; j++)
        {
            c[i + j] += a[a_len - i - 1] * b[b_len - j - 1];
            max = i + j;
        }
    }
    for (int i = 0; i < 2002; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    int k = 2001;
    while (c[k] == 0)
        k--;
    max = k;
    for (int i = max; i >= 0; i--)
    {
        ret[ret_i++] = c[i];
    }
    free(c);
    return (ret);
}

unsigned long long   combination(int *a, int *b)
{
    int r_a = atoi((char *)a), r_b = atoi((char *)b);
    unsigned long long   ret = 1;
    unsigned long long   child = 1, parent = 1;
    for (int i = 0; i < b; i++)
    {
        unsigned long long x = 1, y = 1; 
        x *= (a - i);
        y *= (i + 1);
        if (x % y == 0)
            ret *= x / y;
        else
        {
            child *= x;
            parent *= y;
        }
    }
    ret *= child;
    ret /= parent;
    return (ret);
}

#include <limits.h>
#include <gmp.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == -1)
    {
        printf("ULLONG MAX = %llu\n", ULLONG_MAX);
        return (0);
    }
    printf("%llu\n", combination(a, b));
}