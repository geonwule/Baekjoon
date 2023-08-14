#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a[101], b[101], c[101];
int ret = INT_MAX;
int	a_i = -1, b_i = -1, c_i = -1;

void	dfs(int cnt)
{
	if (a_i == -1 && b_i == -1)
	{
		if (cnt < ret)
			ret = cnt;
	}
	if (a_i != -1 && (b_i == -1 || c_i == -1 || a[a_i] < ))
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n; i >= 1; i--)
		a[++a_i] = i;
	dfs(0);
	printf("%d\n", ret);
}