#include <iostream> // std::cout
#include <vector> // std::vector
#include <queue> // std::priority_queue
#include <unordered_set> // std::unordered_set

// 노드 구조체
struct Node {
    int x, y;  // 노드의 좌표
    int g, h;  // 출발지부터의 실제 거리(g), 휴리스틱 거리(h)
    Node* parent;  // 이전 경로에 있는 노드

    Node(int x, int y) : x(x), y(y), g(0), h(0), parent(nullptr) {}

    // f(x) = g(x) + h(x) 계산하는 함수
    int getScore() {
        return g + h;
    }
};

// 맨해튼 거리 : 두 점 사이의 거리를 구할 때, 가로, 세로 방향으로만 이동할 수 있다고 가정했을 때의 거리
// 맨해튼 거리를 휴리스틱으로 사용
int heuristic(Node* node, Node* goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// A* 알고리즘 함수
std::vector<Node*> astar(Node* start, Node* goal) {
    std::unordered_set<std::string> visited;  // 방문한 노드 저장
    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> pq(
        [](Node* a, Node* b) { return a->getScore() > b->getScore(); });  // f(x) 값으로 정렬된 우선순위 큐

    start->h = heuristic(start, goal);  // 시작 노드의 휴리스틱 값 설정
    pq.push(start);

    while (!pq.empty()) {
        Node* current = pq.top();  // 가장 작은 f(x) 값을 가진 노드 선택
        pq.pop();

        // 목적지에 도착했다면 경로 반환
        if (current->x == goal->x && current->y == goal->y) {
            std::vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            return path;
        }

        // 이미 방문한 노드라면 무시
        std::string id = std::to_string(current->x) + "," + std::to_string(current->y);
        if (visited.count(id)) continue;
        visited.insert(id);

        // 상하좌우 인접 노드 탐색
        static const int dx[4] = {0, 0, 1, -1};
        static const int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            // 새로운 노드 생성
            Node* neighbor = new Node(nx, ny);
            neighbor->parent = current;
            neighbor->g = current->g + 1;  // 이전 노드까지의 거리 + 1
            neighbor->h = heuristic(neighbor, goal);  // 휴리스틱 값 계산

            pq.push(neighbor);  // 우선순위 큐에 새로운 노드 추가
        }
    }

    // 목적지까지 경로를 찾지 못한 경우 빈 벡터 반환
    return std::vector<Node*>();
}

int main() {
    Node* start = new Node(0, 0);  // 시작 노드
    Node* goal = new Node(3, 3);  // 목적지 노드

    std::vector<Node*> path = astar(start, goal);

    // 경로 출력
    for (Node* node : path) {
        std::cout << "(" << node->x << ", " << node->y << ") ";
    }
    std::cout << std::endl;

    // 메모리 해제
    for (Node* node : path) {
        delete node;
    }

    return 0;
}