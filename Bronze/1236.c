#include <stdio.h>
#include <stdlib.h>

void    mal_free(char **s)
{
    int i = 0;
    while (s[i] != NULL)
    {
        free(s[i]);
    }
    free(s);
}

int X_check(char **s, int x, int y)
{
    int ret = 0;
    for ()
    return (ret);
}

int ret_set(char **s)
{
    int ret = 0;
    int x_cnt = 0;
    int y_cnt = 0;

    int x, y;
    y = 0;
    x = 0;
    while (s[y] != NULL && s[y][x] != '\0')
    {
        if (X_check(s, x, y))
        {
            s[y][x] = 'X';
            ret++;
        }
        x++;
        y++;
    }
    x--;
    y--;
    if (s[y][x + 1] != '\0')
    return (ret);
}

int main()
{
    int x, y;
    char    **castle;
    int ret = 0;
    char    *c;

    scanf("%d %d", &y, &x); // 0 < x, y <= 50

    castle = (char **)malloc(sizeof(char *) * (y + 1));
    castle[y] = NULL;
    for (int i = 0; i < y; i++)
    {
        c = (char *)malloc(sizeof(char) * (x + 1));
        scanf("%s", c);
        castle[i] = c;
    }
    ret = ret_set(castle);
    //mal_free(castle);
    printf("%d\n", ret);
}