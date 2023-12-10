#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Max 1001

enum    e_state
{
    NORMAL = 0,
    LEAKS,
};

// vector<e_state> varr(Max);
vector<int> vleaks;

int varr[Max];
//, vleaks[Max], vleaks_idx = 0;

int nLeaks, ltapes, needTapes = 0;

int main()
{
    cin >> nLeaks >> ltapes;
    for (int i = 0; i < nLeaks; i++)
    {
        int location;
        cin >> location;
        varr[location] = LEAKS;
        vleaks.push_back(location);
        // vleaks[vleaks_idx++]= location;
    }
    sort(vleaks.begin(), vleaks.end());
    for (size_t i = 0; i < vleaks.size(); i++)
    {
        int cur = vleaks[i];
        if (varr[cur] == LEAKS)
        {
            needTapes++;
            for (int j = cur; j < cur + ltapes; j++)
                varr[j] = NORMAL;
        }
    }
    cout << needTapes;
}