#include <stdio.h>

long long power(long long x, long long n, long long m);

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", power(A, B, C));
    return 0;
}

long long power(long long x, long long n, long long m) {
	if (m == 1)
		return (0);
    if (n == 0) {
        return 1;
    }
    long long half = power(x, n / 2, m);
    long long result = half * half % m;
    if (n % 2 == 1) {
        result = result * x % m;
    }
    return result;
}

int	power(int x, int n)
{
	if (n == 0)
		return (1);
	int half;
	if (n % 2 == 0)
	{
		half = power(x, n / 2);
		return (half * half);
	}
	else if (n % 2 == 1)
	{
		half = power(x, (n - 1) / 2);
		return (half * half * x);
	}
	return (0);
}

int main()
{
	int x, n;
	printf("input x, n\n");
	scanf("%d %d", &x, &n);
	printf("x ^ n = %d\n", power(x, n));
}