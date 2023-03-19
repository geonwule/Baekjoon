#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    long long ret = 1;

    for (int i = 1; i <= 15; i++)
    {
        ret *= i;
        printf("%d! = %lld\n", i, ret);
    }
}