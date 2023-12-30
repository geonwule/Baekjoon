#include <iostream>

#define Max 90 // 1 <= N <= 90

int N;

using namespace std;

void input()
{
    cin >> N;
}

size_t dp[Max + 1];

void output()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 5;
    for (int i = 6; i <= N; i++)
        dp[i] = dp[i - 1] + (dp[i - 1] / 2) + 1;

    cout << dp[N];
}
/*
    1 

    1 0

    10 0
    10 1

    100 100 0 100 1
    101 101 0 

    1000 1000 0 1000 1
    1001 1001 0 
    1010 1010 0 1010 1

    10000 0 1
    10001 0
    10010 0 1
    10100 0 1
    10101 0
*/

int main()
{
    input();
    output();
}