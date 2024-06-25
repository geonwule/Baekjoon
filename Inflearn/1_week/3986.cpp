#include <iostream>
#include <vector>

using namespace std;

bool is_good(const string& s)
{
    int cnt_a, cnt_b;
    cnt_a = cnt_b = 0;
    for (const char &c : s)
    {
        if (c == 'A')
            cnt_a++;
        else
            cnt_b++;
    }
    if (cnt_a % 2 == 1 || cnt_b % 2 == 1)
        return false;

    char target = 0, target2 = 0;
    for (const char &c : s)
    {
        if (target == 0)
            target = c;
        else if (c == target && target2 != 0)
            return false;
        else if (c == target)
            target = 0;
        else
        {
            if (target2 == 0)
                target2 = c;
            else
                target2 = 0;
        }
    }
    
    return true;
}

#include <stack>

int solution(vector<string> v)
{
    int answer = 0;
    for (const string &s : v)
    {
        // if (is_good(s))
        //     answer++;
        stack<char> stk;
        for (const char& c: s)
        {
            if (!stk.empty() && stk.top() == c) stk.pop();
            else
                stk.push(c);
        }
        if (stk.empty())
            answer++;
    }
    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (string &s : v)
        cin >> s;
    
    cout << solution(v);

    return 0;
}