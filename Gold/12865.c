#include <stdio.h>

int dp[100001]; // k의 최댓값 = 100000 (배낭 최대무게)

int dp_one(int n, int *w, int *v)
{
    int v_max = 0;

    for(int i = 0; i < n; i++)
    {
        if (w[i] == 1 && v[i] > v_max)
            v_max = v[i];
    }
    return (v_max);
}

int dp_two(int n, int *w, int *v)
{
    int v_max = dp[1];
    for(int i = 0; i < n; i++)
    {
        if(w[i] == 2 && v_max < v[i])
            v_max = v[i];
    }
	return (v_max);
}

int main()
{
    int n, k, w[100], v[100];
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
    dp[0] = 0;
    dp[1] = dp_one(n, w, v);
    dp[2] = 0;
    dp[3] = 6;
    dp[4] = 8;
    dp[5] = 12;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = ?;
    }
    printf("%d\n", dp[k]);
}