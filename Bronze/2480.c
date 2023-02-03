#include <stdio.h>

int main()
{
    int a, b, c;
    int ret = 0;

    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
    {
        ret += 10000;
        ret += (a * 1000);
        printf("%d\n", ret);
        return (0);
    }
    if (a == b || a == c || b == c)
    {
        ret += 1000;
        if (a == b || a == c)
        {
            ret += (a * 100);
        }
        else if (b == c)
        {
            ret += (b * 100);
        }
        printf("%d\n", ret);
        return (0);
    }
    int big;

    big = a;
    if (big < b)
        big = b;
    if (big < c)
        big = c;
    ret += (big * 100);
    printf("%d\n", ret);
}