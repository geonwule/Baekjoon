#include <iostream>
#include <vector>

using namespace std;

struct Info
{
    float v, f, c;
};

int solution(const int N, const float D, const vector<Info> &v)
{
    int answer = 0;
    for (const auto &e : v)
    {
        if (e.v * (e.f / e.c) >= D)
            answer++;
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;

    vector<int> answer;

    while (t--)
    {
        int N;
        float D;
        cin >> N >> D;
        vector<Info> v(N);
        for (auto &e : v)
            cin >> e.v >> e.f >> e.c;

        answer.push_back(solution(N, D, v));
    }

    for (auto &e : answer)
        cout << e << endl;
    return 0;
}