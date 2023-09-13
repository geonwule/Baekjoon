#include <iostream>
#include <cmath>

int main()
{
    int L;
    std::string str;
    std::cin >> L >> str;
    unsigned long long ret = 0;
    unsigned long long r = 1;
    for (int i = 0; i < str.size(); i++)
    {
        ret += ((str[i] - 'a' + 1) * r) % 1234567891;
        ret %= 1234567891;
        r = r * 31 % 1234567891;
    }
    ret %= 1234567891;
    std::cout << ret;
}