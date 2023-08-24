#include <iostream>

int main()
{
	while (1)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp == 0)
			return (0);
		int d[4];
		d[0] = tmp / 1000;
		d[1] = tmp / 100;
		if (d[1] > 9)
			d[1] %= 10;
		d[2] = tmp / 10;
		if (d[2] > 9)
			d[2] %= 10;
		d[3] = tmp % 10;
		int ret = 2;
		if (d[0])
		{
			ret += 3 * 4 + 3;
			for (int i = 0; i < 4; i++)
			{
				if (d[i] == 1)
					ret -= 1;
				else if (d[i] == 0)
					ret += 1;
			}
		}
		else if (d[1])
		{
			ret += 3 * 3 + 2;
			for (int i = 1; i < 4; i++)
			{
				if (d[i] == 1)
					ret -= 1;
				else if (d[i] == 0)
					ret += 1;
			}
		}
		else if (d[2])
		{
			ret += 3 * 2 + 1;
			for (int i = 2; i < 4; i++)
			{
				if (d[i] == 1)
					ret -= 1;
				else if (d[i] == 0)
					ret += 1;
			}
		}
		else
		{
			ret += 3 * 1 + 0;
			for (int i = 3; i < 4; i++)
			{
				if (d[i] == 1)
					ret -= 1;
				else if (d[i] == 0)
					ret += 1;
			}
		}
		std::cout << ret << "\n";
	}
}