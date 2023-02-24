#include <stdio.h>
#include <stdlib.h>

char **board_init(int x, int y)
{
    char **bod;
    bod = (char **)malloc(sizeof(char *) * (y + 1));
    bod[y] = NULL;
    for (int i = 0; i < y; i++)
    {
        bod[i] = (char *)malloc(sizeof(char) * (x + 1));
        scanf("%s", bod[i]);
    }
    return (bod);
}

void mal_free(char **bod, int y)
{
    for (int i = 0; i < y; i++)
        free(bod[i]);
    free(bod);
}

void print_bod(char **bod, int y)
{
    for (int i = 0; i < y; i++)
        printf("%s\n", bod[i]);
}

int cut_8x8(char **bod, int x, int x_m, int y, int y_m, int before)
{
    int min = 0, first_x = x % 2, first_y = y % 2;
    char first = bod[y][x]; // 'B' or 'W'

    for (int i = y; i < y_m; i++)
    {
        for (int j = x; j < x_m; j++)
        {
            if (i % 2 == first_y && j % 2 == first_x || i % 2 != first_y && j % 2 != first_x)
            {
                if (bod[i][j] != first)
                    min++;
            }
            else if (i % 2 == first_y && j % 2 != first_x || i % 2 != first_y && j % 2 == first_x)
            {
                if (bod[i][j] == first)
                    min++;
            }
            if (min >= before)
            {
                return (before);   
            } // 최솟값 초과
        }
    }
    return (min);
}

int cut_8x8_2(char **bod, int x, int x_m, int y, int y_m, int before)
{
    int min = 0, first_x = x % 2, first_y = y % 2;
    char first = bod[y][x]; // 'B' or 'W'

    for (int i = y; i < y_m; i++)
    {
        for (int j = x; j < x_m; j++)
        {
            if (i % 2 == first_y && j % 2 == first_x || i % 2 != first_y && j % 2 != first_x)
            {
                if (bod[i][j] == first)
                    min++;
            }
            else if (i % 2 == first_y && j % 2 != first_x || i % 2 != first_y && j % 2 == first_x)
            {
                if (bod[i][j] != first)
                    min++;
            }
            if (min >= before)
            {
                return (before);   
            } // 최솟값 초과
        }
    }
    return (min);
}

int board_cut(char **bod, int x, int y)
{
    int min = x * y; // min init (max)

    for (int i = 0; i < y; i++)
    {
        if (y - i < 8)
            break;
        for (int j = 0; j < x; j++)
        {
            if (x - j < 8)
                break;
            min = cut_8x8(bod, j, j + 8, i, i + 8, min);
            min = cut_8x8_2(bod, j, j + 8, i, i + 8, min);
        }
    }
    return (min);
}

int main()
{
    int y, x, min;
    char **board;
    scanf("%d %d", &y, &x);
    board = board_init(x, y);
    min = board_cut(board, x, y);
    printf("%d\n", min);
    mal_free(board, y);
}

// printf("\n");
// print_bod(board, y);