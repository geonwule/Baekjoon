#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<vector<int>> vv;
// vector<int> visited;
// int dfs(int idx)
// {
//     visited[idx] = 1;
//     if (vv[idx].empty())
//         return (1);

//     int answer = 1;
//     for (int i : vv[idx])
//     {
//         if (!visited[i])
//         {
//             answer += dfs(i);
//         }
//     }
//     return answer;
// }

// #include <tuple>

// bool comp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
    
//     return a.first > b.first;
// }

// vector<int> solution(int N, int M, vector<pair<int, int>>& vp)
// {
//     vv.resize(N + 1, vector<int>());
//     for (auto &p : vp)
//     {
//         int child = p.first;
//         int parent = p.second;
//         vv[parent].push_back(child);
//     }
//     vector<pair<int, int>> da;

//     visited.resize(N + 1, 0);
//     for (int i = 1; i <= N; i++)
//     {
//         fill(visited.begin(), visited.end(), 0);
//         da.push_back({dfs(i), i});
//     }

//     sort(da.begin(), da.end(), comp);
//     int sum = da[0].first;

//     int idx, ssum;
//     vector<int> answer;
//     for (auto &p : da)
//     {
//         tie(ssum, idx) = p;
//         if (ssum != sum)
//             break;
//         answer.push_back(idx);
//     }
//     return answer;
// }


vector<vector<int>> vv;
vector<int> visited;
vector<int> arr;

int dfs(int idx)
{
    visited[idx] = 1;

    int answer = 1;
    for (int i : vv[idx])
    {
        if (visited[i])
            continue;
        answer += dfs(i);
    }

    return answer;
}

vector<int> solution2(int N, int M, vector<pair<int, int>>& vp)
{
    vv.resize(N + 1, vector<int>());
    for (auto &p : vp)
    {
        int child = p.first;
        int parent = p.second;
        vv[parent].push_back(child);
    }
    
    visited.resize(N + 1, 0);
    arr.resize(N + 1, 0);
    int mx = 0;
    for (int i = 1; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), 0);
        arr[i] = (dfs(i));
        mx = max(mx, arr[i]);
    }

    vector<int> answer;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != mx)
            continue;
        answer.push_back(i);
    }

    return answer;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> vp(M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }

    // vector<int> answer = solution(N, M, vp);
    vector<int> answer = solution2(N, M, vp);

    sort(answer.begin(), answer.end());
    for (const int i : answer)
        cout << i << ' ';

    return 0;
}