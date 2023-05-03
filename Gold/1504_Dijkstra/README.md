다익스트라 알고리즘(Dijkstra)
: 가중그래프에서 최단경로를 찾는 알고리즘 중 하나이다.
주어진 출발점으로부터 다른 모든 정점까지의 최단경로를 찾는것이 가능하다.

핵심아이디어
: 시작정점에서부터 각 정점까지의 거리를 최단거리로 초기화하고, 방문하지 않은 정점 중에서 가장 최단거리를 갖는 정점을 선택하고, 그 정점과 인접한 정점들의 거리를 갱신하는 것이다. 이 과정을 모든 정점을 방문할때까지 반복하면, 모든 정점까지의 최단경로를 구할 수 있다.

1. 다익스트라 알고리즘 예시
    1) 출발점을 기준으로 모든정점의 거리를 무한대로 초기화
    2) 현재 방문하지 않은 정점중에서 출발점에서부터 가장 가까운 정점을 선택.
    3) 선택한 정점과 인접한 정점들의 거리를 갱신
    4) 2,3번 과정을 모든정점 방문시까지 반복.