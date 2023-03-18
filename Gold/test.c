#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int abs_mi(int a, int b)
{
    return (a - b > 0 ? a-b : b-a);
}

int main()
{
    printf("%d\n", abs_mi(1, 9));
}