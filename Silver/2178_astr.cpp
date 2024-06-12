#include <iostream> // cout
#include <queue> // priority_queue
#include <vector> // vector
#include <unordered_set> // unordered_set

#define MAX 101
using namespace std;

struct Node
{
    int x, y; //pos
    int g, h; //g(real distance), h(heuristic distance)
    Node *parent;

    Node(int _x, int _y) : x(_x), y(_y), g(0), h(0), parent(nullptr) {}

    int getScore() { return g + h; }
    std::string getPos()
    {
        string pos;
        pos = "(" + to_string(x) + "," + to_string(y) + ")";
        return pos;
    }
};

//Uqlid distance
int heuristic(Node *a, Node *b)
{
    return abs(a->x - b->x) + abs(a->y - b->y);
}

int N, M, arr[MAX][MAX];

vector<Node *>  astar(Node *start, Node *goal)
{
    unordered_set<string> visited;
    priority_queue<Node *, vector<Node *>, function<bool(Node *, Node *)>> pq(
        [](Node *a, Node *b) {return a->getScore() > b->getScore();});

    start->h = heuristic(start, goal);
    pq.push(start);

    while (!pq.empty())
    {
        Node *cur = pq.top();
        pq.pop();

        //made goal
        if (cur->x == goal->x && cur->y == goal->y)
        {
            vector<Node *> answer;
            while (cur)
            {
                answer.push_back(cur);
                cur = cur->parent;
            }
            return answer;
        }

        //visited check
        string id = to_string(cur->x) + "," + to_string(cur->y);
        if (visited.count(id))
            continue;
        visited.insert(id);

        //search up, down, left, right
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int nx = cur->x + dx[i];
            int ny = cur->y + dy[i];

            //except map
            if (nx < 1 || ny < 1 || nx > M || ny > N || arr[ny][nx] == 0)
                continue;
            
            Node *neighbor = new Node(nx, ny);
            neighbor->g = cur->g + 1; //distance (start - cur loc)
            neighbor->h = heuristic(neighbor, goal); //distance heuristic (cur loc - goal)
            neighbor->parent = cur;
            pq.push(neighbor);
        }
    }

    return vector<Node *>();
}

int main()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < M; x++)
        {
            arr[y+1][x+1] = line[x] - '0';
        }
    }

    Node *start = new Node(1, 1);
    Node *goal = new Node(M, N);

    vector<Node *> answer = astar(start, goal);

    //free memory
    for (auto i = answer.size() - 1; i >= 0; i--)
    {
        Node *cur = answer[i];
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= M; x++)
            {
                if (cur->x == x && cur->y == y)
                {
                    cout << '*';    
                }
                else
                    cout << arr[y][x];
            }
            cout << '\n';
        }
        cout << "\n";
    }

    for (Node * node : answer)
    {
        // cout << node->getPos() << endl;

        delete node;
    }
}