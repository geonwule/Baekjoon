#include <stdio.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double max = a / b * c;
    double t = a * b / c;
    if (max < t)
        max = t;
    printf("%d", (int)max);
}