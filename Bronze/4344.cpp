#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

float solution(const int N, const vector<float>& v)
{
    float answer = 0.0f;
    float average = 0.0f;
    for (const auto &e : v)
        average += e;
    average /= N;
    // cout << "rev = "<< average <<'\n';

    int over_num = 0;
    for (const auto &e : v)
    {
        if (e > average)
            over_num++;
    }

    answer = (float)over_num / N * 100;

    return answer;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<float> v(N);
        for (auto &e : v)
            cin >> e;
        printf("%.3f%\n", solution(N, v));
    }
}