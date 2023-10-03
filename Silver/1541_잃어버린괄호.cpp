#include <iostream>
#include <cmath>

int main()
{
    std::string s;
    std::cin >> s;
    int ret = 0, cur = 0;
    char cal = '+';
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '+' || c == '-')
        {
            if (cal == '-')
                ret -= cur;
            else // cal == '+'
                ret += cur;
            cal = c;
            cur = 0;
            continue;
        }
    }
}