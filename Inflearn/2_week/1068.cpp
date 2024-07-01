#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vv;
int Del;

int dfs(int idx)
{
    if (vv[idx].empty() || (vv[idx].size() == 1 && vv[idx][0] == Del))
        return 1; //leaf Node

    int answer = 0;
    for (int child : vv[idx])
    {
        if (child == Del)
            continue;
        answer += dfs(child);
    }
    return answer;
}

int solution(int N, vector<int>& v, int del)
{
    int root_idx;
    vv.resize(N, vector<int>());
    for (int i = 0; i < N; i++)
    {
        int parent_idx = v[i];
        if (parent_idx == -1)
        {
            root_idx = i;
            continue;
        }
        vv[parent_idx].push_back(i);
    }
    Del = del;

    if (root_idx == del)
        return 0;
    return dfs(root_idx);
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int &i : v)
        cin >> i;
    int del;
    cin >> del;

    cout << solution(N, v, del);

    return 0;
}