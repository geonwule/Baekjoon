#include <stdio.h>

int main()
{
    int ret = 0, a;

    while (1)
    {
        if (EOF == scanf("%d", &a))
            break ;
        ret += a;
    }
    printf("%d\n", ret);
}