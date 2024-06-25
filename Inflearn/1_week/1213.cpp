#include <iostream>
#include <map>

using namespace std;

string solution(const string &str)
{
    string answer = "";

    map<char, int> mp;
    for (const char c : str)
        mp[c]++;
    
    if (mp.size() == 1) // 종류 1개
        return string(str);

    if (str.size() % 2 == 0) // 짝수
    {
        bool possible = true;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % 2 == 1) // 하나라도 홀수가 있으면 불가능
            {
                possible = false;
                break;
            }
            answer.insert(answer.size() / 2, string(it->second, it->first));
        }
        
        if (!possible)
        {
            answer = "";
        }
    }
    else // 홀수
    {
        int cnt_holsu = 0;
        char holsu_char;
        bool possible = true;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % 2 == 1) // 홀수 일때
            {
                cnt_holsu++;
                holsu_char = it->first;
                answer.insert(answer.size() / 2, string(it->second - 1, it->first));
            }
            else // 짝수 일때
            {
                answer.insert(answer.size() / 2, string(it->second, it->first));
            }

            if (cnt_holsu > 1)
            {
                possible = false;
                break;
            }
        }

        if (!possible)
            answer = "";
        else
        {
            answer.insert(answer.size() / 2, string(1, holsu_char));
        }
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;

    string answer = solution(s);
    if (answer == "")
        cout << "I'm Sorry Hansoo";
    else
        cout << answer;
    
    return 0;
}