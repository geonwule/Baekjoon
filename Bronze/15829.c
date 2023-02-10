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
    for (int j = 0; j < 2001; j++)
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
        free(temp);
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
    free(temp);
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
    for (int i = 0; i < 2001; i++)
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
    while (i < 2002)
    {
        if (j < box_len)
        {
            box[i] = temp[j] - '0';
            j++;
        }
        else
            box[i] = 0;
        i++;
    }
    free(temp);
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

int *ret_set(int *new_ret, int ret_len)
{
    int *ret = temp_set();
    for (int i = 0; i < ret_len; i++)
    {
        ret[i] = new_ret[i];
    }
    if (new_ret)
        free(new_ret);
    return (ret);
}

void m_set(int *m)
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            m[i] = 1;
        else
            m[i] = i + 1;
    }
}

int abs_m_set(int *a, int *b, int a_len, int b_len)
{
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] > b[i])
            return (1);
        else if (a[i] < b[i])
            return (0);
    }
    return (2); // abs (a == b)
}

int ret_m_comp(int *a, int a_len, int *b, int b_len, int *flag)
{
    int ret;

    if (b_len > a_len)
        return (0);
    else if (b_len < a_len)
        return (1);
    ret = abs_m_set(a, b, a_len, b_len);
    if (ret == 2)
    {
        *flag = -1;
        return (0);
    }
    return (ret);
}

int abs_set(int *a, int *b, int a_len, int b_len)
{
    if (a_len > b_len)
        return (3);
    else if (a_len < b_len)
        return (2);
    if (a_len == b_len)
    {
        for (int i = 0; i < a_len; i++)
        {
            if (a[i] > b[i])
                return (3);
            else if (a[i] < b[i])
                return (2);
        }
        return (1); // abs (a == b)
    }
    return (0);
}

int a_abs_comp_b(int *a, int *b, int a_len, int b_len) // a > 0 , b < 0
{
    if (abs_set(a, b, a_len, b_len) == 1) // abs(a) == abs(b)
    {
        printf("0\n");
        free(a);
        return(0);
    }
    if (abs_set(a, b, a_len, b_len) == 2) // abs(a) < abs(b)
        return (-1);
    return (1);  // abs(a) >= abs(b)
}

int a_minus_b(int *a, int *b, int a_len, int b_len, int *new_a) // abs(a) >= abs(b)
{
    int *temp = temp_set();
    int i = 0, j;
    while (i < a_len)
    {
        if (i < b_len)
        {
            temp[i] += a[a_len - i - 1] - b[b_len - i - 1];
            i++;
        }
        else
        {
            temp[i] += a[a_len -i - 1];
            i++;
        }
    }
    for (int j = 0; j < 2001; j++)
    {
        while (temp[j] < 0)
        {
            temp[j] += 10;
            temp[j + 1] -= 1;
        }
    }
    i = 2001;
    while (temp[i] == 0)
        i--;
    j = 0;
    for (int k = i; k >= 0; k--)
    {
        new_a[j] = temp[k];
        j++;
    }
    free(a);
    free(temp);
    return (j);
}

// while ( 1 )
// a -= b ;
// if (a < b)
//  break ;

// ex 300 % 100
// if (a[0] == 0)
//  printf("0\n");
// else
//  printf("a");

//return new_a_len;
int *ret_mod_comp(int *a, int a_len, int *b, int b_len, int *new_a_len)
{
    int comp, new_b_len, old_b_len, i = 2;
    int *temp_a, *new_a = a, *new_b, *old_b;
    
    *new_a_len = a_len;

    while (1)
    {
        comp = a_abs_comp_b(new_a, b, *new_a_len, b_len);
        while (comp != 0 || comp != -1)
        {
            new_b = a_multip_i(b, b_len, i, &new_b_len);
            comp = a_abs_comp_b(new_a, new_b, *new_a_len, new_b_len);
            i++;
        }
        if (i != 0)
        {
            free(new_b);
            old_b = a_multiple_i(b, b_len, i-2, &old_b_len);
            comp = 
        }
        if (comp == 0)
            return (0);
        if (comp == -1)
            break ;
        temp_a = temp_set();
        *new_a_len = a_minus_b(new_a, b, *new_a_len, b_len, temp_a);
        new_a = ret_set(temp_a, *new_a_len);
    }
    return (new_a);
}
int    *main2(int n, char *str, int *ret_len)
{
    int *a, *b, *c, *new_ret, *ret = NULL;
    int a_len, b_len, c_len;
    for (int i = 0; i < n; i++)
    {
        a = temp_set();
        b = temp_set();
        new_ret = temp_set();
        a_len = string_to_int(abcde_put(str[i]), a);
        b_len = string_to_int(jegob_31(i), b);
        c = a_multip_b(a, b, a_len, b_len, &c_len);
        *ret_len = a_plus_b(new_ret, ret, c, *ret_len, c_len);
        ret = ret_set(new_ret, *ret_len);
    }
    return (ret);
}
int main()
{
    int n, ret_len = 0, m_len = 10, flag = 0, n_ret_len;
    int *ret, *new_ret;
    int m[10];
    m_set(m);
    scanf("%d", &n);
    char str[n + 1];
    scanf("%s", str);
    ret = main2(n, str, &ret_len);
    if (ret_m_comp(ret, ret_len, m, m_len, &flag))
    {
        ret = ret_mod_comp(ret, ret_len, m, m_len, &n_ret_len);
        ret_len = n_ret_len;
        if (ret == NULL)
            return (0);
    }
    if (flag == -1)
    {
        printf("0\n");
        free(ret);
        return (0);
    }
    for (int i = 0; i < ret_len; i++)
    {
        printf("%d", ret[i]);
    }
    printf("\n");
    free(ret);
}