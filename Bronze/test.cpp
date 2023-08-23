#include <iostream>
#include <vector>
#include <string>
//#include <sstream>

void parseTime(const std::string& timeStr, int& hour, int& minute, int& second) {
    size_t firstColon = timeStr.find(':');
    size_t secondColon = timeStr.rfind(':');

    if (firstColon == std::string::npos || secondColon == std::string::npos || firstColon == secondColon) {
        // 구분자가 존재하지 않거나, 구분자가 두 개가 아니거나, 구분자 사이에 문자가 없을 경우
        throw std::invalid_argument("Invalid time format");
    }

    hour = std::stoi(timeStr.substr(0, firstColon));
    minute = std::stoi(timeStr.substr(firstColon + 1, secondColon - firstColon - 1));
    second = std::stoi(timeStr.substr(secondColon + 1));
}

int main()
{
	int hh, mm, ss, hh2, mm2, ss2, hh3 = 0, mm3 = 0, ss3 = 0;
	std::string	tmp1, tmp2;
	std::cin >> tmp1 >> tmp2;
	parseTime(tmp1, hh, mm, ss);
	parseTime(tmp2, hh2, mm2, ss2);
	// std::cin >> hh >> mm >> ss;
	// std::cin >> hh2 >> mm2 >> ss2;
	if (hh2 < hh)
	{
		hh2 += 24;
	}
	else if (hh2 == hh)
	{
		if (mm2 < mm)
		{
			hh2 += 24;
		}
		else if (mm2 == mm)
		{
			if (ss2 < ss)
			{
				hh2 += 24;
			}
			else if (ss2 == ss)
			{
				std::cout << "24:00:00";
				return (0);
			}
		}
	}
	ss3 = ss2 - ss;
	if (ss3 < 0)
	{
		ss3 += 60;
		mm3 -= 1;
	}
	mm3 += mm2 - mm;
	if (mm3 < 0)
	{
		mm3 += 60;
		hh3 -= 1;
	}
	hh3 += hh2 - hh;
	std::vector<int>	ret;
	ret.push_back(hh3);
	ret.push_back(mm3);
	ret.push_back(ss3);
	for (int i = 0; i < 3; i++)
	{
		if (ret[i] == 0 || ret[i] / 10 == 0)
			std::cout << "0";
		std::cout << ret[i];
		if (i + 1 != 3)
			std::cout << ":";
	}
}