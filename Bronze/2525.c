#include <stdio.h>

int main()
{
    int hh, mm, time;
    scanf("%d %d %d", &hh, &mm, &time);
    int p_h = time / 60, p_m = time % 60;
    mm += p_m;
    while (mm > 59)
    {
        mm -= 60;
        hh += 1;
    }
    hh += p_h;
    while (hh > 23)
        hh -= 24;
    printf("%d %d\n", hh, mm);
}