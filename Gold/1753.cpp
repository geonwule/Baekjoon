#include <iostream>
#include <vector>

using namespace std;

#define MAX 20000
#include <queue>
#include <unordered_set>


vector<int> solution(const int V, const int K, const vector<vector<int>>& nodes)
{
    vector<int> answer(V + 1, -1);
    answer[K] = 0; //self
    unordered_set<int> visited;

    queue<pair<int, int>> q;
    q.push({K, 0});
    visited.insert(K);

    while(!q.empty())
    {
        int cur = q.front().first;
        int sum = q.front().second;
        q.pop();

        if (cur != K)
        {
            answer[cur] = answer[cur] == -1 ? sum : min(answer[cur], sum);
        }

        for (int next = 1; next <= V; next++)
        {
            if (nodes[cur][next] == 0 || visited.count(next))
                continue;
            visited.insert(next);
            q.push({next, sum + nodes[cur][next]});
        }
    }

    
    return answer;
}

int main()
{
    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<int>> nodes(V + 1, vector<int>(V + 1, 0));
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u][v] = nodes[u][v] == 0 ? w : min(nodes[u][v], w);
    }

    vector<int> answer = solution(V, K, nodes);
    for(size_t i = 1; i < answer.size(); i++)
    {
        if (answer[i] == -1)
            cout << "INF\n";
        else
            cout << answer[i] << '\n';

    }

    //test
    // for (auto y = 0; y < nodes.size(); y++)
    // {
    //     for (auto x = 0; x < nodes.size(); x++)
    //     {
    //         cout << "(" << y << " -> " << x << ")=" << nodes[y][x] << "\n";
    //     }
    // }
}