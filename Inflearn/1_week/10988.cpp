#include <iostream>

using namespace std;

int solution(const string &str)
{
    int front = 0, back = str.size() - 1;

    while (front < back)
    {
        if (str[front] != str[back])
            return 0;
        front++;
        back--;
    }

    return 1;
}

#include <algorithm>
int solution2(const string &str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());

    if (str == temp)
        return 1;
    
    return 0;
}

int main()
{
    string str;
    cin >> str;

    // cout << solution(str);
    cout << solution2(str);

    return 0;
}