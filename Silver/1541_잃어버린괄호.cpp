#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    std::string s;
    std::cin >> s;
    int ret = 0, cur = 0;
    bool minus = false;
    std::string str;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t == '-' || t == '+')
        {
            int temp_int = std::stoi(str);
            if (minus)
                cur += temp_int;
            else
                ret += temp_int;
            if (t == '-')
                minus = true;
            str = "";
            continue;
        }
        str += t;
    }
    int temp_int = std::stoi(str);
    if (minus)
        cur += temp_int;
    else
        ret += temp_int;
    ret -= cur;
    std::cout << ret;
}