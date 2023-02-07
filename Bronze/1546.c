#include <stdio.h>

int main()
{
    int n;
    double m;
    scanf("%d", &n);
    double box[n];
    for (int i = 0; i < n; i++)
        scanf("%le", &box[i]);
    m = box[0];
    for (int i = 1; i < n; i++)
    {
        if (m < box[i])
            m = box[i];
    }
    for (int i = 0; i < n; i++)
    {
        box[i] = box[i] / m * 100;
    }
    double sum = 0.00;
    for (int i = 0; i < n; i++)
    {
        sum += box[i];
    }
    printf("%.12f\n", sum / n);
}