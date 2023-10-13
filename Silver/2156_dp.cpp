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
    int x, y, h;
    bool ch;
};

size_t dp[10001];
bool vi[10001];

int myMax(size_t a, size_t b, size_t c)
{
    if (a >= b && a >= c)
        return (1);
    else if (b >= a && b >= c)
        return (2);
    else
        return (3);
    return (0);
}

int main()
{
    int t;
    cin >> t;
    vector<size_t> v;
    v.push_back(0);
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0] = 0;
    dp[1] = v[1];
    vi[1] = true;
    dp[2] = v[1] + v[2];
    vi[2] = true;
    for (int i = 3; i <= t; i++)
    {
        if (vi[i - 1] && vi[i - 2])
        {
            size_t aa = dp[i - 1], bb = dp[i - 2] + v[i], \
                   cc = dp[i - 3] + v[i - 1] + v[i];
            switch (myMax(aa, bb, cc))
            {
                case 1:
                    dp[i] = aa;
                    break ;
                case 2:
                    dp[i] = bb;
                    vi[i] = true;
                    vi[i - 1] = false;
                    break ;
                case 3:
                    dp[i] = cc;
                    vi[i] = true;
                    vi[i - 2] = false;
                    break ;
                default :
                    break ;
            }
        }
        else
        {
            dp[i] = dp[i - 1] + v[i];
            vi[i] = true;
        }
    }
    cout << dp[t];
}