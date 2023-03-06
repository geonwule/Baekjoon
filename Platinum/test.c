#include <stdio.h>
#include <string.h>

int int_back(const void *x, const void *y)
{
    char *a = (char *)x;
    char *b = (char *)y;
    return (strlen(a));
    //return (a[3] - b[5]);
}

int main()
{
    char *a = "123456";
    char *b = "456789";
    printf("%d\n", int_back(a, b));
}