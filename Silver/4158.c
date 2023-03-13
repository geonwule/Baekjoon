#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binary(int *a, int t, int left, int right)
{
	int L = left, R = right, pivot, p_i;
	while (L <= R)
	{
		p_i = (L + R) / 2;
		pivot = a[p_i];
		if (t == pivot)
			return 1;
		if (pivot < t)
			L = p_i + 1;
		else
			R = p_i - 1;
	}
	return 0;
}

void a_init(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}

int main()
{
	int n, m, *a, t, cnt, z1, z2;
	while (1)
	{
		cnt = 0;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			return 0;
		a = (int *)malloc(sizeof(int) * (n + 1));
		a_init(a, n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &t);
			if (binary(a, t, 0, n - 1))
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
		free(a);
	}
}