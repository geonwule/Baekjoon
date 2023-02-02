#include <stdio.h>

int main()
{
    char a[10000], b[10000];
    char big[10000], small[10000];

    scanf("%s", a);
    scanf("%s", b);

    int a_i, b_i = 0;
    int big_i, sma_i;

    while (a[a_i] != '\0')
        a_i++;
    while (b[b_i] != '\0')
        b_i++;
    if (a_i >= b_i)
    {
        big = a;
        big_i = a_i;
        small = b;
        sma_i = b_i;
    }
    else if (b_i > a_i)
    {
        big = b;
        big_i = b_i;
        small = a;
        sma_i = a_i;
    }
    int t_a, t_b, t;
    while (sma_i >= 0)
    {
        t_a = big[big_i] - '0';
        t_b = small[sma_i] - '0';
        t = t_a + t_b;
        if (t >= 10)
        {
            t -= 10;
            for (int i = big_i - 1; i >= 0; i--)
            {
                if (big[i] + 1 == ':')
                    continue ;
                big[i] += 1;
            }
            big[big_i - 1] = (int)(big[big_i -1] - '0' + 1) + '0'; 
        }
        big[big_i] = 
        big_i--;
        sma_i--;
    }
}

// a= 14455
// b=   321
