#include <stdio.h>
#include <stdlib.h>

char **board_set(int x, int y)
{
    char **board;
    board = (char **)malloc(sizeof(char *) * (y + 1));
    board[y] = NULL;
    for (int i = 0; i < y; i++)
        board[i] = malloc(sizeof(char) * (x+1));
    for (int i = 0; i < y; i++)
        scanf("%s", board[i]);
    return (board);
}

void change_color(char *c)
{
    if (*c == 'B')
        *c = 'W';
    else if (*c == 'W')
        *c = 'B';
}

int ret_set(char **board, int x, int y)
{
    int ret = 0;
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            int k = j + 1;
            if (k < x + 8 && (board[i][j] == board[i][k]))
            {
                change_color(&board[i][k]);
                ret++;
            }
        }
    }
    return (ret);
}

#include <limits.h>

int black_white(char **board, int x, int y, int x_m, int y_m)
{
    int b = 0, w = 0, ret;
    if (x + 7 >= x_m)
        return (-1);
    if (y + 7 >= y_m)
        return (-2);
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (board[y][x] == 'B')
                b++;
            else // 'W'
                w++;
        }
    }
    ret = b - w;
    if (ret < 0)
        ret *= -1;
    return (ret);
}

void x_y_start(char **board, int x, int y, int *x_ret, int *y_ret)
{
    int temp, ret = INT_MAX, x_s, y_s, tf = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            temp = black_white(board, j, i, x, y);
            if (temp == -1)
                break;
            else if (temp == -2)
            {
                tf = -1;
                break;
            }
            if (temp < ret)
            {
                x_s = j;
                y_s = i;
            }
        }
        if (tf == -1)
            break;
    }
    *x_ret = x_s;
    *y_ret = y_s;
}

#include <stdlib.h>

void    mal_free(char **s, int n)
{
    for (int i = 0; i < n + 1; i++)
        free(s[i]);
    free (s);
}

int main()
{
    int x, y, ret, x_start, y_start;
    scanf("%d %d", &y, &x);
    char **board = board_set(x, y);
    x_y_start(board, x, y, &x_start, &y_start);
    ret = ret_set(board, x_start, y_start);
    printf("%d\n", ret);
    mal_free(board, y);
}