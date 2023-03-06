#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 4)
    {
        printf("0\n");
        return (0);
    }
    int five = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 5 == 0)
            five++;
        if (i % 25 == 0)
            five++;
        if (i % 125 == 0)
            five++;
    }
    printf("%d\n", five);
    return (0);
}
// for (unsigned long long i = 2; i <= n; i++)
// {
//     if ((sum % 10) % 2 == 0 && i % 10 == 5
//     || sum % 10 == 5 && (i % 10) % 2 == 0)
//     {
//         zero++;
//         sum = (sum * i) / 10;
//     }
//     else if (i % 10 == 0)
//     {
//         zero++;
//     }
//     else
//         sum = (sum * i) % 10;
// }
// printf("%d\n", zero);