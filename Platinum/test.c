#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()//int ac, char **av)
{
    long long test;
    char    ch[1002];
    scanf("%lld", &test);
    sprintf(ch, "%lld", test);
    printf("%s\n", ch);
}