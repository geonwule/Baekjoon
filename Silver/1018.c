#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, w = 0, b = 0;
    scanf("%d %d", &y, &x);
    char board[y + 1][x + 1];
    *board[y] = NULL;
    for (int i = 0; i < y; i++)
    {
        scanf("%s", board[i]);
        for (int j = 0; j < x; j++)
        {
            if (board[i][j] == 'B')
                b++;
            else if (board[i][j] == 'W')
                w++;
        }
        if (w >= 32 && b >= 32)
        {
            printf("B = %d, W = %d 0\n", b, w);
            return (0);
        }
    }
    if (w < 32)
    {
        printf("%d\n", 32 - w);
    }
    else if (b < 32)
    {
        printf("%d\n", 32 - b);
    }
}