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
    size_t time, fee, curIdx;
    bool possible;
};

size_t dp[17];
// bool vi[16];
int main()
{
    int t;
    cin >> t;
    vector<zz> v;
    zz temp = {0, 0, 0};
    v.push_back(temp);
    for (int i = 0; i < t; i++)
    {
        zz tmp;
        cin >> tmp.time >> tmp.fee;
        tmp.curIdx = 0;
        tmp.possible = true;
        if (tmp.time > t - i)
            tmp.possible = false;
        v.push_back(tmp);
    }
    dp[t+1] = 0; // empty tail 
    dp[t] = 0;
    if (v[t].possible)
        dp[t] = v[t].fee;
    for (int i = t; i >= 1; i--)
    {
        if (!v[i].possible) // 남은 기간보다 상담 기간이 더 길때 불가
            dp[i] = dp[i + 1];
        else if (dp[i + v[i].time] + v[i].fee <= dp[i + 1]) // 현재 가격과, 현재를 하면 생기는 공백 이후 가격을 더한게 다음날 가격보다 작으면 진행안함
            dp[i] = dp[i + 1];
        else //진행함
            dp[i] = dp[i + v[i].time] + v[i].fee;
    }
    // for (int i = 1; i <= t; i++)
    //     cout << i << " : " << dp[i] << "\n";
    cout << dp[1];
}