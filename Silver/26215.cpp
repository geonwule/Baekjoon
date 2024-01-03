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
int n;
// vector<int> v;
deque<int> v;
int time_ = 0;

void output()
{
    int target = 0;
    while (!v.empty())
    {
        sort(v.begin(), v.end());
        time_++;
        if (time_ > 1440)
        {
            cout << -1;
            return ;
        }
        deque<int>::iterator max1 = (v.end()-1);
        --*(max1);
        if (v.size() >= 2)
        {
            deque<int>::iterator max2 = (v.end()-2);
            --*(max2);
            if (*(max2) == 0)
                v.erase(max2);
        }
        if (*(max1) == 0)
            v.erase(max1);
    }
    cout << time_;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
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
