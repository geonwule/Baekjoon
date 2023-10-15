#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <queue>
#include <deque>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct zz
{
    size_t time, fee;
};

int n; // 1<=n<=1000
long r = 0;
int arr[3] = {1, 2, 2};
void dfs(int lev, vector<int> v)
{
    if (lev == n)
    {
        r++;
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] + lev <= n)
        {
            v.push_back(arr[i]);
            dfs(lev + arr[i], v);
            vector<int>::iterator ii = v.end() - 1;
            v.erase(ii);
        }
    }
    return;
}
long long dp[1001];
int main()
{
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    dp[4] = 11;
    dp[5] = 21;
    dp[6] = 43;
    // vector<int> v;
    // dfs(0, v);
    // cout << r << "\n";
    // return (0);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    cout << dp[n];
}
