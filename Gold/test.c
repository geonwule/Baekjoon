#include <stdio.h>

void box2_reset(char **box, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (box[i][j] == 'G')
                box[i][j] == 'R';
        }
    }
}
#include <stdlib.h>
int main()
{
    char **box = (char **)malloc(sizeof(char*) * 2);
    box[1] = NULL;
    
}