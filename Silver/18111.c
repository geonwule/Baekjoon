#include <stdio.h>
#include <stdlib.h>

int **map_init(int y, int x, int *min, int *max)
{
    int **map;

    map = (int **)malloc(sizeof(int *) * y);
    for (int i = 0; i < y; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * x);
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &map[i][j]);
            if (min[0] == 0 || min[1] > map[i][j])
            {
                min[0] = 1;
                min[1] = map[i][j];
            }
            else if (min[1] == map[i][j])
            {
                min[0] += 1;
            }
            if (max[0] == 0 || max[1] < map[i][j])
            {
                max[0] = 1;
                max[1] = map[i][j];
            }
            else if (max[1] == map[i][j])
            {
                max[0] += 1;
            }
        }
    }
}

void    mal_free(int **map, int y)
{
    for (int i = 0; i < y; i++)
        free(map[i]);
    free(map);
}

void    mine_craft(int **map, int b, int x, int y, int *min, int *max, int *ret)
{
    if (max[0] >= min[0] && b - min[0] >= 0)    // 쌓기 1초
    {
        
    }
    else if (max[0] < min[0])   // 깎기 2초
}

int main()
{
    int y, x, b, min[2] = {0, }, max[2] = {0, }, **map, ret[2] = {0, };

    scanf("%d %d %d", &y, &x, &b);
    map = map_init(y, x, min, max);
    mine_craft(map, b, x, y, min, max, ret);
    printf("%d %d\n", ret[0], ret[1]);
    mal_free(map, y);
}

//printf("min = %d, min_n = %d\nmax = %d, max_n = %d\n", min[1], min[0], max[1], max[0]);