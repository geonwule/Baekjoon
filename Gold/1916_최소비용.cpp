#include <iostream>
#include <vector>
#include <limits.h>

int n, m, start, end;
int	arr[1001][1001];

void	back(int a, int b, int sum, int *ret)
{
	if (a == start && b == end)
	{
		if (sum < *ret)
			*ret = sum;
		return ;
	}
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			back(x, y, sum, ret);
		}
	}
}

int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < 8; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	std::cin >> start >> end;
	int ret = INT_MAX;
	back(start, start, 0, &ret);
	std::cout << ret;
}