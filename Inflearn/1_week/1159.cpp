#include <iostream>
#include <vector>

using namespace std;

int cnt[26];

string solution(const vector<string>& arr)
{
    for (const auto& e : arr)
        cnt[e[0] - 'a']++;

    string answer;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
            answer += 'a' + i;
    }
    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (string &e : v)
        cin >> e;
    
    string answer = solution(v);
    if (answer.empty())
        cout << "PREDAJA";
    else
        cout << answer;
    
    return 0;
}