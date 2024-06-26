#include <iostream>
#include <vector>

using namespace std;

int solution(const int N)
{
    size_t ori = 1, var = 1, digit = 1;
    while(1)
    {
        if (var % N == 0)
            return digit;
        var = (var * 10 + 1) % N;
        // ori = ori * 10 + 1;
        // cout << "var = " << var << ", ori = " << ori << '\n';
        // cout << "digit = " << digit << ", var % N = " << var % N << ", ori % N = " << ori % N << '\n';
        digit++;
    }

    return 0;
}

int main()
{
    vector<int> answer;

    while (1)
    {
        int N;
        cin >> N;
        if (cin.eof())
            break;
        answer.push_back(solution(N));
    }

    for (const int &i : answer)
        cout << i << '\n';
    return 0;
}