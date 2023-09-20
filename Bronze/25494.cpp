#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        int ret = 0;
        for (int x = 1; x <= a; x++)
        {
            for (int y = 1; y <= b; y++)
            {
                for (int z = 1; z <= c; z++)
                {
                    if (x % y == y % z && y % z == z % x)
                        ret++;
                }
            }
        }
        std::cout << ret << std::endl;
    }
}