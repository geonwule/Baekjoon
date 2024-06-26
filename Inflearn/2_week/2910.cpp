#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int comp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    int N, C;
    cin >> N >> C;
    vector<pair<int, int>> vp;
    unordered_set<int> visited;
    while (N--)
    {
        int i;
        cin >> i;
        if (visited.count(i))
        {
            for (auto &p : vp)
            {
                if (p.first == i)
                {
                    p.second++;
                    break;
                }
            }
        }
        else
        {
            vp.push_back({i, 1});
            visited.insert(i);
        }
    }
    stable_sort(vp.begin(), vp.end(), comp);

    for (const auto& p : vp)
    {
        for (int i = 0; i < p.second; i++)
            cout << p.first << ' ';
    }

    return 0;
}