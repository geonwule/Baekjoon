#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &str, const string &sep)
{
    vector<string> answer;

    string input(str);
    size_t pos;
    while ((pos = input.find(sep)) != string::npos)
    {
        string temp = input.substr(0, pos);
        if (temp != "")
            answer.push_back(temp);
        input = input.substr(pos + sep.size(), input.size());
    }
    answer.push_back(input);

    return answer;
}

vector<string> solution(const string &pattern, const vector<string>& str)
{
    vector<string> split_pattern = split(pattern, "*");

    vector<string> answer;
    for (const string &s : str)
    {
        bool possible = false;

        string line(s);
        size_t pos;
        if ((pos = line.find(split_pattern[0])) != string::npos && pos == 0)
        {
            line = line.substr(pos + split_pattern[0].size());
            while ((pos = line.find(split_pattern[1])) != string::npos)
            {
                if (pos + split_pattern[1].size() == line.size())
                {
                    possible = true;
                    break ;
                }
                line = line.substr(pos + split_pattern[1].size());
            }
        }
        
        if (possible)
            answer.push_back("DA");
        else
            answer.push_back("NE");
    }
    return answer;
}

vector<string> solution2(const string &pattern, const vector<string>& str)
{
    vector<string> answer;
    size_t sep_pos = pattern.find('*');
    string pre = pattern.substr(0, sep_pos);
    string suf = pattern.substr(sep_pos + 1);

    for (const auto &s : str)
    {
        bool possible = false;

        if (s.size() >= pre.size() + suf.size())
        {
            if (s.find(pre) == 0 && s.substr(s.size() - suf.size()) == suf)
                possible = true;
        }

        if (possible)
            answer.emplace_back("DA");
        else
            answer.emplace_back("NE");
    }
    return answer;
}

int main()
{
    int N;
    string pattern;

    cin >> N >> pattern;
    vector<string> str(N);
    for (string &s : str)
        cin >> s;
    
    // vector<string> answer = solution(pattern, str);
    vector<string> answer = solution2(pattern, str);
    for (const string &s : answer)
        cout << s << '\n';
    return 0;
}