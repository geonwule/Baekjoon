#include <stdio.h>
#include <stdlib.h>

char **box_init(void)
{
    char **box = (char **)malloc(sizeof(char *) * 101);
    box[100] = NULL;
    for (int i = 0; i < 100; i++)
    {
        box[i] = (char *)malloc(sizeof(char) * 101);
    }
    return (box);
}

void    mal_free(char **s)
{
    for (int i = 0; i < 101; i++)
        free(s[i]);
    free(s);
}

void input_box(char **box, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", box[i]);
    }
}

void area_check(char **box, int n, char key, int y, int x)
{
    if (box[y][x] != key)
        return ;
    box[y][x] = ' ';
    int i = y, j = x;
    if (i - 1 >= 0)
        area_check(box, n, key, i - 1, j);
    i = y;
    if (i + 1 < n)
        area_check(box, n, key, i + 1, j);
    i = y;
    if (j - 1 >= 0)
        area_check(box, n, key, i, j - 1);
    j = x;
    if (j + 1 < n)
        area_check(box, n, key, i, j + 1);
}


int count_area(char **box, int n)
{
    int area = 0, i, j;

    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (box[i][j] == ' ')
            {
                j++;
                continue;
            }
            area_check(box, n, box[i][j], i, j);
            area++;
            j++;
        }
        i++;
    }
    return (area);
}

#include <string.h>

void box2_reset(char **box, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (box[i][j] == 'G')
                box[i][j] = 'R';
        }
    }
}

void box2_cpy(char **box2, char **box, int n)
{
    for (int i = 0; i < n; i++)
    {
        strncpy(box2[i], box[i], n);
    }
}

int main()
{
    int n;
    char **box = box_init();
    char **box2 = box_init();
    scanf("%d", &n);
    input_box(box, n);
    box2_cpy(box2, box, n);
    box2_reset(box2, n);
    // printf("%d\n", count_area(box2, n));
    printf("%d %d\n", count_area(box, n), count_area(box2, n));
    mal_free(box);
    mal_free(box2);
}