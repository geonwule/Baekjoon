#include <string.h>
#include <stdio.h>

int main()
{
    int i = 0;

    for (int j = 0; j < 20; j++)
        i += ('z') * (j + 1);
    printf("%d\n", i);
}