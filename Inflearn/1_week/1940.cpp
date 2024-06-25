#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int N, M, R = 2;
vector<int> v;

int solution2()
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == M)
                cnt++;
        }
    }

    return cnt;
}

void combi(int start, int sum, vector<int> &b)
{
    if (b.size() == R)
    {
        if (sum == M)
            cnt++;
        return;
    }

    for (int i = start + 1; i < N; i++)
    {
        b.push_back(v[i]);
        combi(i, sum + v[i], b);
        b.pop_back();
    }
}

int solution()
{
    vector<int> b;
    combi(-1, 0, b);
    return cnt;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> N >> M;

    v.resize(N);
    for (int &i : v)
        cin >> i;

    // cout << solution();
    cout << solution2();

    return 0;
}
