#include <stdio.h>

// 1 = 666
// one digit + -> 17 num -> 588digit -> str
// 0 < n < 10000

void    ret_init(char *ret)
{
    ret[0] = '6';
    ret[1] = '6';
    ret[2] = '6';
}

int ret_in_666(long long ret)
{
    int cnt;
    while (ret)
    {
        cnt = 0;
        while (ret % 10 == 6)
        {
            cnt++;
            if (cnt >= 3)
                return (1);
            ret /= 10;
        }
        ret /= 10;
    }
    return (0);
}

int main()
{
    long long n, ret = 666;
    //ret_init(ret);
    scanf ("%lld", &n);
    n -= 1;
    if (n == 0)
    {
        printf("666\n");
        return (0);
    }
    while (1)
    {
        ret++;
        if (ret_in_666(ret))
            n--;
        if (n == 0)
        {
            printf("%lld\n", ret);
            return (0);
        }
    }
}