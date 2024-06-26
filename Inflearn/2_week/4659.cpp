#include <iostream>
#include <vector>

using namespace std;

string solution(const string &s)
{
    string accept = "acceptable.";
    string naccept = "not " + accept;
    bool ck = true;
    string answer;
    answer = "<" + s + "> is ";
    string Moeum("aeiou");

    int cnt = 0, mo_cnt = 0, is_mo = 0;
    char prev = ' ';
    for (const char& c : s)
    {
        if (c == prev && c != 'e' && c != 'o')
        {
            ck = false;
            break;
        }

        int this_is_mo = 0;
        for (const char& mc : Moeum)
        {
            if (c == mc)
            {
                mo_cnt++;
                this_is_mo = 1;
                break;
            }
        }

        if (cnt == 3)
        {
            ck = false;
            break;
        }
    }

    if (ck)
        answer += accept;
    else
        answer += naccept;
    return answer;
}

int main()
{
    vector<string> answer;
    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        answer.push_back(solution(s));
    }

    for (const string &s : answer)
        cout << s << '\n';

    return 0;
}