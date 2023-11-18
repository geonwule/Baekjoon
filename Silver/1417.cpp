#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int numCandidate;

int main()
{
    cin >> numCandidate;
    vector<int> vlistC(numCandidate - 1);
    int dasom, catchNum = 0;
    cin >> dasom;
    for (int i = 0; i < numCandidate - 1; i++)
        cin >> vlistC[i];
    while (1)
    {
        if (vlistC.empty())
            break;
        sort(vlistC.begin(), vlistC.end());
        size_t i = vlistC.size() - 1;
        int &bigCandidate = vlistC[i];
        if (bigCandidate >= dasom)
        {
            bigCandidate--;
            dasom++;
            catchNum++;
        }
        else // dasom victory
            break;
    }
    cout << catchNum;
}