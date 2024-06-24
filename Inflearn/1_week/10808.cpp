#include <iostream>

using namespace std;

int cnt[26];

void solution(const string &str)
{
    for (const char &c : str)
        cnt[c - 'a']++;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin >> str;
    solution(str);

    for (int i = 0; i < 26; i++)
        cout << cnt[i] << ' ';

    return 0;
}