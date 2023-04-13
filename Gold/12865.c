#include <stdio.h>

typedef struct s_vars
{
    int weight;
    int value;
}   t_vars;

t_vars stuff[100];
int n, k;

void    stuff_input(void)
{
    for (int i = 0; i < n; i++)
        scanf("%d %d", &stuff[i].weight, &stuff[i].value);
}

void    dfs(int *ret, int weight, int value, int idx)
{
    if (weight > k)
        return ;
    if (weight <= k && *ret < value)
        *ret = value;
    for (int i = idx; i)
    
}

{
    for (int i = 0; i < n; i++)
    {
        dp[i] = stuff[i].weight;
        dp2[i] = stuff[i].value;
        if (dp[i] > k)
            continue ;
        if (*ret < dp[i])
            *ret = dp2[i];
        for (int j = i + 1; j < n; j++)
        {
            dp[i].
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    stuff_input();
    int ret = -1;
    dfs(&ret, 0, 0, 0);
    printf("%d\n", ret);
}