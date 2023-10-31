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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Stuff
{
    int wt, va;
    Stuff() : wt(0), va(0) {}
    Stuff &operator+(const Stuff &other)
    {
        Stuff temp(*this);
        temp.wt += other.wt;
        temp.va += other.va;
        return temp;
    }
};

int num, _weight, res = 0;
Stuff stuff[101];
int dp[101][100001];
void output()
{
    for (int i = 1; i <= num; i++)
    {
        for (int weight = 1; weight <= _weight; weight++)
        {
            if (i == 1)
            {
                if (stuff[i].wt <= weight)
                    dp[i][weight] = stuff[i].va;
                else
                    dp[i][weight] = 0;
                continue;
            }

            if (stuff[i].wt > weight)
                dp[i][weight] = dp[i - 1][weight];
            else // stuff[i].wt <= weight
            {
                dp[i][weight] = max(dp[i - 1][weight], dp[i - 1][weight - stuff[i].wt] + stuff[i].va);
            }
        }
    }
    res = dp[num][_weight];
}

// void output()
// {
//     if (stuff[0].wt <= _weight)
//         dp[0] = stuff[0];
//     else
//         dp[0] = Stuff();

//     for (int i = 1; i < num; i++)
//     {
//         if (stuff[i].wt <= _weight)
//             dp[i] = stuff[i];
//         else
//         {
//             dp[i] = Stuff();
//             continue;
//         }
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (stuff[i].wt + dp[j].wt <= _weight && dp[i].va < stuff[i].va + dp[j].va)
//             {
//                 dp[i] = stuff[i];
//                 dp[i] += dp[j];
//             }
//         }
//     }
//     for (int i = 0; i < num; i++)
//     {
//         if (dp[i].va > res)
//             res = dp[i].va;
//     }
// }

void input()
{
    cin >> num >> _weight;
    for (int i = 1; i <= num; i++)
        cin >> stuff[i].wt >> stuff[i].va;
}

int main()
{
    input();
    output();
    cout << res;
}
