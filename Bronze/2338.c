#include <stdio.h>

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

void big_plus_small(int *a, int *b, int a_len, int b_len, int *temp)
{
    int i = 0;
    int box;
    while (a_len >= 0)
    {
        while (b_len >= 0)
        {
            box = 0;
            box += a[a_len] + b[b_len];
            if (box / 10)
            {
                box = box % 10;
                temp[i + 1] += 1;   // 0 init
            }
            temp[i] += box;
            a_len--;
            b_len--;
            i++;
        }
        if (a_len < 0)
            break;
        temp[i] += a[a_len];
        if (temp[i] / 10)
        {
            temp[i + 1] += 1;
            temp[i] = temp[i] % 10;
        }
        a_len--;
        i++;
    }
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
        return (1);  // abs (a == b)
    }
}

void    a_bbagi_b(int *a, int *b, int a_len, int b_len, int *temp, int minus)  // abs(a) > abs(b)
{
    int a_l = a_len;
    int b_l = b_len;
    int i = 0;
    while (b_l >= 0)
    {
        temp[i] = a[a_l] - b[b_l];
        if (temp[i] < 0)
        {
            temp[i] += 10;
            int j = a_l -1;
            while (a[j] - 1 < 0)
            {
                a[j] -= 1;
                j--;
            }
            a[j] -= 1;
        }
        i++;
        b_l--;
        a_l--;
    }
    while (a_l >= 0)
    {
        temp[i] = a[a_l];
        i++;
        a_l--;
    }
    int ret[2002] = {0 , };
    i--;
    for (int k = i; i >= 0; i--)
    {
        if (temp[k] != 0)
        {
            i = k;
            break ;
        }
    }
    int r = 0;
    for (int k = i; k >= 0; k--)
    {
        ret[r] = temp[k];
        r++;
        k--;
    }
    if (minus == -1)
        ret[0] *= -1;
    for (int k = 0; k <= i; k++)
    {
        printf("%d", ret[k]);
    }
    printf("\n");
}

void a_minus_b(int *a, int *b, int a_len, int b_len, int *temp) // a > 0 , b < 0
{
    if (abs_set(a, b, a_len, b_len) == 1) //abs(a) == abs(b)
    {
        printf("0\n");
        return ;
    }
    if (abs_set(a, b, a_len, b_len) == 2) // abs(a) < abs(b)
        a_bbagi_b(b, a, b_len, a_len, temp, -1);
    else if (abs_set(a, b, a_len, b_len) == 3) // abs(a) >= abs(b)
        a_bbagi_b(a, b, a_len, b_len, temp, 1);
}

void a_plus_b(int *a, int *b, int a_len, int b_len, int *temp)
{
    int i = 0;
    int j = 0;
    int big_len;
    int flag = 1;
    if (a[0])
        if (a[0] < 0 && b[0] < 0) // both minus
        {
            a[0] *= -1;
            b[0] *= -1;
            flag = -1;
        }
    if (a[0] < 0 || b[0] < 0)
    {
        if (a[0] < 0)
        {
            a[0] *= -1;
            a_minus_b(b, a, b_len, a_len, temp);
        }
        if (b[0] < 0)
        {
            b[0] *= -1;
            a_minus_b(a, b, a_len, b_len, temp);
        }
        return ;
    }
    int box;
    a_len--;
    b_len--;
    if (a_len >= b_len)
    {
        big_plus_small(a, b, a_len, b_len, temp);
        big_len = a_len;
    }
    else if (a_len < b_len)
    {
        big_plus_small(b, a, b_len, a_len, temp);
        big_len = b_len;
    }
    int ret[2002] = {
        0,
    };
    int k = big_len ;
    if (temp[k + 1])
        k++;
    int q = 0;
    while (k >= 0)
    {
        ret[q] = temp[k];
        k--;
        q++;
    }
    if (flag == -1)
        ret[0] *= -1;
    for (int i = 0; i < q; i++)
    {
        printf("%d", ret[i]);
    }
    printf("\n");
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
    int temp[2002] = {
        0,
    };

    /// @ㅇㅖ오ㅣ처리 ///////////////// 
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
    /// @ㅇㅖ오ㅣ처리 ////////////////

    a_plus_b(a, b, a_len, b_len, temp); // A + B
    b[0] *= -1;
    if (a[0] < 0 && b[0] < 0 || a[0] > 0 && a[0] > 0)
        a_plus_b(a, b, a_len, b_len, temp); // A - B
    else if (b[0] < 0)
    {
        b[0] *= -1;
        a_minus_b(a, b, a_len, b_len, temp); // A - B
    }
    else if (a[0] < 0)
    {
        a[0] *= -1;
        a_minus_b(b, a, b_len, a_len, temp); // B - A
    }
    // a_minus_b();
    // a_cob_b();

    // printf("a_len = %d\n", a_len);
    // for (int i = 0; i < a_len; i++)
    // {
    //     printf("%d", a[i]);
    // }
    // printf("\n");
    // printf("b_len = %d\n", b_len);
    // for (int i = 0; i < b_len; i++)
    // {
    //     printf("%d", b[i]);
    // }
    // printf("\n");
}