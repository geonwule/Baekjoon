#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = i;; j++)
		{
			if (j > n)
				j -= n;
			printf("%d", j);
			if (cnt++ + 1 >= m)
			{
				printf("\n");
				break ;
			}
			printf(" ");
		}
	}
}