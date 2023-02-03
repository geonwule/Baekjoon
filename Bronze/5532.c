#include <stdio.h>

int main()
{
    int l, a, b, c, d;

    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

    int max = 1;

    while (a > c * max)
        max++;
    while (b > d * max)
        max++;

    l -= max;
    printf("%d\n", l);
}