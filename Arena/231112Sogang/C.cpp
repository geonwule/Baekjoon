#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>

using namespace std;

int num, cmdNum;
vector<int> house, rev;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int hNum;
        cin >> hNum;
        house.push_back(hNum);
    }
    for (int i = 1; i <= num; i++)
    {
        for (int )
        rev.push_back(house[i]);
    }

    cin >> cmdNum;
    for (int i =0; i < cmdNum; i++)
    {
        int start, end;
        cin >> start >> end;
        vector<int> chouse(house);
        chouse.insert(chouse.begin(), 0); // head
        
        

        for (int j = 1; j <= num; j++)
        {
            cout << chouse[j];
            if (j  == num)
                cout <<'\n';
            else
                cout << ' ';
        }
    }
}