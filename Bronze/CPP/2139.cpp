#include <iostream>

int main()
{
    while (1)
	{
		int dd, mm, yy, ret = 0;
		std::cin >> dd >> mm >> yy;
		if (!dd && !mm && !yy)
			break ;
		ret += dd;
		for (int i = 1; i < mm; i++)
		{
			if (i == 2)
			{
				if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0))
					ret += 29;
				else
					ret += 28;
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				ret += 30;
			else
				ret += 31;
		}
		std::cout << ret << std::endl;
	}
}