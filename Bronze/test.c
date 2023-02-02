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

// void a_minus_b(int *a, int *b, int a_len, int b_len, char *temp)
// {
//     printf("%s", temp);
// }

// void a_cob_b(int *a, int *b, int a_len, int b_len, char *temp)
// {
//     printf("%s", temp);
// }

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
    a_plus_b(a, b, a_len, b_len, temp); // A - B
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