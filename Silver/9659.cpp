#include <iostream>

using namespace std;

enum e_win_or_lose
{
    WIN,
    LOSE,
};

void printWinner(e_win_or_lose winner)
{
    if (winner == WIN)
        cout << "SK";
    else
        cout << "CY";
}

#include <vector>

#define MAX 1000000000000

vector<e_win_or_lose> sk_side_dp;

int main()
{
    size_t n;
    cin >> n;
    sk_side_dp.resize(n);

    sk_side_dp[1] = WIN;
    sk_side_dp[2] = LOSE;
    sk_side_dp[3] = WIN;
    sk_side_dp[4] = LOSE;
    sk_side_dp[5] = WIN;
    for (size_t i = 6; i <= n; i++)
    {
        //상대 입장에서 내가 1 or 3 or 4를 가져갔을때 모두 WIN인 경우면 나는 LOSE
        if (sk_side_dp[i - 1] == WIN && sk_side_dp[i - 3] == WIN)
            sk_side_dp[i] = LOSE;
        else // 상대가 LOSE한 경우 하나라도 있으면 그것을 선택하면 되기 떄문에 나는 WIN
            sk_side_dp[i] = WIN;
    }
    printWinner(sk_side_dp[n]);
}