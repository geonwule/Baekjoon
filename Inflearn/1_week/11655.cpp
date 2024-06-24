#include <iostream>

using namespace std;

string solution(const string &str)
{
    string answer(str);

    for (auto &c : answer)
    {
        if (!isalpha(c))
            continue;
        
        if ((isupper(c) && c + 13 > 'Z') || (islower(c) && c + 13 > 'z'))
            c -= 13;
        else
            c += 13;
    }

    return answer;
}

int main()
{
    string str;
    getline(cin, str);

    cout << solution(str);

    return 0;
}