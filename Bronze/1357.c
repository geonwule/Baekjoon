#include <stdio.h>
#include <stdlib.h>

int ft_intlen(int a)
{
    if (a < 10)
        return (1);
    if (a >= 10 && a < 100)
        return (2);
    if (a >= 100 && a < 1000)
        return (3);
    return (4);
}

int ft_rev(int a)
{
    int len = ft_intlen(a);
    char    *ret;

    if (len == 1)
        return (a);
    ret = (char *)malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    int i = 0;
    while (i < len)
    {
        ret[i] = a % 10 + '0';
        i++;
        a /= 10;
    }
    return (atoi(ret)); 
}

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    
    printf("%d\n", ft_rev(ft_rev(x) + ft_rev(y)));
}