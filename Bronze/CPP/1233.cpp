#include <iostream>

int arr[81] = {
    0,
};

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    for (int x = 1; x <= a; x++)
    {
        for (int y = 1; y <= b; y++)
        {
            for (int z = 1; z <= c; z++)
            {
                arr[x + y + z] += 1;
            }
        }
    }
    int idx;
    int cnt = 0;
    for (int i = 3; i <= 80; i++)
    {
        if (arr[i] > cnt)
        {
            idx = i;
            cnt = arr[i];
        }
    }
    std::cout << idx << std::endl;
}