/* 11655 - 1 */

// #include <iostream>
// #include <cstring>

// using namespace std;

// string solution(const string& str)
// {
//     string answer(str);
//     for (char &c : answer)
//     {
//         if (isalpha(c))
//         {
//             if (isupper(c))
//             {
//                 if (c + 13 > 'Z')
//                     c -= 13;
//                 else
//                     c += 13;
//             }
//             else
//             {
//                 if (c + 13 > 'z')
//                     c -= 13;
//                 else
//                     c += 13;
//             }
//         }
//     }
//     return answer;
// }

// int main()
// {
//     string str;
//     getline(cin, str);
//     cout << solution(str);

//     return 0;
// }


/* 9996 - 1*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(const int N, const string& str, const vector<string>& v)
{
    vector<string> answer;

    size_t pos = str.find('*');
    string pre = str.substr(0, pos);
    string suf = str.substr(pos + 1);
    reverse(suf.begin(), suf.end());

    for (const string& s : v)
    {
        string rs(s);
        reverse(rs.begin(), rs.end());

        if (s.size() < pre.size() + suf.size())
            answer.push_back("NE");
        else if (s.find(pre) == 0 && rs.find(suf) == 0)
            answer.push_back("DA");
        else
            answer.push_back("NE");
    }

    return answer;
}

int main()
{
    int N;
    string str;
    cin >> N >> str;

    vector<string> arr(N);
    for (string &s : arr)
        cin >> s;
    
    vector<string> answer = solution(N, str, arr);

    for (string& s : answer)
        cout << s << '\n';

    return 0;
}