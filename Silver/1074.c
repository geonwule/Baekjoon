#include <stdio.h>

int	arr[33000][33000];

void	dfs(int s_x, int s_y, int e_x , int e_y, int r, int c)
{
	if (e_x - s_x == 2)
	{
		
	}
}

int	two_jegob(int n)
{
	int t = 1;
	for (int i = 0; i < n; i++)
		t *= 2;
	return (t);
}

int main()
{
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	int two = two_jegob(n);
	dfs(0, 0, two, two, r, c);
	printf("%d\n", arr[r][c]);
}