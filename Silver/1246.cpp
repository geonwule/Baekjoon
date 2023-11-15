#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int numEgg, numCus;
vector<int> vCus;

void output()
{
    sort(vCus.begin(), vCus.end());

    size_t rfee = 0, rsum = 0;
    for (int i = 0; i < vCus.size(); i++)
    {
        size_t fee = vCus[i], curEgg = 0;
        for (int j = 0; j < vCus.size(); j++)
        {
            if (vCus[j] >= fee)
                curEgg++;
        }
        if (curEgg > numEgg)
            curEgg = numEgg;
        if (rsum < curEgg * fee)
        {
            rsum = curEgg * fee;
            rfee = fee;
        }
    }
    cout << rfee << ' ' << rsum;
}

void input()
{
    cin >> numEgg >> numCus;
    for (int i = 0; i < numCus; i++)
    {
        int t;
        cin >> t;
        vCus.push_back(t);
    }
}

int main()
{
    input();
    output();
}
