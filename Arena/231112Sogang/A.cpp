#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>

using namespace std;

int num;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> num;
    size_t jam = 0;
    int left, right;
    cin >> left >> right;
    if (left == right && left != 0)
        jam++;
    for (int i = 1; i < num; i++)
    {
        int nleft, nright;
        cin >> nleft >> nright;
        if (nleft == nright && nleft != 0)
            jam++;
        if (left == nleft && left != 0)
            jam++;
        if (right == nright && right != 0)
            jam++;
        left = nleft;
        right = nright;
    }
    cout << jam << '\n';
}