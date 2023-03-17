#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
	int a = *(int *)x;
	int b = *(int *)y;

	return (b - a);
}

void zerg_win(int n)
{
	int mutal_at = 0, scv[3], dp[4];
	for (int i = 0; i < n; i++)
		scanf("%d", &scv[i]);
	if (n == 1)
	{
		mutal_at = scv[0] / 9;
		if (scv[0] % 9 == 0)
			mutal_at += 1;
	}
	else if (n == 2)
	{
		while (scv[0] > 0 || scv[1] > 0)
		{
			qsort(scv, 2, sizeof(int), compare);
			scv[0] -= 9;
			scv[1] -= 3;
			mutal_at++;
		}
	}
	else if (n == 3)
	{
		while (scv[0] > 0 || scv[1] > 0 || scv[2] > 0)
		{
			qsort(scv, 3, sizeof(int), compare);
			scv[0] -= 9;
			scv[1] -= 3;
			scv[2] -= 1;
			mutal_at++;
		}
	}
	printf("%d\n", mutal_at);
}

int main()
{
	int n;
	scanf("%d", &n);
	zerg_win(n);
}