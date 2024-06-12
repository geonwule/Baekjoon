#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
    bool is_road;
    int start, goal;
    int drop_item;
    int need_item_size;
    vector<int> need_item_list;
};


#include <queue>

void search_road(const int N, vector<vector<Node>> &nodes, queue<Node> &q, unordered_set<int> &visited, unordered_set<int> &my_items)
{
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (visited.count(cur.goal))
            continue;

        bool  satisfy_condition = true;
        for (auto need_item : cur.need_item_list)
        {
            if (!my_items.count(need_item))
            {
                satisfy_condition = false;
                break;
            }
        }

        if(satisfy_condition)
        {
            visited.insert(cur.goal);
            my_items.insert(cur.drop_item);
            for (int i = 1; i <= N; i++)
            {
                if (nodes[cur.goal][i].is_road)
                    q.push(nodes[cur.goal][i]);
            }
        }
    }
}

int main()
{
    unordered_set<int> visited;
    visited.insert(1);

    int N, M, K, S;
    cin >> N >> M >> K >> S;
    unordered_set<int> my_items;
    vector<vector<Node>> nodes(N + 1);
    for (int i = 1; i <= N; i++)
    {
        nodes[i].resize(N + 1, {false});
        //test
        // for (int j = 1; j<= N; j++)
        // {
        //     cout << boolalpha << nodes[i][j].is_road << ' ';
        // }
        // cout << '\n';
    }

    for (int i = 0; i < S; i++)
    {
        int item;
        cin >> item;
        my_items.insert(item);
    }

    while (M--)
    {
        int U, V, W, C;
        cin >> U >> V >> W >> C;
        vector<int> need_items(C);
        for (int i = 0; i < C; i++)
            cin >> need_items[i];
        nodes[U][V] = {true, U, V, W, C, need_items};
    }

    queue<Node> q;
    for (int i = 1; i <= N; i++)
    {
        if (nodes[1][i].is_road && !visited.count(nodes[1][i].goal))
            q.push(nodes[1][i]);
    }

    search_road(N, nodes, q, visited, my_items);

    //test
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j<= N; j++)
    //     {
    //         if (nodes[i][j].is_road)
    //         {
    //             cout << i << "->" << j << " : ";
    //             cout <<  "nodes[i][j].drop_item = " << nodes[i][j].drop_item << ", ";
    //             cout << "nodes[i][j].need_item_size = " << nodes[i][j].need_item_size << '\n';
    //         }
    //     }
    //     cout << '\n';
    // }

    cout << visited.size();
}