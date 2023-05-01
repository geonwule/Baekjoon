#include <stdio.h>
#include <limits.h>
int n, e, eq1, eq2, arr[801][801], ret = INT_MAX;

//a == 1, b == distance
void    dfs(int dot, int dist, int eq1_check, int eq2_check)
{
    if (dot == n && eq1_check == 1 && eq2_check == 1
        && ret > dist)
    {
        ret = dist;
        return ;
    }
    for (int i = dot; i <= n; i++)
    {
        if (arr[dot][i] != 0)
        {
            if (i == eq1)
                eq1_check = 1;
            else if (i == eq2)
                eq2_check = 1;
            dist += arr[dot][i];
            dfs(i, dist, eq1_check, eq2_check);
        }
    }
}

void    input_init(void)
{
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
        arr[b][a] = c;
    }
    scanf("%d %d", &eq1, &eq2);
}

int main()
{
    input_init();
    dfs(1, 0, 0, 0);
    if (ret == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", ret);
}