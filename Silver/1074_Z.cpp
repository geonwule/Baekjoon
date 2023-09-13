#include <iostream>
#include <cmath>
#include <string>

#define MAX 32768

int n, r, c;

// int arr[MAX][MAX] = {0, };
// bool visited[MAX][MAX] = {false, };
int **arr;
bool **visited;

int cnt = 0;

void    set_input(int z)
{
    for (int y = 0; y < z; y++)
    {
        for (int x = 0; x < z; x++)
        {
            if (visited[y][x])
                continue ;
            arr[y][x] = cnt++;
            visited[y][x] = true;
        }
    }
}

int main()
{
    std::cin >> n >> r >> c;
    int N = pow(2, n);
    arr = new int *[N];
    visited = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
        visited[i] = new bool[N];
        memset(visited[i], false, N * sizeof(bool));
    }
    std::cout << recursive(r, c);
}