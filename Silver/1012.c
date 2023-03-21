#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_vars
{
    int x;
    int y;
} t_vars;

int cabbage[51][51];
t_vars location[2500];

void cabbage_init()
{
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
            cabbage[i][j] = 0;
    }
}

int dfs(int x, int y)
{
    if (cabbage[y][x] == 0)
        return (0);
    cabbage[y][x] = 0;
    if (x - 1 >= 0 && cabbage[y][x - 1] == 1)
        dfs(x - 1, y);
    if (x + 1 <= 50 && cabbage[y][x + 1] == 1)
        dfs(x + 1, y);
    if (y - 1 >= 0 && cabbage[y - 1][x] == 1)
        dfs(y - 1, x);
    if (y + 1 <= 50 && cabbage[y + 1][x] == 1)
        dfs(y + 1, x);
    return (1);
}

void input_set(int k)
{
    for (int j = 0; j < k; j++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        cabbage[y][x] = 1;
        location[j].x = x;
        location[j].y = y;
    }
}

int main()
{
    int test, m, n, k;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int worm = 0;
        scanf("%d %d %d", &m, &n, &k);
        cabbage_init();
        input_set(k);
        for (int j = 0; j < k; j++)
        {
            if (dfs(location[j].x, location[j].y))
                worm++;
        }
        printf("%d\n", worm);
    }
}