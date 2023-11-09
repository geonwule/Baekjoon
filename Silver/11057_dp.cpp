#include <iostream>
//https://geonwule.tistory.com/2
using namespace std;
#define Moduler 10007

size_t num, dp[1001][10], res[1001];

void output()
{
    for (int i = 0; i <= 9; i++) // dp[1] init
    {
        dp[1][i] = 1;
        res[1] += dp[1][i];
    }
    for (int i = 2; i <= num; i++)
    {
        for (int firstDigit = 0; firstDigit < 10; firstDigit++)
        {
            for (int j = firstDigit; j <= 9; j++)
                dp[i][firstDigit] += dp[i - 1][j] % Moduler;
            res[i] += dp[i][firstDigit];
            res[i] %= Moduler;
        }
    }
    cout << res[num];
}

void input()
{
    cin >> num;
}

int main()
{
    input();
    output();
}

