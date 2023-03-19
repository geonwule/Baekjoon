#include <stdio.h>

char	rect[50][51];

void	rect_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s", rect[i]);
	}
}

int	compare(int a, int b)
{
	return (a < b ? a : b);
}

int	main(void)
{
	int n, m, max;
	scanf("%d %d", &n, &m);
	rect_init(n);
	max = compare(n, m) - 1;
	for (int idx = max; idx >= 1; idx--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i + idx < n && j + idx < m
					&& rect[i][j] == rect[i][j + idx]
					&& rect[i][j] == rect[i + idx][j] 
					&& rect[i][j] == rect[i + idx][j + idx])
				{
					max = idx;
					printf("%d\n", (max + 1) * (max + 1));
					return (0);
				}
			}
		}
	}
	printf("1\n");
}