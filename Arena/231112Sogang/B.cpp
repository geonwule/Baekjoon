#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>

using namespace std;

int num;
vector<int> arr;
// string arr;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> num;
    arr.reserve(num);
    arr.push_back(1);

    vector<int>::iterator it;
    if (num >= 2)
    {
        it = arr.insert(arr.begin(), 2) + 1;
    }
    for (int i = 3; i <= num; i++)
    {
        if (i % 2 == 1)
        {
            it = arr.insert(it, i) + 1;
        }
        else // i % 2 == 0
        {
            it = arr.insert(it, i);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i + 1 == arr.size())
            cout << '\n';
        else
            cout << ' ';
    }
}