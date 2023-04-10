#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long *n_box = malloc(sizeof(unsigned long long) * (n + 6));
    n_box[1] = 5;
    n_box[2] = 12;
    n_box[3] = 22;
    for (int i = 4; i <= n; i++)
        n_box[i] = n_box[i - 1] + (i + 1) * 3 - 2;
    printf("%llu\n", n_box[n] % 45678);
}