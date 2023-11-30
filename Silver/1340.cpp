#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string eng_mon[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int m_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
    string MM, DD, TIME;
    int YY;
    cin >> MM >> DD >> YY >> TIME;

    int amount = 365;
    double res;
    if (YY % 100 != 0 && (YY % 400 == 0 || YY % 4 == 0))
    {
        amount = 366;
        m_arr[1] = 29;
    }
    amount = amount * 24 * 60;
    int daysum = 0;

    for (int i = 0; i < 12; i++)
    {
        if (MM == eng_mon[i])
        {
            daysum += atoi(DD.c_str());
            break ;
        }
        daysum += m_arr[i];
    }

    int HH, MM;
    istringstream iss(TIME);
    iss >> HH >> MM;

}

/*
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    string month, time, day;
    string eng_mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year, daysum = 0, hour, min, totalmin;

    cin >> month >> day >> year >> time;

    int m_arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        m_arr[1] = 29;
        totalmin = 366 * 24 * 60;
    } else {
        totalmin = 365 * 24 * 60;
    }

    auto it = find(begin(eng_mon), end(eng_mon), month);
    if (it != end(eng_mon)) {
        daysum += accumulate(begin(m_arr), next(begin(m_arr), distance(begin(eng_mon), it)), 0);
    }

    daysum += stoi(day) - 1;
    hour = stoi(time.substr(0, 2));
    min = stoi(time.substr(3, 2));

    int minsum = daysum * 24 * 60 + hour * 60 + min;

    double result = static_cast<double>(minsum) / totalmin * 100;
    printf("%0.9f\n", result);

    return 0;
}

*/