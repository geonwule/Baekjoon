#include <stdio.h>

long long   power(long long x, long long n, long long m)
{
    if (m == 1)
        return (0);
    if (n == 0)
        return (1);
    long long half, result;
    if (n % 2 == 0)
    {
        half = power(x, n / 2, m);
        result = half * half % m;
    }
    else
    {
        half = power(x, (n - 1) / 2, m);
        result = half * half % m * x % m;
    }
    return (result);
}

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", power(a, b, c));
}