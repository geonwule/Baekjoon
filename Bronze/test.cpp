#include <iostream>
#include <string>

int main()
{
	std::string a, b;
	char c;
	std::cin >> a >> c >> b;
	if (b.size() > a.size())
	{
		std::string temp = b;
		b = a;
		a = temp;
	}
	std::string ret = a + b;
	if (c == '*')
	{
		for (int i = 1; i < ret.size(); i++)
		{
			if (ret[i] == '1')
			{
				ret.erase(i, 1);
				std::cout << ret;
				return (0);
			}
		}
	}
	if (a.size() > b.size())
	{
		for (int i = 1; i <= b.size(); i++)
		{
			ret.erase(1, 1);
		}
	}
	else
	{
		ret = a;
		ret[0] = '2';
	}
	std::cout << ret;
}