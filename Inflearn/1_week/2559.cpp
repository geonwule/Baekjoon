#include <iostream>
#include <vector>

using namespace std;

int solution(const int K, const vector<int>& arrs)
{
    int answer = 0;

    int sum = 0;
    for (size_t i = 0; i < K; i++)
        sum+=arrs[i];

    answer = sum;
    for (size_t i = 1; i < arrs.size() - K + 1; i++)
    {
        sum = sum - arrs[i-1] + arrs[K - 1 + i];
        answer = max(answer, sum);
    }

    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arrs(N);
    for (auto &arr : arrs)
        cin >> arr;
    
    cout << solution(K, arrs);

    return 0;
}