#include <stdio.h>

int main()
{
    int n;
    scanf ("%d", &n);

    int ret = 0;
    int i = 1;
    while (n > 0)
    {
        if (i > n)
            i = 1;
        n -= i;
        i++;
        ret++;
    }
    printf("%d\n", ret);
}