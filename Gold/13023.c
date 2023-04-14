#include <stdio.h>

int n, m, arr[2000][2000];

void    input_set(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][0] = 1;
        arr[a][b] = 1;
        arr[b][0] = 1;
        arr[b][a] = 1;
    }
}

int back_tracking(int point, int relation)
{
    if (relation >= 5)
        return (1);
    {
        
    }
    return (0);
}

int main()
{
    input_set();
    for (int i = 0; i < n; i++)
    {
        if (back_tracking(i, 1))
        {
            printf("1\n");
            return (0);
        }
    }
    printf("0\n");
}