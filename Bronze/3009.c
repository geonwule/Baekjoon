#include <stdio.h>

void    init(int *n)
{
    for (int j = 0; j < 2; j++)
        scanf("%d", &n[j]);
}

int y_set(int *a, int *b, int *c)
{
    int y;
    if (a[1] == b[1])
        y = c[1];
    else if (a[1] == c[1])
        y = b[1];
    else if (b[1] == c[1])
        y = a[1];
    return y;
}

int x_set(int *a, int *b, int *c, int *y)
{
    int x;
    if (a[0] == b[0])
    {
        x = c[0];
        *y = y_set(a, b, c);
    }
    else if (a[0] == c[0])
    {
        x = b[0];
        *y = y_set(a, b, c);
    }
    else if (b[0] == c[0])
    {
        x = a[0];
        *y = y_set(a, b, c);
    }
    return (x);
}

int main()
{
    int a[2], b[2], c[2];
    init(a);
    init(b);
    init(c);
    int x, y;
    x = x_set(a, b, c, &y);
    printf("%d %d", x, y);
    return 0;
}