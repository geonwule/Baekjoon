#include <stdio.h>

unsigned long long jegob_31(int a)
{
    unsigned long long ret = 1;
    for (int i = 0; i < a; i ++)
    {
        ret *= 31;
    }
    return (ret);
}

int abcde_put(char c)
{
    int i = c - 96;
    return (i);
}
#include <limits.h>
int main()
{
    int n;
    unsigned long long ret = 0;

    scanf("%d", &n);
    char str[n + 1];
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        ret += abcde_put(str[i]) * jegob_31(i);
    }
    printf("%llu\n", ret);
}