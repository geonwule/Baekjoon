#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> &solution(const int N, const vector<int> &sizes, const int T, const int P)
{
    static vector<vector<int>> answer(2);
    int n_Tshirts, n_pens, n_pen;

    n_Tshirts = n_pens = n_pen = 0;
    //T-shirts
    for (const auto &size : sizes)
    {
        if (size == 0)
            continue;
        n_Tshirts += size / T;
        if (size % T)
            n_Tshirts += 1;
    }
    answer[0].push_back(n_Tshirts);

    //pens
    answer[1].push_back(N / P);
    answer[1].push_back(N % P);

    return answer;
}

int main()
{
    int N;

    cin >> N;
    vector<int> v(6);
    for (auto &e : v)
        cin >> e;
    int T, P;
    cin >> T >> P;

    vector<vector<int>> &answer = solution(N, v, T, P);

    for (auto &v : answer)
    {
        for (auto &e : v)
            cout << e << ' ';
        cout << '\n';
    }
}