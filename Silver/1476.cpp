//. (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)

#include <iostream>
using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;

    int ourCalender = 1;
    int e = 1, s = 1, m = 1;

    while (1)
    {
        if (e == E && s == S && m == M)
            break;
        e++;
        s++;
        m++;
        ourCalender++;

        if (e > 15)
            e -= 15;
        if (s > 28)
            s -= 28;
        if (m > 19)
            m -= 19;
    }

    cout << ourCalender;
}