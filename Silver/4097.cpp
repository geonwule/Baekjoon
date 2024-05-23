#include <iostream>

using namespace std;

// 1 ≤ n ≤ 250,000
//-10,000 ≤ arr[i] ≤ 10,000

#include <vector>

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        ssize_t res = -10000;
        vector<int> arr(n + 1), dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
        }
        
    }

    return 0;
}