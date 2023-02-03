#include <stdio.h>

int main()
{
    int h, m, s, n;
    scanf("%d %d %d %d", &h, &m, &s, &n);

    s += n % 60;
    if (s >= 60)
    {
        s -= 60;
        m += 1;
    }
    m += n / 60;
    while (m >= 60)
    {
        m -= 60;
        h += 1;
    }
    if (h >= 24)
        h -= 24;
    printf("%d %d %d\n", h, m, s);
}