#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> solve(vector<string>& v)
{
    vector<string> answer;
    for (string &s : v)
    {
        stack<char> st;
        bool ck = true;
        for (char &c : s)
        {
            if (c == '(' || c == '[')
                st.push(c);
            else
            {
                if (c == ')' && st.size() && st.top() == '(')
                    st.pop();
                else if (c == ']' && st.size() && st.top() == '[')
                    st.pop();
                else if (c == ')' || c == ']')
                {
                    ck = false;
                    break;
                }
            }
        }

        if (ck && st.empty())
            answer.push_back("yes");
        else
            answer.push_back("no");
    }
    return answer;
}

int main()
{
    vector<string> answer, orders;
    while(1)
    {
        string s;
        getline(cin, s);
        if (s == ".")
            break;
        orders.push_back(s);
    }
    answer = solve(orders);

    for (const auto &a : answer)
        cout << a << '\n';

    return 0;
}