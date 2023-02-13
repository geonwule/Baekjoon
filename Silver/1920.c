#include <stdio.h>

int main()
{
    int n, m, a;
    scanf("%d", &n);
    int box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        box[i] = a;
    }
    scanf("%d", &m);
    int ret[m];
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &a);
        ret[j] = 0;
        for (int i = 0; i < n; i++)
        {
            if (box[i] == a)
            {
                ret[j] = 1;
                break ;
            }
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ret[i]);
}