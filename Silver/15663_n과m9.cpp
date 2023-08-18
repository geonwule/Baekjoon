#include <iostream>
#include <algorithm>
#include <vector>

int	n, m;
int	arr[8];
int	ret[8];
bool chk[8] = { false };

void	set_input(void)
{
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
}

void	back_tracking(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
		{
			std::cout << ret[i];
			if (i + 1 != m)
				std::cout << " ";
		}
		std::cout << "\n";
		return ;
	}
	int	xx = 0;
	for (int i = 0; i < n; i++)
	{
		if (!chk[i] && arr[i] != xx)
		{
			ret[level] = arr[i];
			xx = ret[level];
			chk[i] = true;
			back_tracking(level + 1);
			chk[i] = false;
		}
	}
}

int main()
{
	std::cin >> n >> m;
	set_input();
	std::sort(arr, arr + n);
	back_tracking(0);
}