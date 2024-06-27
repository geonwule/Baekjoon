#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& v, const int K)
{
    vector<int> sum(v.size() + 1, 0);
    for(int i = 0; i < v.size(); i++)
    {
        sum[i + 1] = sum[i] + v[i]; 
    }

    int answer = -100 * 1000000;

    for (int i = K; i <= v.size(); i++)
    {
        int rsum = sum[i] - sum[i - K];
        answer = max(answer, rsum);
    }

    /*
    1 2 3 4 5

    0 1 3 6 10 15

    */

    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int &i : v)
        cin >> i;

    cout << solve(v, K);

    return 0;
}