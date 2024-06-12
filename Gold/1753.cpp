#include <iostream>
#include <vector>

using namespace std;

enum e_node_element
{
    INIT_VALUE = 11,
    NOTHING = -1,
};

#include <unordered_set>
#include <queue>
struct Node
{
    int pos, sum;
};

bool comp(Node &a, Node &b)
{
    return a.sum > b.sum;
}

#include <map>
int search(const vector<map<int, int>>& nodes, const int start, const int goal, const int V)
{
    int result = NOTHING;
    unordered_set<int> visited;
    priority_queue<Node, vector<Node>, bool(*)(Node&, Node&)> q(comp);
    // queue<Node> q;
    q.push({start, 0});
    while (!q.empty())
    {
        Node cur = q.top();
        // Node cur = q.front();
        q.pop();

        if (cur.pos == goal)
        {
            if (result == NOTHING || cur.sum < result)
                result = cur.sum;
            break ;
        }

        if (visited.count(cur.pos))
            continue;
        visited.insert(cur.pos);

        const map<int, int> &cur_map = nodes[cur.pos];
        for (auto it = cur_map.begin(); it != cur_map.end(); it++)
        {
            Node neighbor = {it->first, cur.sum + it->second};
            q.push(neighbor);
        }
    }

    return result;
}


void test()
{
    map<int, int> maps;
    maps[1] = 10;
    maps[2] = 20;
    maps[3] = 30;
    maps[4] = 40;
    maps[5] = 50;

    for(auto it = maps.begin(); it != maps.end(); it++)
    {
        cout << "first = " << it->first << ", second = " << it->second << endl;
    }
}

int main()
{
    // test();
    // return 0;

    // 1 <= V <= 20,000 정점의 수
    // 1 <= E <= 300,000 간선의 수
    int V, E;
    int start;
    cin >> V >> E >> start;


    vector<map<int, int>> nodes(V + 1);

    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        map<int, int> &cur = nodes[u];
        map<int, int>::iterator it = cur.find(v);
        if (it != cur.end()) //double
        {
            cur[v] = min(cur[v], w);
        }
        else
            cur[v] = w;
    }

    vector<int> result(V + 1, NOTHING);

    for (int i = 1; i <= V; i++)
    {
        if (i == start)
        {
            cout << "0\n";
            continue;
        }
        result[i] = search(nodes, start, i, V);
        if (result[i] == NOTHING)
            cout << "INF\n";
        else
            cout << result[i] << '\n';
    }

    return 0;
}