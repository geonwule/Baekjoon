#include <stdio.h>

int main()
{
    char t[1000000] = {0, };
    int c = 0;

    while (1)
    {
        if (scanf("%s", t) == EOF)
            break ;
        c++;
    }
    printf("%d\n", c);
}