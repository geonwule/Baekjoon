#include <stdio.h>

int main()
{
    int b1, b2, b3, c1, c2;

    scanf ("%d %d %d %d %d", &b1,&b2,&b3,&c1,&c2);

    int s_b, s_c;

    s_b = b1;
    s_c = c1;

    if (s_b > b2)
        s_b = b2;
    if (s_b > b3)
        s_b = b3;
    if (s_c > c2)
        s_c = c2;
    printf("%d\n", s_b + s_c - 50);
}