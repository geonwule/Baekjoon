#include <stdio.h>
#include <stdlib.h>

int parent[1001] = {0, };

int find(int a)
{
    int root, lead;
    for (root = a; parent[root] != 0; root=parent[root]);
    for (int now = a; now != root; now = lead)
    {
        lead = parent[now];
        parent[now] = root;
    }
    return (root);
}

void    uni(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, m, a, b, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a = find(a);
        b = find(b);
        if (a != b)
            uni(a, b);
    }
}

// geonwule
// int arr[1001][1001];

// void arr_init(int m)
// {
//     int a, b;
//     for (int i = 1; i < 1001; i++)
//     {
//         for (int j = 0; j < 1001; j++)
//         {
//             if (j == 0)
//             {
//                 arr[i][j] = -1;
//                 continue ;
//             }
//             arr[i][j] = 0;
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d %d", &a, &b);
//         // if (a < b)
//         // {
//         //     arr[a][b] = 1;
//         //     arr[a][0] = 1;
//         // }
//         // else
//         // {
//         //     arr[b][a] = 1;
//         //     arr[b][0] = 1;
//         // }
//         arr[a][b] = 1;
//         arr[a][0] = 1;
//         arr[b][a] = 1;
//         arr[b][0] = 1;
//     }
// }

// void connected_check(int idx, int n)
// {
//     if (arr[idx][0] == 0)
//         return;
//     arr[idx][0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (arr[idx][i] == 1)
//             connected_check(i, n);
//     }
// }

// int main()
// {
//     int n, m, cnt = 0;
//     scanf("%d %d", &n, &m);
//     if (m == 0)
//     {
//         printf("%d\n", n);
//         return (0);
//     }
//     arr_init(m);
//     for (int i = 1; i <= n; i++)
//     {
//         if (arr[i][0] == 0)
//             continue;
//         if (arr[i][0] == -1)
//         {
//             cnt += 1;
//             continue;
//         }
//         else
//         {
//             arr[i][0] = 0;
//             cnt += 1;
//         }
//         for (int j = i + 1; j <= n; j++)
//         {
//             if (arr[i][j] == 1)
//                 connected_check(j, n);
//         }
//     }
//     printf("%d\n", cnt);
// }