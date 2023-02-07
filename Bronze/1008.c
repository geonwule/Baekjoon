#include <stdio.h>
#include <unistd.h>

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.12lf\n", (a / b));
}

// int main()
// {
//     int i;
//     int j;
//     int ten;
//     int cnt;
//     char c;

//     scanf("%d", &i);
//     scanf("%d", &j);
//     if (i < j)
//     {
//         ten = 10 * i;
//         printf("0.%d", ten / j);
//         cnt = 0;
//         while ((ten % j) != 0 && cnt < 32)
//         {
//             ten = 10 * (ten % j);
//             cnt++;
//             printf("%d", ten / j);
//         }
//         printf("\n");
//         return (0);
//     }
//     else if (i % j == 0 || i == j)
//     {
//         c = i / j + '0';
//         write(1, &c, 1);
//         write(1, "\n", 1);
//         return (0);
//     }
//     else
//         ten = 10 * (i % j);
//         printf("%d.%d", i / j, ten / j);
//         cnt = 0;
//         while ((ten % j) != 0 && cnt < 15)
//         {
//             ten *= 10;
//             cnt++;
//             printf("%d", ten / j);
//         }
//         printf("\n");
//         return (0);
// }