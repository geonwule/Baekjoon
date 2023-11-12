#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
vector<string> vRet;

int main()
{
    // string arr = "abcwwewssadsdw";
    // string tm = "a";
    // cout << arr.find(tm);

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string tmp;
        cin >> tmp;
        if (vRet.empty())
        {
            vRet.push_back(tmp);
            continue;
        }
        bool is_double = false;
        for (int i = 0; i < vRet.size(); i++)
        {
            if (vRet[i].find(tmp) == 0) // double
            {
                if (vRet[i].size() < tmp.size())
                {
                    vRet.erase(vRet.begin() + i);
                    vRet.push_back(tmp);
                }
                is_double = true;
                break ;
            }
            if (tmp.find(vRet[i]) == 0) // double
            {
                if (vRet[i].size() < tmp.size())
                {
                    vRet.erase(vRet.begin() + i);
                    vRet.push_back(tmp);
                }
                is_double = true;
                break ;
            }
        }
        if (!is_double)
            vRet.push_back(tmp);
    }
    cout << vRet.size();
    // for (int i = 0; i < vRet.size(); i++)
    // {
    //     cout << vRet[i] << ' ';
    // }
}