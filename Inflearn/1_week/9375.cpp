#include <map>
#include <vector>
#include <iostream>

using namespace std;

int solution(map<string, int>& mp)
{
    int answer = 1;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        answer *= it->second + 1; // 0개 조합 추가
    }

    return answer - 1; // ALL 0개 조합 제외
}


int main()
{
    vector<int> answer;

    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        map<string, int> mp;
        while (N--)
        {
            string name, kind;
            cin >> name >> kind;
            mp[kind]++;
        }
        answer.push_back(solution(mp));
    }

    for (int ans : answer)
        cout << ans << '\n';

    return 0;
}

void print_mpv(map<string, vector<string>>& mpv)
{
    for (auto it = mpv.begin(); it != mpv.end(); it++)
    {
        cout << "kind = " << it->first << '\n';
        vector<string> &v = it->second;
        cout << "name = ";
        for (string s : v)
            cout << s << ' ';
        cout << '\n';
    }
}