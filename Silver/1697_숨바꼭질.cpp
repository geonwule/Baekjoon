#include <iostream>
#include <limits.h>
#include <queue>
#include <iomanip>

int N, K;
bool    visited[100001] = {false ,};
size_t  sec[100001] = {0, };
std::queue<int> q;

void    print_path()
{
    std::cout << "PATH\n";
    for (int i = N; i <= K; i++)
        std::cout << std::setw(3) << i;
    std::cout << std::endl;
    for (int i = N; i <= K; i++)
        std::cout << std::setw(3)<< sec[i];
    std::cout << std::endl;
}

void    bfs(int location)
{
    sec[location] = 0;
    visited[location] = true;
    q.push(location);
    while (!q.empty())
    {
        int pt = q.front();
        q.pop();
        if (pt == K)
            break ;
        if (!visited[pt + 1] && pt + 1 >= 0 && pt + 1 <= 100000)
        {
            visited[pt + 1] = true;
            q.push(pt + 1);
            sec[pt + 1] = sec[pt] + 1;
        }
        if (!visited[pt - 1] && pt - 1 >= 0 && pt - 1 <= 100000)
        {
            visited[pt - 1] = true;
            q.push(pt - 1);
            sec[pt - 1] = sec[pt] + 1;
        }
        if (!visited[pt * 2] && pt * 2 >= 0 && pt * 2 <= 100000)
        {
            visited[pt * 2] = true;
            q.push(pt * 2);
            sec[pt * 2] = sec[pt] + 1;
        }
    }
}

int main()
{

    std::cin >> N >> K;
    bfs(N);
    print_path();
    std::cout << sec[K];
}