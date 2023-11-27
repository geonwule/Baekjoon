#include <iostream>
#include <vector>
#include <queue>

int numPeople, target;

void init_qarr(std::queue<int> &qarr)
{
    for (int i = 1; i <= numPeople; ++i) 
        qarr.push(i);
}
// 1 2 3 4 5
//   2 . 4 . . . .

int main()
{
    std::cin >> numPeople >> target;
    std::queue<int> qarr;
    init_qarr(qarr);

    std::cout << '<';
    while (1)
    {
        if (qarr.empty())
            break;
        int cnt = target;
        while (--cnt)
        {
            int tmp = qarr.front();
            qarr.pop();
            qarr.push(tmp);
        }
        std::cout << qarr.front();
        qarr.pop();
        if (!qarr.empty())
            std::cout << ", ";
    }
    std::cout << '>';
}