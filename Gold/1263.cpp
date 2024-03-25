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

#define Max 1000
int n;
struct Work
{
    int t, s;
};

vector<Work> work;

int compare(Work &a, Work &b)
{
    return a.s > b.s;
}

int possible(int t)
{
    for (int i = 0; i < n; i++)
    {
        Work &cur = work[i];
        t += cur.t;
        if (t > cur.s)
        {
            return 0;
        }
    }
    return 1;
}

void output()
{
    sort(work.begin(), work.end(), compare);
    // int res;
    // for (res = work[0].s - work[0].t; res >= -1; res--)
    // {
    //     if (possible(res))
    //         break;
    // }

    int cur_time = work[0].s - work[0].t;
    for (int i = 1; i < n; i++)
    {
        if (cur_time <= work[i].s)
        {
            cur_time -= work[i].t;
        }
        else
        {
            cur_time = work[i].s - work[i].t;
        }
    }

    if (cur_time < 0)
        cur_time = -1;
    cout << cur_time;

    // cout << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     cout << work[i].t << ' ' << work[i].s << '\n';
    // }
}

void input()
{
    cin >> n;
    work.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> work[i].t >> work[i].s;
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