#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf ("%d %d %d %d", &a,&b,&c,&d);

    int f = a + b + c + d;
    int m, s;

    m = f / 60;
    s = f % 60;
    printf("%d\n%d\n", m, s);
}