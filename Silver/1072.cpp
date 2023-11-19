#include <iostream>
#define MAX 1000000000
#define MIN 0
int main()
{
    double numGame, numVictor;
    std::cin >> numGame >> numVictor;

    int VictorPercent = numVictor * 100 / numGame;
    if (VictorPercent >= 99)
    {
        std::cout << -1;
        return 0;
    }

    // std::cout << VictorPercent << ' ';
    int cnt;
    int low = MIN, high = MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int temp = (numVictor + mid) * 100 / (numGame + mid);
        if (temp > VictorPercent)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    std::cout << low;
}