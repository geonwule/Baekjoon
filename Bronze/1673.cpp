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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#define Max 100

string buff;

void output()
{
    stringstream ss(buff);
    size_t coupon, stamp, res = 0, dojang = 0;
    ss >> coupon >> stamp;

    while (coupon)
    {
        dojang += coupon;
        res += coupon;

        coupon = dojang / stamp;
        dojang %= stamp;
    }
    cout << res << '\n';
}

void input()
{
    while (true)
    {
        buff.clear();
        if (!getline(cin, buff) || buff.empty())
            break;
        output();
    }
}

int main()
{
    input();
}
