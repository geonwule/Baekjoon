#include <stdio.h>
#include <stdlib.h>

void    box_init(int **box, int i, int j)
{
    for (int a = 0; a <= i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            box[a][b] = 0;
        }
    }
}

void    mal_free(int **s, int k, int n)
{
    for (int i = 0; i <= k; i++)
    {
        free(s[i]);
    }
    free(s);
}

int main()
{
    int t, k, n, ret;
    scanf("%d", &t);
    int box[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &k, &n);
        int **n_box;
        n_box = (int **)malloc(sizeof(int *) * (k+1));
        for (int i = 0; i <= k; i++)
            n_box[i] = (int *)malloc(sizeof(int) * n);  
        box_init(n_box, k, n);
        for (int j = 0; j <= k; j++)
        {
            for (int q = 0; q < n; q++)
            {
                if (j == 0)
                    n_box[j][q] = q + 1;
                else
                    for (int z = 0; z <= q; z++)
                    {
                        n_box[j][q] += n_box[j-1][z];
                    }
                ret = n_box[j][q];
            } 
        }
        box[i] = ret;
        mal_free(n_box, k, n);
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", box[i]);
}