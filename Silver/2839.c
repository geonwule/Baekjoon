#include <stdio.h>

int main()
{
    int n;
    int cnt = 0;

    scanf("%d", &n);    //kilogram

    if (n % 5 != 0 && n % 3 != 0)
    {
        printf("-1\n"); // error
        return (0);
    }
    if (n % 5 == 0)
    {
        cnt = n / 5;
        printf("%d\n", cnt);    //result
        return (0);
    }
    for (int i = 0; n - (3 * i) % 5 != 0; i++)
    {
        if (i * 3 >= n)
            break ;
    }

    printf("%d\n", cnt);    //result
}