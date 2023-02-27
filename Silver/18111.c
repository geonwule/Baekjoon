#include <stdio.h>
#include <stdlib.h>

int **map_copy(int x, int y, int **dest)
{
    int **map;

    map = (int **)malloc(sizeof(int *) * y);
    for (int i = 0; i < y; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * x);
        for (int j = 0; j < x; j++)
        {
            map[i][j] = dest[i][j];
        }
    }
    return (map);
}

int **map_init(int y, int x, int *min_c, int *max_c)
{
    int **map, min = -1, max = -1;

    map = (int **)malloc(sizeof(int *) * y);
    for (int i = 0; i < y; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * x);
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &map[i][j]);
            if (min == -1 || min > map[i][j])
            {
                min = map[i][j];
            }
            if (max == -1 || max < map[i][j])
            {
                max = map[i][j];
            }
        }
    }
    *min_c = min;
    *max_c = max;
    return (map);
}

void mal_free(int **map, int y)
{
    for (int i = 0; i < y; i++)
        free(map[i]);
    free(map);
}

int block_play(int **map, int x, int y, int b, int max_h, int *ret)
{
    int time = 0;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (map[i][j] == max_h)
                continue;
            else if (map[i][j] < max_h)
            {
                b -= (max_h - map[i][j]);
                time += (max_h - map[i][j]);
                map[i][j] = max_h;
            }
            else if (map[i][j] > max_h)
            {
                b += (map[i][j] - max_h);
                time += (2 * (map[i][j] - max_h));
                map[i][j] = max_h;
            }
        }
    }
    if (b < 0)
        return (0);
    ret[0] = time;
    ret[1] = map[0][0];
    return (1);
}

int *mine_craft(int **map, int b, int x, int y, int min_h, int max_h)
{
    int temp[2], height = 0, time = 0;
    int *ret = (int *)malloc(sizeof(int) * 2);
    int **map_temp;

    ret[0] = -1;
    while (max_h >= min_h)
    {
        map_temp = map_copy(x, y, map);
        if (block_play(map_temp, x, y, b, max_h, temp))
        {
            if (ret[0] == -1 || ret[0] > temp[0])
            {
                ret[0] = temp[0];
                ret[1] = temp[1];
            }
        }
        max_h--;
        mal_free(map_temp, y);
    }
    return (ret);
}

int main()
{
    int y, x, b, min, max, **map;
    int *ret;

    scanf("%d %d %d", &y, &x, &b);
    map = map_init(y, x, &min, &max);
    ret = mine_craft(map, b, x, y, min, max);
    printf("%d %d\n", ret[0], ret[1]);
    free(ret);
    mal_free(map, y);
}

// printf("min = %d, min_n = %d\nmax = %d, max_n = %d\n", min[1], min[0], max[1], max[0]);