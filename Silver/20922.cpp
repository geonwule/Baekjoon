#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std;
#define MAX 100000

int solution(const int N, const int K, const vector<int> &v)
{
    int answer = 0;
    vector<int> size_numbers(MAX + 1, 0);
    unordered_set<int> visited;

    vector<int>::const_iterator left, right;
    left = right = v.begin();

    int cnt = 0;
    while(right != v.end())
    {
        int rv = *right;
        if (size_numbers[rv] == 0)
            visited.insert(rv);
        size_numbers[rv]++;
        cnt++;

        while (visited.size() > K)
        {
            int lv = *left;
            size_numbers[lv]--;
            cnt--;
            if (size_numbers[lv] == 0)
                visited.erase(lv);
            
            left++;
        }

        answer = max(answer, cnt);
        right++;
    }

    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for(auto &e : v)
        cin >> e;
    
    cout << solution(N, K, v);

    return 0;
}