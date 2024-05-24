#include <iostream>
using namespace std;

#include <vector>
#include <climits>
int main()
{
    int n;
    cin >> n;

    vector<int> dp_cnt(n + 1, INT_MAX);
    dp_cnt[1] = 0;
    dp_cnt[2] = 1;
    dp_cnt[3] = 1;
    dp_cnt[4] = 2;
    for (int i = 5; i <= n; i++)
    {
        if (i % 3 == 0)
            dp_cnt[i] = min(dp_cnt[i / 3], dp_cnt[i]);
        
        if (i % 2 == 0)
            dp_cnt[i] = min(dp_cnt[i / 2], dp_cnt[i]);
        
        dp_cnt[i] = min(dp_cnt[i - 1], dp_cnt[i]);

        dp_cnt[i] += 1;
    }

    cout << dp_cnt[n] << '\n';
    while (1)
    {
        cout << n;
        if (n == 1)
            break;
        cout << ' ';

        if (n % 3 == 0 && dp_cnt[n / 3] + 1 == dp_cnt[n])
            n = n / 3;
        else if (n % 2 == 0 && dp_cnt[n / 2] + 1 == dp_cnt[n])
            n = n / 2;
        else
            n = n - 1;
    }
}

/* thinking

고정값
dp[1] = 1
dp[2] = 1 2
dp[3] = 1 3
dp[4] = 1 2 4

vector의 모든 요소가 stack을 갖고있으면 메모리초과 
그럼 각 요소에는 size()갯수만 저장하고, 
마지막에 dp[n] -> dp[n / 3] -> dp [(n / 3) / 2] ... 으로 타고가면서 출력..?

*/

