#include <iostream>
#include <vector>

std::vector<int> dp;

int main()
{
    int n;
    std::cin >> n;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(3);
    for (int i = 4; i <= n; i++)
    {
        dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
    }
    std::cout << dp[n];
}