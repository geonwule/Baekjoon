#include <stdio.h>

int arr[1025][1025], acc[1025][1025];

//printf("x = %d y = %d\nacc[%d][%d] = %d\n", j, i, i, j, acc[i][j]);

int section_sum(int x1, int y1, int x2, int y2)
{
    int sum = 0;
    for (int y = y1; y <= y2; y++)
    {
        sum += acc[y][x2] - acc[y][x1 -1];
    }
    return (sum);
}

int main()
{
    int n, m;
    scanf ("%d %d", &n, &m);
    acc[0][n] = 0;
    for (int i = 1; i <= n; i++)
    {
        acc[i][0] = acc[i - 1][n];
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
            acc[i][j] = acc[i][j - 1] + arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", section_sum(x1,y1,x2,y2));
    }
}