#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <iomanip> // setprecision() 함수를 사용하기 위한 헤더파일

using namespace std;

int main()
{
    size_t sum = 0;
    string orders[] = {"Re", "Pt" , "Cc" , "Ea" , "Tb" , "Cm" , "Ex" };
    unordered_map<string, int> uoMap;
    for (auto &e : orders)
    {
        uoMap[e] = 0;
    }

    while(true)
    {
        string s;
        cin >> s;
        if (cin.eof())
            break;
        if (uoMap.count(s))
            uoMap[s]++;
        sum++;
    }

    for (auto &e : orders)
    {
        // cout << e << " " << uoMap[e] << ' ' << fixed << setprecision(2) << static_cast<double>(uoMap[e]) / sum << '\n';
        cout << e << " " << uoMap[e] << ' ';
        printf("%.2f\n", (double)uoMap[e] / sum);
    }
    cout << "Total " << sum << " 1.00\n";
    return 0;
}