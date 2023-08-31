#include <iostream>

int arr[11] = {0, };

void	recur(int goal, int lev, int &ret)
{
	if (lev > goal)
		return ;
	if (lev == goal)
	{
		ret += 1;
		return ;
	}
	for (int i = 1; i <= 3; i++)
	{
		recur(goal, lev + i, ret);
	}
}

void	set_arr(void)
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		int ret = 0;
		recur(i, 0, ret);
		arr[i] = ret;
	}
}

int main()
{
	int test;
	set_arr();
	std::cin >> test;
	for (int i = 0; i < test; i++)
	{
		int n;
		std::cin >> n;
		std::cout << arr[n] << "\n";
	}
}