#include <stdio.h>
#include <stdlib.h>

int scan_a_b(int *box)
{
    int box_len = 0;
    int i, j;
    char temp[2002];

    scanf("%s", temp);
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

int exept_process(int *a, int *b, int a_len, int b_len)
{
    if (a[0] == 0 && b[0] == 0)
    {
        for (int i = 0; i < 3; i++)
            printf("0\n");
        return (0);
    }
    if (a[0] == 0 || b[0] == 0)
    {
        if (a[0] == 0)
        {
            for (int i = 0; i < b_len; i++) // A + B
            {
                printf("%d", b[i]);
            }
            printf("\n");
            b[0] *= -1; // A - B
            for (int i = 0; i < b_len; i++)
            {
                printf("%d", b[i]);
            }
            printf("\n");
        }
        if (b[0] == 0)
        {
            for (int i = 0; i < a_len; i++) // A + B
            {
                printf("%d", a[i]);
            }
            printf("\n");
            for (int i = 0; i < a_len; i++) // A - B
            {
                printf("%d", a[i]);
            }
            printf("\n");
        }
        printf("0\n"); // A * B
        return (0);
    }
    return (1);
}

int *a_b_temp(int *a)
{
    int *ret;
    ret = (int *)malloc(sizeof(int) * 2002);
    for (int i = 0; i < 2002; i++)
    {
        ret[i] = a[i];
    }
    return (ret);
}

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

void a_minus_b(int *a, int *b, int a_len, int b_len, int minus) // abs(a) >= abs(b)
{
    int *temp = temp_set();
    int i = 0;
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
    if (minus == -1)
        temp[i] *= -1;
    for (int k = i; k >= 0; k--)
    {
        printf("%d", temp[k]);
    }
    printf("\n");
    free(temp);
}

void a_abs_comp_b(int *a, int *b, int a_len, int b_len) // a > 0 , b < 0
{
    if (abs_set(a, b, a_len, b_len) == 1) // abs(a) == abs(b)
    {
        printf("0\n");
        return;
    }
    if (abs_set(a, b, a_len, b_len) == 2) // abs(a) < abs(b)
        a_minus_b(b, a, b_len, a_len, -1);
    else if (abs_set(a, b, a_len, b_len) == 3) // abs(a) >= abs(b)
        a_minus_b(a, b, a_len, b_len, 1);
}

int big_plus_small(int *a, int *b, int a_len, int b_len, int *c)
{
    int i = 0;
    while (i < a_len)
    {
        if (i < b_len)
        {
            c[i] += a[a_len -i -1] + b[b_len - i -1];
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

void a_plus_b(int *a, int *b, int a_len, int b_len)
{
    int *temp = temp_set();
    int i = 0;
    int j = 0;
    int minus = 1;
    if (a[0])
        if (a[0] < 0 && b[0] < 0) // both minus
        {
            a[0] *= -1;
            b[0] *= -1;
            minus = -1;
        }
    if (a[0] < 0 || b[0] < 0) // one minus
    {
        if (a[0] < 0)
        {
            a[0] *= -1;
            free(temp);
            a_abs_comp_b(b, a, b_len, a_len);
        }
        if (b[0] < 0)
        {
            b[0] *= -1;
            free(temp);
            a_abs_comp_b(a, b, a_len, b_len);
        }
        return;
    }
    int max;
    if (a_len >= b_len)
        max = big_plus_small(a, b, a_len, b_len, temp);
    else if (a_len < b_len)
        max = big_plus_small(b, a, b_len, a_len, temp);
    if (minus == -1)
        temp[max] *= -1;
    for (int i = max; i >= 0; i--)
    {
        printf("%d", temp[i]);
    }
    free(temp);
    printf("\n");
}

int minus_check(int *a, int *b)
{
    int minus = 1;

    if (a[0] < 0 && b[0] < 0) // minus * minus = yangsu
    {
        a[0] *= -1;
        b[0] *= -1;
    }
    else if (a[0] < 0 || b[0] < 0) // minus * yangsu = minus
    {
        if (a[0] < 0)
            a[0] *= -1;
        if (b[0] < 0)
            b[0] *= -1;
        minus = -1;
    } // else : yangsu * yangsu = yangsu
    return (minus);
}

void a_or_b_one(int *a, int *b, int a_len, int b_len, int minus)
{
    if (a[0] == 1 && a[1] == -48)
    {
        if (minus == -1)
            b[0] *= -1;
        for (int i = 0; i < b_len; i++)
        {
            printf("%d", b[i]);
        }
    }
    else if (b[0] == 1 && b[1] == -48)
    {
        if (minus == -1)
            a[0] *= -1;
        for (int i = 0; i < a_len; i++)
        {
            printf("%d", a[i]);
        }
    }
    printf("\n");
}

void a_multip_b(int *a, int *b, int a_len, int b_len)
{
    int minus = minus_check(a, b);
    int *c = temp_set();
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
    if (minus == -1)
        c[max] *= -1;
    for (int i = max; i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    printf("\n");
    free(c);
}

int main()
{
    int a[2002] = {
        0,
    };
    int b[2002] = {
        0,
    };
    int a_len = scan_a_b(a);
    int b_len = scan_a_b(b);

    if (!exept_process(a, b, a_len, b_len))
        return (0);
    ///A + B
    int *a_temp = a_b_temp(a);
    int *b_temp = a_b_temp(b);

    a_plus_b(a_temp, b_temp, a_len, b_len);
    free(a_temp);
    free(b_temp);

    ///A - B
    a_temp = a_b_temp(a);
    b_temp = a_b_temp(b);
    b_temp[0] *= -1;
    if ((a_temp[0] < 0 && b_temp[0] < 0) || (a_temp[0] > 0 && b_temp[0] > 0))
        a_plus_b(a_temp, b_temp, a_len, b_len); // - A - B or A - (-B)
    else if (b_temp[0] < 0)
    {
        b_temp[0] *= -1;
        a_abs_comp_b(a_temp, b_temp, a_len, b_len); // A - B
    }
    else if (a_temp[0] < 0)
    {
        a_temp[0] *= -1;
        a_abs_comp_b(b_temp, a_temp, b_len, a_len); // B - A
    }
    free(a_temp);
    free(b_temp);

    ///A x B
    a_temp = a_b_temp(a);
    b_temp = a_b_temp(b);
    a_multip_b(a_temp, b_temp, a_len, b_len);
    free(a_temp);
    free(b_temp);
}