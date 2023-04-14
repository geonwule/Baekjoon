#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
    int x;
    int y;
}   t_vars;

int n, m, map[50][50];
int home_num = 0, ch_store = 0, ch_distance[13];
t_vars ch_location[13], home_location[101];
int ch_idx = 0, home_idx = 0;

void    input_init(void)
{
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &map[y][x]);
            if (map[y][x] == 2)
            {
                ch_store++;
                ch_location[ch_idx].x = x;
                ch_location[ch_idx++].y = y;
            }
            if (map[y][x] == 1)
            {
                home_num++;
                home_location[home_idx].x = x;
                home_location[home_idx++].y = y;
            }
        }
    }
}
#include <limits.h>

int dis_check(t_vars home, t_vars chicken)
{
    int x, y;
    x = home.x - chicken.x;
    y = home.y - chicken.y;
    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    return (x + y);
}

// fail
int    chicken_distance(t_vars *s_chicken, int s_ch_idx)
{
    int distance = 0;
    for (int i = 0; i < home_idx; i++)
    {
        int home_dis = 1;
        while (1)
        {
            if (home_location[i].y - home_dis >= 0 && map[home_location[i].y - home_dis][home_location[i].x] == 2
            || home_location[i].x - home_dis >= 0 && map[home_location[i].y][home_location[i].x - home_dis] == 2
            || map[home_location[i].y][home_location[i].x + home_dis] == 2
            || map[home_location[i].y + home_dis][home_location[i].x] == 2)
            {
                break ;
            }
            else if (home_location[i].y - home_dis >= 0 && home_location[i].x - home_dis >= 0 && map[home_location[i].y - home_dis][home_location[i].x - home_dis] == 2
            || map[home_location[i].y + home_dis][home_location[i].x + home_dis] == 2)
            {
                home_dis += 1;
                break ;
            }
            home_dis++;
        }
        distance += home_dis;
    }
    return (distance);
}

/*int    chicken_distance(t_vars *s_chicken, int s_ch_idx)
{
    int distance = 0;
    for (int i = 0; i < home_idx; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < s_ch_idx; j++)
        {
            int dis = dis_check(home_location[i], s_chicken[j]);
            if (min > dis)
                min = dis;
        }
        distance += min;
    }
    return (distance);
}*/

int ret = INT_MAX;
t_vars  s_chicken[13];
int s_ch_idx = 0;

int duplicate(int level, t_vars ch_lo)
{
    if (level == 0)
        return (0);
    for (int i = 0; i < level; i++)
    {
        if (s_chicken[i].x == ch_lo.x && s_chicken[i].y == ch_lo.y)
            return (1);
    }
    return (0);
}

void back_tracking(int level, int idx)
{
    if (level == m)
    {
        s_ch_idx = m;
        int dis = chicken_distance(s_chicken, s_ch_idx);
        if (ret > dis)
            ret = dis;
        return ;
    }
    for (int i = idx; i < ch_store; i++)
    {
        // if (duplicate(level, ch_location[i]))
        //     continue ;
        s_chicken[level].x = ch_location[i].x;
        s_chicken[level].y = ch_location[i].y;
        back_tracking(level + 1, idx + 1);
    }
}

int main()
{
    input_init();
    if (m == ch_store)
    {
        printf("%d\n", chicken_distance(ch_location, ch_idx));
        return (0);
    }
    back_tracking(0, 0);
    printf("%d\n", ret);
}