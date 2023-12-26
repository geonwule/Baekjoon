#include <iostream>

using namespace std;

string phoneCombi;

int main()
{
    string phoneA, phoneB;

    cin >> phoneA >> phoneB;
    for (int i = 0; i < 8; i++)
    {
        phoneCombi += phoneA[i];
        phoneCombi += phoneB[i];
    }

    while (phoneCombi.size() > 2)
    {
        string tmp;
        for (string::iterator it = phoneCombi.begin(); it != phoneCombi.end();)
        {
            int a = (*it) - '0';
            it++;
            if (it == phoneCombi.end())
                break;
            int b = (*it) - '0';
            tmp += (a + b) % 10 + '0';
        }
        phoneCombi = tmp;
    }

    cout << phoneCombi;
}