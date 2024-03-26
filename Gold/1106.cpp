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
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <stack>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int fx[2] = {1, 0};
int fy[2] = {0, 1};

#define Max 100000
int c, n;

struct Pr
{
    int fee, value;
};
vector<Pr> v;

int dp[Max + 1];

void output()
{
    int res = 0;

    for (int price = 1; price <= Max; price++)
    {
        for (int j = 0; j < n; j++)
        {
            Pr &pr = v[j];
            if (price % pr.fee == 0)
            {
                dp[price] = max(dp[price], price / pr.fee * pr.value);
            }
            else if (price >= pr.fee)
            {
                dp[price] = max(dp[price], dp[price-pr.fee] + pr.value);
            }
            else
                continue;
        }
        if (dp[price] >= c)
        {
            res = price;
            break;
        }
    }

    cout << res;
}

void input()
{
    cin >> c >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].fee >> v[i].value;
    }
}

int main()
{
    try
    {
        input();
        output();
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }
}
