#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(unsigned long long n);

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

int big_plus_small(int *a, int *b, int a_len, int b_len, int *c)
{
    int i = 0;
    while (i < a_len)
    {
        if (i < b_len)
        {
            c[i] += a[a_len - i - 1] + b[b_len - i - 1];
            i++;
        }
        else
        {
            c[i] += a[a_len - i - 1];
            i++;
        }
    }
    for (int j = 0; j < 2002; j++)
    {
        c[j + 1] += c[j] / 10;
        c[j] %= 10;
    }
    i = 2001;
    while (c[i] == 0)
        i--;
    return (i);
}

int a_plus_b(int *ret, int *a, int *b, int a_len, int b_len)
{
    int *temp = temp_set();
    int i = 0;
    int j = 0;
    int max;

    if (a == NULL)
    {
        for (int i = 0; i < b_len; i++)
            ret[i] = b[i];
        free(b);
        return (b_len);
    }
    if (a_len >= b_len)
        max = big_plus_small(a, b, a_len, b_len, temp);
    else if (a_len < b_len)
        max = big_plus_small(b, a, b_len, a_len, temp);
    j = 0;
    for (i = max; i >= 0; i--)
    {
        ret[j] = temp[i];
        j++;
    }
    if (a)
        free(a);
    free(b);
    return (max + 1);
}

int *a_multip_b(int *a, int *b, int a_len, int b_len, int *c_len)
{
    int *c = temp_set();
    int *ret = temp_set();
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
    int k = 2001, j = 0;
    while (c[k] == 0)
        k--;
    max = k;
    for (int i = max; i >= 0; i--)
    {
        ret[j] = c[i];
        j++;
    }
    *c_len = j;
    free(a);
    free(b);
    free(c);
    return (ret);
}

int string_to_int(unsigned long long z, int *box)
{
    char *temp = ft_itoa(z);
    int box_len = 0;
    int i, j;

    while (temp[box_len] != '\0')
        box_len++;
    i = 0;
    j = 0;
    if (temp[0] == '-')
    {
        box[0] = (temp[1] - '0') * -1;
        box_len--;
        i++;
        j = i + 1;
    }
    while (j < 2002)
    {
        box[i] = temp[j] - '0';
        i++;
        j++;
    }
    return (box_len);
}

static int digit_check(unsigned long long n)
{
    int cnt;

    cnt = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return (cnt);
}

static void insert_int(char *ret, unsigned long long n, int len)
{
    len--;
    while (len >= 0)
    {
        ret[len] = n % 10 + '0';
        n /= 10;
        len--;
    }
}

char *ft_itoa(unsigned long long n)
{
    char *ret;
    int ret_len;

    if (n < 0)
        ret_len = digit_check(-n) + 1;
    else
        ret_len = digit_check(n);
    ret = (char *)malloc(sizeof(char) * ret_len + 1);
    if (ret == NULL)
        return (0);
    ret[ret_len] = '\0';
    if (n < 0)
    {
        ret[0] = '-';
        insert_int(ret + 1, -n, ret_len - 1);
    }
    else
        insert_int(ret, n, ret_len);
    return (ret);
}

unsigned long long jegob_31(int a)
{
    unsigned long long ret = 1;
    for (int i = 0; i < a; i++)
    {
        ret *= 31;
    }
    return (ret);
}

int abcde_put(char c)
{
    int i = c - 96;
    return (i);
}

int main()
{
    int n, a_len, b_len, c_len, ret_len;
    int *a, *b, *ret = NULL, *new_ret;

    scanf("%d", &n);
    char str[n + 1];
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        a = temp_set();
        b = temp_set();
        new_ret = temp_set();
        a_len = string_to_int(abcde_put(str[i]), a);
        b_len = string_to_int(jegob_31(i), b);
        ret_len = a_plus_b(new_ret, ret, a_multip_b(a, b, a_len, b_len, &c_len), ret_len, c_len);
        ret = new_ret;
    }
    for (int i = 0; i < ret_len; i++)
    {
        printf("%d", ret[i]);
    }
    printf("\n");
    free(ret);
    system("leaks a.out");
}