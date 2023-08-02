#include <iostream>

int main()
{
    int a, b, v;
    std::cin >> a >> b >> v;
    int ret = 0, day = 0;
    while (1)
    {
        ret += a;
        day++;
        if (ret >= v)
            break ;
        ret -= b;
    }
    std::cout << day;
}