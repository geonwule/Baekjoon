#include <stdio.h>
void fibonacci(int m, int *z, int *o)
{
	int zero[41] = {1, 0}, one[41] = {0, 1};
	for (int i = 2; i <= m; i++)
	{
		zero[i] = zero[i-1] + zero[i-2];
		one[i] = one[i-1] + one[i-2];
	}
	*z = zero[m];
	*o = one[m];
}
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		int zero = 0, one = 0;
		fibonacci(m, &zero, &one);
		printf("%d %d\n", zero, one);
	}
}