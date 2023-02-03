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

void a_minus_b(int *a, int *b, int a_len, int b_len, int minus) // abs(a) > abs(b)
{
    int a_l = a_len - 1;
    int b_l = b_len - 1;
    int *temp = temp_set();
    int i = 0;
    int j;
    while (b_l >= 0)
    {
        temp[i] = a[a_l] - b[b_l];
        if (temp[i] < 0)
        {
            temp[i] += 10;
            j = a_l - 1;
            while (a[j] - 1 < 0)
            {
                a[j] -= 1;
                a[j] += 10;
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
    int ret[2002] = {
        0,
    };
    for (int k = i - 1; k >= 0; k--)
    {
        if (temp[k] != 0)
        {
            i = k;
            break;
        }
    }
    int r = 0;
    for (int k = i; k >= 0; k--)
    {
        ret[r] = temp[k];
        r++;
    }
    if (minus == -1)
        ret[0] *= -1;
    for (int k = 0; k <= i; k++)
    {
        printf("%d", ret[k]);
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
                temp[i + 1] += 1; // 0 init
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

void a_plus_b(int *a, int *b, int a_len, int b_len)
{
    int *temp = temp_set();
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
    int k = big_len;
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
    free(temp);
    printf("\n");
}

int b_count(int *b, int b_len)
{
    for (int i = 0; i < b_len; i++)
    {
        if (b[i] != 0)
            return (1);
    }
    return (0);
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

    if (a[0] == 1 && a[1] == -48 || b[0] == 1 && b[1] == -48) // a or b == 1
    {
        a_or_b_one(a, b, a_len, b_len, minus);
        return;
    }
    int *temp = temp_set();
    int b_l = b_len - 1;
    int j = 0;
    int max = 0;
    int i;
    int a_l;
    while (b_count(b, b_len))
    {
        //b_count
        b[b_l] -= 1;
        if (b[b_l] < 0)
        {
            b[b_l] += 10;
            j = b_l -1;
            while (b[j] - 1 < 0)
            {
                b[j] -= 1;
                b[j] += 10;
                j--;
            }
            b[j] -= 1;
        }
        //b_count
        //
        // temp += a : while (b_count)
        i = 0;
        a_l = a_len - 1;
        while (a_l >= 0)
        {
            temp[i] += a[a_l];
            if (temp[i] > 9)
            {
                temp[i] -= 10;
                j = i + 1;
                while (temp[j] + 1 > 9)
                {
                    temp[j] += 1;
                    temp[j] -= 10;
                    j++;
                }
                temp[j] += 1;
                if (max < j)
                    max = j + 1;
             }
            a_l--;
            i++;
        }
    }
    int ret[2002] = {
        0,
    };
    if (max > i)
        i = max;
    int r = 0;
    for (int k = i - 1; k >= 0; k--)
    {
        ret[r] = temp[k];
        r++;
    }
    if (minus == -1)
        ret[0] *= -1;
    for (int k = 0; k < i; k++)
    {
        printf("%d", ret[k]);
    }
    printf("\n");
    free(temp);
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
    /// @ㅇㅖ오ㅣ처리 //////////////////////////////
    ////////////////////////////////////////////A + B
    int *a_temp = a_b_temp(a);
    int *b_temp = a_b_temp(b);

    a_plus_b(a_temp, b_temp, a_len, b_len);
    free(a_temp);
    free(b_temp);
    ////////////////////////////////////////////////////   A - B
    a_temp = a_b_temp(a);
    b_temp = a_b_temp(b);
    b_temp[0] *= -1;
    if ((a_temp[0] < 0 && b_temp[0] < 0) || (a_temp[0] > 0 && b_temp[0] > 0))
        a_plus_b(a_temp, b_temp, a_len, b_len); // A - B
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
    ////////////////////////////////////////////////////// A x B
    a_temp = a_b_temp(a);
    b_temp = a_b_temp(b);
    a_multip_b(a_temp, b_temp, a_len, b_len);
    free(a_temp);
    free(b_temp);
    ////////////////////////////////////////////////////
}