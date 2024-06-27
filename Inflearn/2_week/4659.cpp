#include <iostream>
#include <vector>

using namespace std;

bool isMoeum(const char& c)
{
    const static string Moeum("aeiou");
    for (const char & m : Moeum)
    {
        if (m == c)
            return true;
    }
    
    return false;
}

string solution(const string &s)
{
    const string accept = "<" + s + "> is acceptable.";
    const string naccept = "<" + s + "> is not acceptable.";

    bool have_moeum = false;
    for (int i = 0; i < s.size(); i++)
    {
        bool is_moeum = false;
        if (isMoeum(s[i]))
        {
            have_moeum = true;
            is_moeum = true;
        }

        if (i + 1 < s.size() && isMoeum(s[i + 1]) == is_moeum \
        && i + 2 < s.size() && isMoeum(s[i + 2]) == is_moeum)
            return naccept;
        
        if (i + 1 < s.size() && s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
            return naccept;
    }

    if (!have_moeum)
        return naccept;
    
    return accept;
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