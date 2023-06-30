#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char ret[20][20];
    for (int i = 0; i < n; i++)
    {
        char tmp[20];
        scanf("%s", tmp);
        int tmp_l = strlen(tmp) - 1;
        int j;
        for (j = 0; j < m; j++)
            ret[i][j] = tmp[tmp_l--];
        ret[i][j] = '\0';
    }
    for (int i = 0; i < n; i++)
        printf("%s\n", ret[i]);
}