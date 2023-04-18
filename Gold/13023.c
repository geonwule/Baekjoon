#include <stdio.h>

int n, m, arr[2000][2000];

void input_set(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b)
            arr[b][a] = 1;
        else
            arr[a][b] = 1;
    }
}

void back_tracking(int idx, int *relation)
{
    if (*relation >= 5)
        return;
    int origin_relation = *relation;
    for (int j = 0; j < n; j++)
    {
        if (arr[idx][j] == 1)
        {
            *relation += 1;
            back_tracking(j, relation);
        }
        if (*relation >= 5)
            return;
        *relation = origin_relation;
    }
}

int main()
{
    input_set();
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        back_tracking(i, &temp);
        if (temp >= 5)
        {
            printf("1\n");
            return (0);
        }
    }
    printf("0\n");
}