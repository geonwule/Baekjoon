#include <stdio.h>

//1<=b<=a<=v<=1,000,000,000
int main()
{
    int a, b, c, v, ret = 0, day = 0;
    scanf ("%d %d %d", &a, &b, &v);

    c = (v - a) / (a - b) + 1;
    if ((v - a) % (a - b) != 0)
        c += 1;
    printf("%d\n", c);
}
//     while (1)
//     {
//         ret += a;
//         day++;
//         if (ret >= v)
//             break ;
//         ret -= b;
//     }
//     printf("%d\n", day);
// }