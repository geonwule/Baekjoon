#include <iostream>

using namespace std;

void switchX(int x, const char *str)
{
    switch (x)
    {
    case 0:
        /* code */
        break;

    default:
        break;
    }
}

char checkSell2(const char *arr, char a)//"AGCT"
{
    char res;

    switch (a)
    {
    case 'A':
        res = arr[0];
        break;
    case 'G':
        res = arr[1];
        break;
    case 'C':
        res = arr[2];
        break;
    case 'T':
        res = arr[3];
        break;
    }
    return res;
}

char checkSell(char a, char b)//"AGCT"
{
    char res;
    if (a == b)
        res = a;
    switch (a)
    {
    case 'A':
        res = checkSell2("ACAG", b);
        break;
    case 'G':
        res = checkSell2("CGTA", b);
        break;
    case 'C':
        res = checkSell2("ATCG", b);
        break;
    case 'T':
        res = checkSell2("GAGT", b);
        break;
    }
    return res;
}

int main()
{
    int size;
    string str;
    cin >> size >> str;

    int idx = size;
    char cur;
    while (1)
    {
        idx--;
        cur = str[idx];
        if (idx == 0)
            break;
        str[idx - 1] = checkSell(str[idx], str[idx - 1]);
    }
    cout << cur;
}