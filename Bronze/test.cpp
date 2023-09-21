#include <iostream>

bool	check_arr(std::string tmp)
{
	std::string arr[] = {"Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", \
						"Never gonna make you cry", "Never gonna say goodbye",  "Never gonna tell a lie and hurt you", "Never gonna stop"};
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] == tmp)
			return (true);
	}
	return (false);
}

int main()
{
	int n;
	std::cin >> n;
	std::cin.ignore();
	std::string ret = "No";
	for (int i = 0; i < n; i++)
	{
		std::string tmp;
		std::getline(std::cin, tmp);
		// std::cin >> tmp;
		if (!check_arr(tmp))
		{
			ret = "Yes";
		}
	}
	std::cout << ret << std::endl;
	return (0);
}