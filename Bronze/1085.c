#include <stdio.h>

int main()
{
    int x, y, w, h, min;

    scanf("%d %d %d %d", &x,&y,&w,&h);
    min = x;
    if (w - x < min)
        min = w - x;
    if (y < min)
        min = y;
    if (h - y < min)
        min = h - y;
    printf("%d\n", min);
}